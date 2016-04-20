//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file bind.hpp
    @brief Dual library for the bind implementation.
    
    Chooses either the Boost bind implementation or the C++ standard bind implementation.
*/

/** @def CXXD_BIND_HEADER
    @brief The bind header file name.
    
    The object-like macro expands to the include header file designation for the bind header file.
    The macro is used with the syntax: \#include CXXD_BIND_HEADER
*/

/** @def CXXD_BIND_NS
    @brief The bind namespace.
    
    The object-like macro expands to the namespace for the bind implementation.
*/

/** @def CXXD_HAS_STD_BIND
    @brief Determines whether the C++ standard bind implementation or the Boost bind implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard bind implementation has been chosen
    0 if the Boost bind implementation has been chosen.
*/

#if !defined(CXXD_BIND_ERROR)
	#if (defined(CXXD_BIND_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_BIND_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_BIND_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for bind
	#elif defined(CXXD_HAS_STD_BIND) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_BIND && (defined(CXXD_BIND_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_BIND_ERROR
            #error CXXD: Previous use of C++ standard bind erroneously overridden
        #elif !CXXD_HAS_STD_BIND && (defined(CXXD_BIND_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_BIND_ERROR
            #error CXXD: Previous use of Boost bind erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_BIND) || defined(CXXD_BIND_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_BIND_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)) || defined(CXXD_BIND_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_BIND_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_BIND_ERROR
                #error CXXD: C++ standard bind is not available
            #else
                #if defined(CXXD_HAS_STD_BIND)
                    #undef CXXD_HAS_STD_BIND
                    #undef CXXD_BIND_NS
                    #undef CXXD_BIND_HEADER
                #endif
                #define CXXD_HAS_STD_BIND 0
                #define CXXD_BIND_NS boost
                #define CXXD_BIND_HEADER <boost/bind/bind.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_BIND)
                #undef CXXD_HAS_STD_BIND
                #undef CXXD_BIND_NS
                #undef CXXD_BIND_HEADER
            #endif
            #define CXXD_HAS_STD_BIND 1
            #define CXXD_BIND_NS std
            #define CXXD_BIND_HEADER <functional>
        #endif
    #endif
#endif
