//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file move.hpp
    @brief Dual library for the move implementation.
    
    Chooses either the Boost move implementation or the C++ standard move implementation.
*/

/** @def CXXD_MOVE_NS
    @brief The move namespace.
    
    The object-like macro expands to the namespace for the move implementation.
*/

/** @def CXXD_MOVE_USE_BOOST
    @brief Override macro for Boost move implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost move implementation.
*/

/** @def CXXD_MOVE_USE_STD
    @brief Override macro for C++ standard move implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard move implementation. If the
    C++ standard move implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_MOVE
    @brief Determines whether the C++ standard move implementation or the Boost move implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard move implementation has been chosen
    0 if the Boost move implementation has been chosen.
*/

#if !defined(CXXD_MOVE_ERROR)
	#if (defined(CXXD_MOVE_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MOVE_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MOVE_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for move
	#elif defined(CXXD_HAS_STD_MOVE) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_MOVE && (defined(CXXD_MOVE_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_MOVE_ERROR
            #error CXXD: Previous use of C++ standard move erroneously overridden
        #elif !CXXD_HAS_STD_MOVE && (defined(CXXD_MOVE_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_MOVE_ERROR
            #error CXXD: Previous use of Boost move erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_MOVE) || defined(CXXD_MOVE_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_MOVE_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_RVALUE_REFERENCES)) || defined(CXXD_MOVE_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_MOVE_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_MOVE_ERROR
                #error CXXD: C++ standard move is not available
            #else
                #if defined(CXXD_HAS_STD_MOVE)
                    #undef CXXD_HAS_STD_MOVE
                #endif
                #define CXXD_HAS_STD_MOVE 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_MOVE)
                #undef CXXD_HAS_STD_MOVE
            #endif
            #define CXXD_HAS_STD_MOVE 1
        #endif
    #endif
#endif

/*

  CXXD_DOXYGEN is only defined when building the docs for doxygen
  so that doxygen will document macros which are not defined
  in the library.
  
  It should never be defined by an end-user of CXXD.

*/

#if defined(CXXD_DOXYGEN)
    #define CXXD_MOVE_USE_STD
    #define CXXD_MOVE_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
