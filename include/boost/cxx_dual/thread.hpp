//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_THREAD_ERROR)
	#if (defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_THREAD_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for thread
	#else
        #if defined(CXXD_HAS_STD_THREAD)
            #if CXXD_HAS_STD_THREAD && (defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST))
                #define CXXD_THREAD_ERROR
                #error CXXD: Previous use of C++ standard thread erroneously overridden
            #elif !CXXD_HAS_STD_THREAD && (defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD))
                #define CXXD_THREAD_ERROR
                #error CXXD: Previous use of Boost thread erroneously overridden
            #endif
        #else
            #include <boost/config.hpp>
            #if defined(BOOST_NO_CXX11_HDR_THREAD) || defined(CXXD_THREAD_USE_BOOST) || defined(CXXD_USE_BOOST)
                #if defined(CXXD_THREAD_USE_STD) || defined(CXXD_USE_STD)
                    #define CXXD_THREAD_ERROR
                    #error CXXD: C++ standard thread is not available
                #else
                    #define CXXD_HAS_STD_THREAD 0
                    #define CXXD_THREAD_NS boost
                    #define CXXD_THREAD_HEADER <boost/thread/thread.hpp>
                #endif
            #else
                #define CXXD_HAS_STD_THREAD 1
                #define CXXD_THREAD_NS std
                #define CXXD_THREAD_HEADER <thread>
            #endif
        #endif
	#endif
#endif
