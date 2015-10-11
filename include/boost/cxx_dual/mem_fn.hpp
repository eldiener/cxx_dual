//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_MEM_FN_ERROR)
	#if (defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MEM_FN_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for mem_fn
	#else
        #if defined(CXXD_HAS_STD_MEM_FN)
            #if CXXD_HAS_STD_MEM_FN && (defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST))
                #define CXXD_MEM_FN_ERROR
                #error CXXD: Previous use of C++ standard mem_fn erroneously overridden
            #elif !CXXD_HAS_STD_MEM_FN && (defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD))
                #define CXXD_MEM_FN_ERROR
                #error CXXD: Previous use of Boost mem_fn erroneously overridden
            #endif
        #else
            #include <boost/config.hpp>
            #if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST)
                #if defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD)
                    #define CXXD_MEM_FN_ERROR
                    #error CXXD: C++ standard mem_fn is not available
                #else
                    #define CXXD_HAS_STD_MEM_FN 0
                    #define CXXD_MEM_FN_NS boost
                    #define CXXD_MEM_FN_HEADER <boost/mem_fn.hpp>
                #endif
            #else
                #define CXXD_HAS_STD_MEM_FN 1
                #define CXXD_MEM_FN_NS std
                #define CXXD_MEM_FN_HEADER <functional>
            #endif
        #endif
	#endif
#endif
