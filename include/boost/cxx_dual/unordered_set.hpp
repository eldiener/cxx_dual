//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_UNORDERED_SET_ERROR)
	#if (defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_SET_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered set
	#elif defined(CXXD_HAS_STD_UNORDERED_SET) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_UNORDERED_SET && (defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_SET_ERROR
            #error CXXD: Previous use of C++ standard unordered set erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_SET && (defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_SET_ERROR
            #error CXXD: Previous use of Boost unordered set erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_UNORDERED_SET) || defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_SET_ERROR
                #error CXXD: C++ standard unordered set is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_SET)
                    #undef CXXD_HAS_STD_UNORDERED_SET
                    #undef CXXD_UNORDERED_SET_NS
                    #undef CXXD_UNORDERED_SET_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_SET 0
                #define CXXD_UNORDERED_SET_NS boost
                #define CXXD_UNORDERED_SET_HEADER <boost/unordered_set.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_SET)
                #undef CXXD_HAS_STD_UNORDERED_SET
                #undef CXXD_UNORDERED_SET_NS
                #undef CXXD_UNORDERED_SET_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_SET 1
            #define CXXD_UNORDERED_SET_NS std
            #define CXXD_UNORDERED_SET_HEADER <unordered_set>
        #endif
    #endif
#endif
