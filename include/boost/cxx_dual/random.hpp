//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_RANDOM_ERROR)
	#if (defined(CXXD_RANDOM_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_RANDOM_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_RANDOM_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for random
	#elif defined(CXXD_HAS_STD_RANDOM) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_RANDOM && (defined(CXXD_RANDOM_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_RANDOM_ERROR
            #error CXXD: Previous use of C++ standard random erroneously overridden
        #elif !CXXD_HAS_STD_RANDOM && (defined(CXXD_RANDOM_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_RANDOM_ERROR
            #error CXXD: Previous use of Boost random erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_RANDOM) || defined(CXXD_RANDOM_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_RANDOM_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_RANDOM_ERROR
                #error CXXD: C++ standard random is not available
            #else
                #if defined(CXXD_HAS_STD_RANDOM)
                    #undef CXXD_HAS_STD_RANDOM
                    #undef CXXD_RANDOM_NS
                    #undef CXXD_RANDOM_HEADER
                #endif
                #define CXXD_HAS_STD_RANDOM 0
                #define CXXD_RANDOM_NS boost::random
                #define CXXD_RANDOM_HEADER <boost/random.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_RANDOM)
                #undef CXXD_HAS_STD_RANDOM
                #undef CXXD_RANDOM_NS
                #undef CXXD_RANDOM_HEADER
            #endif
            #define CXXD_HAS_STD_RANDOM 1
            #define CXXD_RANDOM_NS std
            #define CXXD_RANDOM_HEADER <random>
        #endif
    #endif
#endif
