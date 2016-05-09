//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file shared_mutex.hpp
    @brief Dual library for the shared_mutex implementation.
    
    Chooses either the Boost shared_mutex implementation or the C++ standard shared_mutex implementation.
*/

/** @def CXXD_SHARED_MUTEX_HEADER
    @brief The shared_mutex header file name.
    
    The object-like macro expands to the include header file designation for the shared_mutex header file.
    The macro is used with the syntax: \#include CXXD_SHARED_MUTEX_HEADER
*/

/** @def CXXD_SHARED_MUTEX_NS
    @brief The shared_mutex namespace.
    
    The object-like macro expands to the namespace for the shared_mutex implementation.
*/

/** @def CXXD_SHARED_MUTEX_USE_BOOST
    @brief Override macro for Boost shared_mutex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost shared_mutex implementation.
*/

/** @def CXXD_SHARED_MUTEX_USE_STD
    @brief Override macro for C++ standard shared_mutex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard shared_mutex implementation. If the
    C++ standard shared_mutex implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_SHARED_MUTEX
    @brief Determines whether the C++ standard shared_mutex implementation or the Boost shared_mutex implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard shared_mutex implementation has been chosen
    0 if the Boost shared_mutex implementation has been chosen.
*/

#if !defined(CXXD_SHARED_MUTEX_ERROR)
	#if (defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_SHARED_MUTEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for shared_mutex
	#elif defined(CXXD_HAS_STD_SHARED_MUTEX) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_SHARED_MUTEX && (defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_SHARED_MUTEX_ERROR
            #error CXXD: Previous use of C++ standard shared_mutex erroneously overridden
        #elif !CXXD_HAS_STD_SHARED_MUTEX && (defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_SHARED_MUTEX_ERROR
            #error CXXD: Previous use of Boost shared_mutex erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_SHARED_MUTEX) || defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX)) || defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_SHARED_MUTEX_ERROR
                #error CXXD: C++ standard shared_mutex is not available
            #else
                #if defined(CXXD_HAS_STD_SHARED_MUTEX)
                    #undef CXXD_HAS_STD_SHARED_MUTEX
                    #undef CXXD_SHARED_MUTEX_NS
                    #undef CXXD_SHARED_MUTEX_HEADER
                #endif
                #define CXXD_HAS_STD_SHARED_MUTEX 0
                #define CXXD_SHARED_MUTEX_NS boost
                #define CXXD_SHARED_MUTEX_HEADER <boost/thread/shared_mutex.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_SHARED_MUTEX)
                #undef CXXD_HAS_STD_SHARED_MUTEX
                #undef CXXD_SHARED_MUTEX_NS
                #undef CXXD_SHARED_MUTEX_HEADER
            #endif
            #define CXXD_HAS_STD_SHARED_MUTEX 1
            #define CXXD_SHARED_MUTEX_NS std
            #define CXXD_SHARED_MUTEX_HEADER <shared_mutex>
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
    #define CXXD_SHARED_MUTEX_USE_STD
    #define CXXD_SHARED_MUTEX_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
