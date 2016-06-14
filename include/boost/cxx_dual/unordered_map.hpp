//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file unordered_map.hpp
    @brief Dual library for the unordered_map implementation.
    
    Chooses either the Boost unordered_map implementation or the C++ standard unordered_map implementation.
*/

/** @def CXXD_UNORDERED_MAP_NS
    @brief The unordered_map namespace.
    
    The object-like macro expands to the namespace for the unordered_map implementation.
*/

/** @def CXXD_UNORDERED_MAP_USE_BOOST
    @brief Override macro for Boost unordered_map implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost unordered_map implementation.
*/

/** @def CXXD_UNORDERED_MAP_USE_STD
    @brief Override macro for C++ standard unordered_map implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard unordered_map implementation. If the
    C++ standard unordered_map implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_UNORDERED_MAP
    @brief Determines whether the C++ standard unordered_map implementation or the Boost unordered_map implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard unordered_map implementation has been chosen
    0 if the Boost unordered_map implementation has been chosen.
*/

#if !defined(CXXD_UNORDERED_MAP_ERROR)
	#if (defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_MAP_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered_map
	#elif defined(CXXD_HAS_STD_UNORDERED_MAP) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_UNORDERED_MAP && (defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_MAP_ERROR
            #error CXXD: Previous use of C++ standard unordered_map erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_MAP && (defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_MAP_ERROR
            #error CXXD: Previous use of Boost unordered_map erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_UNORDERED_MAP) || defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_UNORDERED_MAP)) || defined(CXXD_UNORDERED_MAP_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_MAP_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_MAP_ERROR
                #error CXXD: C++ standard unordered_map is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_MAP)
                    #undef CXXD_HAS_STD_UNORDERED_MAP
                #endif
                #define CXXD_HAS_STD_UNORDERED_MAP 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_MAP)
                #undef CXXD_HAS_STD_UNORDERED_MAP
            #endif
            #define CXXD_HAS_STD_UNORDERED_MAP 1
        #endif
    #endif
#endif

/*

  CXXD_DOXYGEN is only defined when building the docs for doxygen
  so that doxygen will document macros which are not defined
  in the library.
  
  It should never be defined by an end-user of CXXD.

*/

#if defined(CXXD_DOXYGEN)
    #define CXXD_UNORDERED_MAP_USE_STD
    #define CXXD_UNORDERED_MAP_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
