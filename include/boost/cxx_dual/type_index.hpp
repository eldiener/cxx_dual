//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file type_index.hpp
    @brief Dual library for the type_index implementation.
    
    Chooses either the Boost type_index implementation or the C++ standard type_index implementation.
*/

/** @def CXXD_TYPE_INDEX_NS
    @brief The type_index namespace.
    
    The object-like macro expands to the namespace for the type_index implementation.
*/

/** @def CXXD_TYPE_INDEX_USE_BOOST
    @brief Override macro for Boost type_index implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost type_index implementation.
*/

/** @def CXXD_TYPE_INDEX_USE_STD
    @brief Override macro for C++ standard type_index implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard type_index implementation. If the
    C++ standard type_index implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_TYPE_INDEX
    @brief Determines whether the C++ standard type_index implementation or the Boost type_index implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard type_index implementation has been chosen
    0 if the Boost type_index implementation has been chosen.
*/

#if !defined(CXXD_TYPE_INDEX_ERROR)
	#if (defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_TYPE_INDEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for type_index
	#elif defined(CXXD_HAS_STD_TYPE_INDEX) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_TYPE_INDEX && (defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_TYPE_INDEX_ERROR
            #error CXXD: Previous use of C++ standard type_index erroneously overridden
        #elif !CXXD_HAS_STD_TYPE_INDEX && (defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_TYPE_INDEX_ERROR
            #error CXXD: Previous use of Boost type_index erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_TYPE_INDEX) || defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_TYPEINDEX)) || defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_TYPE_INDEX_ERROR
                #error CXXD: C++ standard type_index is not available
            #else
                #if defined(CXXD_HAS_STD_TYPE_INDEX)
                    #undef CXXD_HAS_STD_TYPE_INDEX
                #endif
                #define CXXD_HAS_STD_TYPE_INDEX 0
            #endif
        #else
            #if defined(CXXD_HAS_STD_TYPE_INDEX)
                #undef CXXD_HAS_STD_TYPE_INDEX
            #endif
            #define CXXD_HAS_STD_TYPE_INDEX 1
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
    #define CXXD_TYPE_INDEX_USE_STD
    #define CXXD_TYPE_INDEX_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
