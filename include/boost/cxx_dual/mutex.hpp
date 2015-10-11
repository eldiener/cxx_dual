//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_MUTEX_ERROR)
	#if (defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MUTEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for mutex
	#else
        #if defined(CXXD_HAS_STD_MUTEX)
            #if CXXD_HAS_STD_MUTEX && (defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST))
                #define CXXD_MUTEX_ERROR
                #error CXXD: Previous use of C++ standard mutex erroneously overridden
            #elif !CXXD_HAS_STD_MUTEX && (defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD))
                #define CXXD_MUTEX_ERROR
                #error CXXD: Previous use of Boost mutex erroneously overridden
            #endif
        #else
            #include <boost/config.hpp>
            #if defined(BOOST_NO_CXX11_HDR_MUTEX) || defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
                #if defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD)
                    #define CXXD_MUTEX_ERROR
                    #error CXXD: C++ standard mutex is not available
                #else
                    #define CXXD_HAS_STD_MUTEX 0
                    #define CXXD_MUTEX_NS boost
                    #define CXXD_MUTEX_HEADER <boost/thread/mutex.hpp>
                #endif
            #else
                #define CXXD_HAS_STD_MUTEX 1
                #define CXXD_MUTEX_NS std
                #define CXXD_MUTEX_HEADER <mutex>
            #endif
        #endif
	#endif
#endif
