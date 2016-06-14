//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file tuple.hpp
    @brief Dual library for the tuple implementation.
    
    Chooses either the Boost tuple implementation or the C++ standard tuple implementation.
*/

/** @def CXXD_TUPLE_NS
    @brief The tuple namespace.
    
    The object-like macro expands to the namespace for the tuple implementation.
*/

/** @def CXXD_TUPLE_USE_BOOST
    @brief Override macro for Boost tuple implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost tuple implementation.
*/

/** @def CXXD_TUPLE_USE_STD
    @brief Override macro for C++ standard tuple implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard tuple implementation. If the
    C++ standard tuple implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_TUPLE
    @brief Determines whether the C++ standard tuple implementation or the Boost tuple implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard tuple implementation has been chosen
    0 if the Boost tuple implementation has been chosen.
*/

#if !defined(CXXD_TUPLE_ERROR)
	#if (defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TUPLE_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for tuple
	#elif defined(CXXD_HAS_STD_TUPLE) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_TUPLE && (defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TUPLE_ERROR
            #error CXXD: Previous use of C++ standard tuple erroneously overridden
        #elif !CXXD_HAS_STD_TUPLE && (defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TUPLE_ERROR
            #error CXXD: Previous use of Boost tuple erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_TUPLE) || defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_TUPLE)) || defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_TUPLE_ERROR
                #error CXXD: C++ standard tuple is not available
            #else
                #if defined(CXXD_HAS_STD_TUPLE)
                    #undef CXXD_HAS_STD_TUPLE
                #endif
                #define CXXD_HAS_STD_TUPLE 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_TUPLE)
                #undef CXXD_HAS_STD_TUPLE
            #endif
            #define CXXD_HAS_STD_TUPLE 1
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
    #define CXXD_TUPLE_USE_STD
    #define CXXD_TUPLE_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
