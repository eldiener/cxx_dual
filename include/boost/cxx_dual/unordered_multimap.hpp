//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file unordered_multimap.hpp
    @brief Dual library for the unordered multimap implementation.
    
    Chooses either the Boost unordered multimap implementation or the C++ standard unordered multimap implementation.
*/

/** @def CXXD_UNORDERED_MULTIMAP_HEADER
    @brief The unordered multimap header file name.
    
    The object-like macro expands to the include header file designation for the unordered multimap header file.
    The macro is used with the syntax: \#include CXXD_UNORDERED_MULTIMAP_HEADER
*/

/** @def CXXD_UNORDERED_MULTIMAP_NS
    @brief The unordered multimap namespace.
    
    The object-like macro expands to the namespace for the unordered multimap implementation.
*/

/** @def CXXD_UNORDERED_MULTIMAP_USE_BOOST
    @brief Override macro for Boost unordered multimap implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost unordered multimap implementation.
*/

/** @def CXXD_UNORDERED_MULTIMAP_USE_STD
    @brief Override macro for C++ standard unordered multimap implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard unordered multimap implementation. If the
    C++ standard unordered multimap implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_UNORDERED_MULTIMAP
    @brief Determines whether the C++ standard unordered multimap implementation or the Boost unordered multimap implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard unordered multimap implementation has been chosen
    0 if the Boost unordered multimap implementation has been chosen.
*/

#if !defined(CXXD_UNORDERED_MULTIMAP_ERROR)
	#if (defined(CXXD_UNORDERED_MULTIMAP_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_MULTIMAP_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_MULTIMAP_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered multimap
	#elif defined(CXXD_HAS_STD_UNORDERED_MULTIMAP) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_UNORDERED_MULTIMAP && (defined(CXXD_UNORDERED_MULTIMAP_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_MULTIMAP_ERROR
            #error CXXD: Previous use of C++ standard unordered multimap erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_MULTIMAP && (defined(CXXD_UNORDERED_MULTIMAP_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_MULTIMAP_ERROR
            #error CXXD: Previous use of Boost unordered multimap erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_UNORDERED_MULTIMAP) || defined(CXXD_UNORDERED_MULTIMAP_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_UNORDERED_MULTIMAP_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_UNORDERED_MAP)) || defined(CXXD_UNORDERED_MULTIMAP_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_MULTIMAP_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_MULTIMAP_ERROR
                #error CXXD: C++ standard unordered multimap is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_MULTIMAP)
                    #undef CXXD_HAS_STD_UNORDERED_MULTIMAP
                    #undef CXXD_UNORDERED_MULTIMAP_NS
                    #undef CXXD_UNORDERED_MULTIMAP_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_MULTIMAP 0
                #define CXXD_UNORDERED_MULTIMAP_NS boost
                #define CXXD_UNORDERED_MULTIMAP_HEADER <boost/unordered_map.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_MULTIMAP)
                #undef CXXD_HAS_STD_UNORDERED_MULTIMAP
                #undef CXXD_UNORDERED_MULTIMAP_NS
                #undef CXXD_UNORDERED_MULTIMAP_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_MULTIMAP 1
            #define CXXD_UNORDERED_MULTIMAP_NS std
            #define CXXD_UNORDERED_MULTIMAP_HEADER <unordered_map>
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
    #define CXXD_UNORDERED_MULTIMAP_USE_STD
    #define CXXD_UNORDERED_MULTIMAP_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
