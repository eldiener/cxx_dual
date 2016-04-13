//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file unordered_map.hpp
    @brief Dual library for the unordered map implementation.
    
    Chooses either the Boost unordered map implementation or the C++ standard unordered map implementation.
*/

/** @def CXXD_UNORDERED_MAP_HEADER
    @brief The unordered map header file name.
    
    The object-like macro expands to the include header file designation for the unordered map header file.
    The macro is used with the syntax: #include CXXD_UNORDERED_MAP_HEADER
*/

/** @def CXXD_UNORDERED_MAP_NS
    @brief The unordered map namespace.
    
    The object-like macro expands to the namespace for the unordered map implementation.
*/

/** @def CXXD_HAS_STD_UNORDERED_MAP
    @brief Determines whether the C++ standard unordered map implementation or the Boost unordered map implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard unordered map implementation has been chosen
    0 if the Boost unordered map implementation has been chosen.
*/

#if !defined(CXXD_UNORDERED_MAP_ERROR)
	#if (defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_MAP_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered map
	#elif defined(CXXD_HAS_STD_UNORDERED_MAP) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_UNORDERED_MAP && (defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_MAP_ERROR
            #error CXXD: Previous use of C++ standard unordered map erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_MAP && (defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_MAP_ERROR
            #error CXXD: Previous use of Boost unordered map erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_UNORDERED_MAP) || defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_UNORDERED_MAP)) || defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_MAP_ERROR
                #error CXXD: C++ standard unordered map is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_MAP)
                    #undef CXXD_HAS_STD_UNORDERED_MAP
                    #undef CXXD_UNORDERED_MAP_NS
                    #undef CXXD_UNORDERED_MAP_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_MAP 0
                #define CXXD_UNORDERED_MAP_NS boost
                #define CXXD_UNORDERED_MAP_HEADER <boost/unordered_map.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_MAP)
                #undef CXXD_HAS_STD_UNORDERED_MAP
                #undef CXXD_UNORDERED_MAP_NS
                #undef CXXD_UNORDERED_MAP_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_MAP 1
            #define CXXD_UNORDERED_MAP_NS std
            #define CXXD_UNORDERED_MAP_HEADER <unordered_map>
        #endif
    #endif
#endif
