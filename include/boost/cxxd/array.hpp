//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_ARRAY_ERROR)
	#if (defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_ARRAY_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for array
    #elif defined(CXXD_HAS_STD_ARRAY) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_ARRAY && (defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_ARRAY_ERROR
            #error CXXD: Previous use of C++ standard array erroneously overridden
        #elif !CXXD_HAS_STD_ARRAY && (defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_ARRAY_ERROR
            #error CXXD: Previous use of Boost array erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_ARRAY) || defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_ARRAY) || defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_ARRAY_ERROR
                #error CXXD: C++ standard array is not available
            #else
                #if defined(CXXD_HAS_STD_ARRAY)
                    #undef CXXD_HAS_STD_ARRAY
                    #undef CXXD_ARRAY_NS
                    #undef CXXD_ARRAY_HEADER
                #endif
                #define CXXD_HAS_STD_ARRAY 0
                #define CXXD_ARRAY_NS boost
                #define CXXD_ARRAY_HEADER <boost/array.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_ARRAY)
                #undef CXXD_HAS_STD_ARRAY
                #undef CXXD_ARRAY_NS
                #undef CXXD_ARRAY_HEADER
            #endif
            #define CXXD_HAS_STD_ARRAY 1
            #define CXXD_ARRAY_NS std
            #define CXXD_ARRAY_HEADER <array>
        #endif
    #endif
#endif
