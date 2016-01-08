//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_RATIO_ERROR)
	#if (defined(CXXD_RATIO_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_RATIO_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_RATIO_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for ratio
	#elif defined(CXXD_HAS_STD_RATIO) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_RATIO && (defined(CXXD_RATIO_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_RATIO_ERROR
            #error CXXD: Previous use of C++ standard ratio erroneously overridden
        #elif !CXXD_HAS_STD_RATIO && (defined(CXXD_RATIO_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_RATIO_ERROR
            #error CXXD: Previous use of Boost ratio erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_RATIO) || defined(CXXD_RATIO_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_RATIO_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_RATIO) || defined(CXXD_RATIO_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_RATIO_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_RATIO_ERROR
                #error CXXD: C++ standard ratio is not available
            #else
                #if defined(CXXD_HAS_STD_RATIO)
                    #undef CXXD_HAS_STD_RATIO
                    #undef CXXD_RATIO_NS
                    #undef CXXD_RATIO_HEADER
                #endif
                #define CXXD_HAS_STD_RATIO 0
                #define CXXD_RATIO_NS boost
                #define CXXD_RATIO_HEADER <boost/ratio.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_RATIO)
                #undef CXXD_HAS_STD_RATIO
                #undef CXXD_RATIO_NS
                #undef CXXD_RATIO_HEADER
            #endif
            #define CXXD_HAS_STD_RATIO 1
            #define CXXD_RATIO_NS std
            #define CXXD_RATIO_HEADER <ratio>
        #endif
    #endif
#endif
