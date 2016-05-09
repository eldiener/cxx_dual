//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file unordered_multiset.hpp
    @brief Dual library for the unordered_multiset implementation.
    
    Chooses either the Boost unordered_multiset implementation or the C++ standard unordered_multiset implementation.
*/

/** @def CXXD_UNORDERED_MULTISET_HEADER
    @brief The unordered_multiset header file name.
    
    The object-like macro expands to the include header file designation for the unordered_multiset header file.
    The macro is used with the syntax: \#include CXXD_UNORDERED_MULTISET_HEADER
*/

/** @def CXXD_UNORDERED_MULTISET_NS
    @brief The unordered_multiset namespace.
    
    The object-like macro expands to the namespace for the unordered_multiset implementation.
*/

/** @def CXXD_UNORDERED_MULTISET_USE_BOOST
    @brief Override macro for Boost unordered_multiset implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost unordered_multiset implementation.
*/

/** @def CXXD_UNORDERED_MULTISET_USE_STD
    @brief Override macro for C++ standard unordered_multiset implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard unordered_multiset implementation. If the
    C++ standard unordered_multiset implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_UNORDERED_MULTISET
    @brief Determines whether the C++ standard unordered_multiset implementation or the Boost unordered_multiset implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard unordered_multiset implementation has been chosen
    0 if the Boost unordered_multiset implementation has been chosen.
*/

#if !defined(CXXD_UNORDERED_MULTISET_ERROR)
	#if (defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_MULTISET_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered_multiset
	#elif defined(CXXD_HAS_STD_UNORDERED_MULTISET) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_UNORDERED_MULTISET && (defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_MULTISET_ERROR
            #error CXXD: Previous use of C++ standard unordered_multiset erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_MULTISET && (defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_MULTISET_ERROR
            #error CXXD: Previous use of Boost unordered_multiset erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_UNORDERED_MULTISET) || defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_UNORDERED_SET)) || defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_MULTISET_ERROR
                #error CXXD: C++ standard unordered_multiset is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_MULTISET)
                    #undef CXXD_HAS_STD_UNORDERED_MULTISET
                    #undef CXXD_UNORDERED_MULTISET_NS
                    #undef CXXD_UNORDERED_MULTISET_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_MULTISET 0
                #define CXXD_UNORDERED_MULTISET_NS boost
                #define CXXD_UNORDERED_MULTISET_HEADER <boost/unordered_set.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_MULTISET)
                #undef CXXD_HAS_STD_UNORDERED_MULTISET
                #undef CXXD_UNORDERED_MULTISET_NS
                #undef CXXD_UNORDERED_MULTISET_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_MULTISET 1
            #define CXXD_UNORDERED_MULTISET_NS std
            #define CXXD_UNORDERED_MULTISET_HEADER <unordered_set>
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
    #define CXXD_UNORDERED_MULTISET_USE_STD
    #define CXXD_UNORDERED_MULTISET_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
