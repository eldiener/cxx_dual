//  (C) Copyright Edward Diener 2015-2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file array.hpp
    @brief Dual library for the array implementation.
    
    Chooses either the Boost array implementation or the C++ standard array implementation.
*/

/** @def CXXD_ARRAY_NS
    @brief The array namespace.
    
    The object-like macro expands to the namespace for the array implementation.
*/

/** @def CXXD_ARRAY_USE_BOOST
    @brief Override macro for Boost array implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost array implementation.
*/

/** @def CXXD_ARRAY_USE_STD
    @brief Override macro for C++ standard array implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard array implementation. If the
    C++ standard array implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_ARRAY
    @brief Determines whether the C++ standard array implementation or the Boost array implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard array implementation has been chosen
    0 if the Boost array implementation has been chosen.
*/

#if !defined(CXXD_ARRAY_ERROR)
	#if (defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_ARRAY_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for array
    #elif defined(CXXD_HAS_STD_ARRAY) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_ARRAY && (defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_ARRAY_ERROR
            #error CXXD: Previous use of C++ standard array erroneously overridden
        #elif !CXXD_HAS_STD_ARRAY && (defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_ARRAY_ERROR
            #error CXXD: Previous use of Boost array erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_ARRAY) || defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_ARRAY)) || defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_ARRAY_ERROR
                #error CXXD: C++ standard array is not available
            #else
                #if defined(CXXD_HAS_STD_ARRAY)
                    #undef CXXD_HAS_STD_ARRAY
                #endif
                #define CXXD_HAS_STD_ARRAY 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_ARRAY)
                #undef CXXD_HAS_STD_ARRAY
            #endif
            #define CXXD_HAS_STD_ARRAY 1
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
    #define CXXD_ARRAY_USE_STD
    #define CXXD_ARRAY_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
