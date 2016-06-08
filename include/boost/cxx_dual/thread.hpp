//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file thread.hpp
    @brief Dual library for the thread implementation.
    
    Chooses either the Boost thread implementation or the C++ standard thread implementation.
*/

/** @def CXXD_THREAD_HEADER
    @brief The thread header file name.
    
    The object-like macro expands to the include header file designation for the thread header file.
    The macro is used with the syntax: \#include CXXD_THREAD_HEADER
*/

/** @def CXXD_THREAD_NS
    @brief The thread namespace.
    
    The object-like macro expands to the namespace for the thread implementation.
*/

/** @def CXXD_THREAD_USE_BOOST
    @brief Override macro for Boost thread implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost thread implementation.
*/

/** @def CXXD_THREAD_USE_STD
    @brief Override macro for C++ standard thread implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard thread implementation. If the
    C++ standard thread implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_THREAD
    @brief Determines whether the C++ standard thread implementation or the Boost thread implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard thread implementation has been chosen
    0 if the Boost thread implementation has been chosen.
*/

#if !defined(CXXD_THREAD_ERROR)
	#if (defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_THREAD_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for thread
	#elif defined(CXXD_HAS_STD_THREAD) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_THREAD && (defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_THREAD_ERROR
            #error CXXD: Previous use of C++ standard thread erroneously overridden
        #elif !CXXD_HAS_STD_THREAD && (defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_THREAD_ERROR
            #error CXXD: Previous use of Boost thread erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_THREAD) || defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_THREAD)) || defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_THREAD_ERROR
                #error CXXD: C++ standard thread is not available
            #else
                #if defined(CXXD_HAS_STD_THREAD)
                    #undef CXXD_HAS_STD_THREAD
                    #undef CXXD_THREAD_HEADER
                #endif
                #define CXXD_HAS_STD_THREAD 0
                #define CXXD_THREAD_HEADER <boost/cxx_dual/detail/thread.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_THREAD)
                #undef CXXD_HAS_STD_THREAD
                #undef CXXD_THREAD_HEADER
            #endif
            #define CXXD_HAS_STD_THREAD 1
            #define CXXD_THREAD_HEADER <boost/cxx_dual/detail/thread.hpp>
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
    #define CXXD_THREAD_USE_STD
    #define CXXD_THREAD_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
