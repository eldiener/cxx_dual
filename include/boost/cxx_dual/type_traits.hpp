//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file type_traits.hpp
    @brief Dual library for the type traits implementation.
    
    Chooses either the Boost type traits implementation or the C++ standard type traits implementation.
*/

/** @def CXXD_TYPE_TRAITS_HEADER
    @brief The type traits header file name.
    
    The object-like macro expands to the include header file designation for the type traits header file.
    The macro is used with the syntax: #include CXXD_TYPE_TRAITS_HEADER
*/

/** @def CXXD_TYPE_TRAITS_NS
    @brief The type traits namespace.
    
    The object-like macro expands to the namespace for the type traits implementation.
*/

/** @def CXXD_HAS_STD_TYPE_TRAITS
    @brief Determines whether the C++ standard type traits implementation or the Boost type traits implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard type traits implementation has been chosen
    0 if the Boost type traits implementation has been chosen.
*/

#if !defined(CXXD_TYPE_TRAITS_ERROR)
	#if (defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TYPE_TRAITS_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for type traits
	#elif defined(CXXD_HAS_STD_TYPE_TRAITS) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_TYPE_TRAITS && (defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TYPE_TRAITS_ERROR
            #error CXXD: Previous use of C++ standard type traits erroneously overridden
        #elif !CXXD_HAS_STD_TYPE_TRAITS && (defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TYPE_TRAITS_ERROR
            #error CXXD: Previous use of Boost type traits erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_TYPE_TRAITS) || defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)) || defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST)
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
