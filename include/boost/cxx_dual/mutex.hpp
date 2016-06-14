//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file mutex.hpp
    @brief Dual library for the mutex implementation.
    
    Chooses either the Boost mutex implementation or the C++ standard mutex implementation.
*/

/** @def CXXD_MUTEX_NS
    @brief The mutex namespace.
    
    The object-like macro expands to the namespace for the mutex implementation.
*/

/** @def CXXD_MUTEX_USE_BOOST
    @brief Override macro for Boost mutex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost mutex implementation.
*/

/** @def CXXD_MUTEX_USE_STD
    @brief Override macro for C++ standard mutex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard mutex implementation. If the
    C++ standard mutex implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_MUTEX
    @brief Determines whether the C++ standard mutex implementation or the Boost mutex implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard mutex implementation has been chosen
    0 if the Boost mutex implementation has been chosen.
*/

#if !defined(CXXD_MUTEX_ERROR)
	#if (defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MUTEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for mutex
	#elif defined(CXXD_HAS_STD_MUTEX) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_MUTEX && (defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_MUTEX_ERROR
            #error CXXD: Previous use of C++ standard mutex erroneously overridden
        #elif !CXXD_HAS_STD_MUTEX && (defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_MUTEX_ERROR
            #error CXXD: Previous use of Boost mutex erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_MUTEX) || defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_MUTEX)) || defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_MUTEX_ERROR
                #error CXXD: C++ standard mutex is not available
            #else
                #if defined(CXXD_HAS_STD_MUTEX)
                    #undef CXXD_HAS_STD_MUTEX
                #endif
                #define CXXD_HAS_STD_MUTEX 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_MUTEX)
                #undef CXXD_HAS_STD_MUTEX
            #endif
            #define CXXD_HAS_STD_MUTEX 1
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
    #define CXXD_MUTEX_USE_STD
    #define CXXD_MUTEX_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
