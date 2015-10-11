//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_TUPLE_ERROR)
	#if (defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TUPLE_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for tuple
	#elif defined(CXXD_HAS_STD_TUPLE) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_TUPLE && (defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TUPLE_ERROR
            #error CXXD: Previous use of C++ standard tuple erroneously overridden
        #elif !CXXD_HAS_STD_TUPLE && (defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TUPLE_ERROR
            #error CXXD: Previous use of Boost tuple erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_TUPLE) || defined(CXXD_TUPLE_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_TUPLE_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_TUPLE_ERROR
                #error CXXD: C++ standard tuple is not available
            #else
                #if defined(CXXD_HAS_STD_TUPLE)
                    #undef CXXD_HAS_STD_TUPLE
                    #undef CXXD_TUPLE_NS
                    #undef CXXD_TUPLE_HEADER
                #endif
                #define CXXD_HAS_STD_TUPLE 0
                #define CXXD_TUPLE_NS boost
                #define CXXD_TUPLE_HEADER <boost/tuple/tuple.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_TUPLE)
                #undef CXXD_HAS_STD_TUPLE
                #undef CXXD_TUPLE_NS
                #undef CXXD_TUPLE_HEADER
            #endif
            #define CXXD_HAS_STD_TUPLE 1
            #define CXXD_TUPLE_NS std
            #define CXXD_TUPLE_HEADER <tuple>
        #endif
    #endif
#endif
