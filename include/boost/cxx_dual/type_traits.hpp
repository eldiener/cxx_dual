//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_TYPE_TRAITS_ERROR)
	#if (defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TYPE_TRAITS_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for type traits
	#elif defined(CXXD_HAS_STD_TYPE_TRAITS) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_TYPE_TRAITS && (defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TYPE_TRAITS_ERROR
            #error CXXD: Previous use of C++ standard type traits erroneously overridden
        #elif !CXXD_HAS_STD_TYPE_TRAITS && (defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TYPE_TRAITS_ERROR
            #error CXXD: Previous use of Boost type traits erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_TYPE_TRAITS_ERROR
                #error CXXD: C++ standard type traits is not available
            #else
                #if defined(CXXD_HAS_STD_TYPE_TRAITS)
                    #undef CXXD_HAS_STD_TYPE_TRAITS
                    #undef CXXD_TYPE_TRAITS_NS
                    #undef CXXD_TYPE_TRAITS_HEADER
                #endif
                #define CXXD_HAS_STD_TYPE_TRAITS 0
                #define CXXD_TYPE_TRAITS_NS boost
                #define CXXD_TYPE_TRAITS_HEADER <boost/type_traits.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_TYPE_TRAITS)
                #undef CXXD_HAS_STD_TYPE_TRAITS
                #undef CXXD_TYPE_TRAITS_NS
                #undef CXXD_TYPE_TRAITS_HEADER
            #endif
            #define CXXD_HAS_STD_TYPE_TRAITS 1
            #define CXXD_TYPE_TRAITS_NS std
            #define CXXD_TYPE_TRAITS_HEADER <type_traits>
        #endif
    #endif
#endif
