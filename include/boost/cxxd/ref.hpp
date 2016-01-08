//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_REF_ERROR)
	#if (defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_REF_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for ref
	#elif defined(CXXD_HAS_STD_REF) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_REF && (defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_REF_ERROR
            #error CXXD: Previous use of C++ standard ref erroneously overridden
        #elif !CXXD_HAS_STD_REF && (defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_REF_ERROR
            #error CXXD: Previous use of Boost ref erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_REF) || defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_REF_ERROR
                #error CXXD: C++ standard ref is not available
            #else
                #if defined(CXXD_HAS_STD_REF)
                    #undef CXXD_HAS_STD_REF
                    #undef CXXD_REF_NS
                    #undef CXXD_REF_HEADER
                #endif
                #define CXXD_HAS_STD_REF 0
                #define CXXD_REF_NS boost
                #define CXXD_REF_HEADER <boost/core/ref.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_REF)
                #undef CXXD_HAS_STD_REF
                #undef CXXD_REF_NS
                #undef CXXD_REF_HEADER
            #endif
            #define CXXD_HAS_STD_REF 1
            #define CXXD_REF_NS std
            #define CXXD_REF_HEADER <functional>
        #endif
    #endif
#endif
