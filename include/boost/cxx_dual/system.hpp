//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_SYSTEM_ERROR)
	#if (defined(CXXD_SYSTEM_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_SYSTEM_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_SYSTEM_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for system error
	#elif defined(CXXD_HAS_STD_SYSTEM) && !defined(CXXD_ALLOW_CHANGE)
        #if CXXD_HAS_STD_SYSTEM && (defined(CXXD_SYSTEM_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_SYSTEM_ERROR
            #error CXXD: Previous use of C++ standard system error erroneously overridden
        #elif !CXXD_HAS_STD_SYSTEM && (defined(CXXD_SYSTEM_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_SYSTEM_ERROR
            #error CXXD: Previous use of Boost system error erroneously overridden
        #endif
    #else
        #include <boost/config.hpp>
        #if defined(BOOST_NO_CXX11_HDR_SYSTEM_ERROR) || defined(CXXD_SYSTEM_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_SYSTEM_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_SYSTEM_ERROR
                #error CXXD: C++ standard system error is not available
            #else
                #if defined(CXXD_HAS_STD_SYSTEM)
                    #undef CXXD_HAS_STD_SYSTEM
                    #undef CXXD_SYSTEM_NS
                    #undef CXXD_SYSTEM_HEADER
                #endif
                #define CXXD_HAS_STD_SYSTEM 0
                #define CXXD_SYSTEM_NS boost
                #define CXXD_SYSTEM_HEADER <boost/system/system_error.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_SYSTEM)
                #undef CXXD_HAS_STD_SYSTEM
                #undef CXXD_SYSTEM_NS
                #undef CXXD_SYSTEM_HEADER
            #endif
            #define CXXD_HAS_STD_SYSTEM 1
            #define CXXD_SYSTEM_NS std
            #define CXXD_SYSTEM_HEADER <system_error>
        #endif
    #endif
#endif
