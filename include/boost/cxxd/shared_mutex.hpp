//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_SHARED_MUTEX_ERROR)
	#if (defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_SHARED_MUTEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for shared mutex
	#elif defined(CXXD_HAS_STD_SHARED_MUTEX) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_SHARED_MUTEX && (defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_SHARED_MUTEX_ERROR
            #error CXXD: Previous use of C++ standard shared mutex erroneously overridden
        #elif !CXXD_HAS_STD_SHARED_MUTEX && (defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_SHARED_MUTEX_ERROR
            #error CXXD: Previous use of Boost shared mutex erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_SHARED_MUTEX) || defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX) || defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_SHARED_MUTEX_ERROR
                #error CXXD: C++ standard shared mutex is not available
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
