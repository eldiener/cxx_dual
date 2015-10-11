//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_HASH_ERROR)
	#if (defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_HASH_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for hash
	#else
        #if defined(CXXD_HAS_STD_HASH)
            #if CXXD_HAS_STD_HASH && (defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST))
                #define CXXD_HASH_ERROR
                #error CXXD: Previous use of C++ standard hash erroneously overridden
            #elif !CXXD_HAS_STD_HASH && (defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD))
                #define CXXD_HASH_ERROR
                #error CXXD: Previous use of Boost hash erroneously overridden
            #endif
        #else
            #include <boost/config.hpp>
            #if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST)
                #if defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD)
                    #define CXXD_HASH_ERROR
                    #error CXXD: C++ standard hash is not available
                #else
                    #define CXXD_HAS_STD_HASH 0
                    #define CXXD_HASH_NS boost
                    #define CXXD_HASH_HEADER <boost/functional/hash.hpp>
                #endif
            #else
                #define CXXD_HAS_STD_HASH 1
                #define CXXD_HASH_NS std
                #define CXXD_HASH_HEADER <functional>
            #endif
        #endif
	#endif
#endif
