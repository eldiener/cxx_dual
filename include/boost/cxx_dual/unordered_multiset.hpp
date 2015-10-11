//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_UNORDERED_MULTISET_ERROR)
	#if (defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_MULTISET_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered multiset
	#elif defined(CXXD_HAS_STD_UNORDERED_MULTISET) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_UNORDERED_MULTISET && (defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_MULTISET_ERROR
            #error CXXD: Previous use of C++ standard unordered multiset erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_MULTISET && (defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_MULTISET_ERROR
            #error CXXD: Previous use of Boost unordered multiset erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_UNORDERED_SET) || defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_MULTISET_ERROR
                #error CXXD: C++ standard unordered multiset is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_MULTISET)
                    #undef CXXD_HAS_STD_UNORDERED_MULTISET
                    #undef CXXD_UNORDERED_MULTISET_NS
                    #undef CXXD_UNORDERED_MULTISET_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_MULTISET 0
                #define CXXD_UNORDERED_MULTISET_NS boost
                #define CXXD_UNORDERED_MULTISET_HEADER <boost/unordered_set.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_MULTISET)
                #undef CXXD_HAS_STD_UNORDERED_MULTISET
                #undef CXXD_UNORDERED_MULTISET_NS
                #undef CXXD_UNORDERED_MULTISET_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_MULTISET 1
            #define CXXD_UNORDERED_MULTISET_NS std
            #define CXXD_UNORDERED_MULTISET_HEADER <unordered_set>
        #endif
    #endif
#endif
