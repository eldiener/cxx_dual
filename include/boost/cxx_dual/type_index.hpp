//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_TYPE_INDEX_ERROR)
	#if (defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TYPE_INDEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for type index
	#elif defined(CXXD_HAS_STD_TYPE_INDEX) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_TYPE_INDEX && (defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TYPE_INDEX_ERROR
            #error CXXD: Previous use of C++ standard type index erroneously overridden
        #elif !CXXD_HAS_STD_TYPE_INDEX && (defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TYPE_INDEX_ERROR
            #error CXXD: Previous use of Boost type index erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_TYPE_INDEX) || defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_TYPEINDEX) || defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_TYPE_INDEX_ERROR
                #error CXXD: C++ standard type index is not available
            #else
                #if defined(CXXD_HAS_STD_TYPE_INDEX)
                    #undef CXXD_HAS_STD_TYPE_INDEX
                    #undef CXXD_TYPE_INDEX_NS
                    #undef CXXD_TYPE_INDEX_HEADER
                #endif
                #define CXXD_HAS_STD_TYPE_INDEX 0
                #define CXXD_TYPE_INDEX_NS boost::typeindex
                #define CXXD_TYPE_INDEX_HEADER <boost/type_index.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_TYPE_INDEX)
                #undef CXXD_HAS_STD_TYPE_INDEX
                #undef CXXD_TYPE_INDEX_NS
                #undef CXXD_TYPE_INDEX_HEADER
            #endif
            #define CXXD_HAS_STD_TYPE_INDEX 1
            #define CXXD_TYPE_INDEX_NS std
            #define CXXD_TYPE_INDEX_HEADER <typeindex>
        #endif
    #endif
#endif
