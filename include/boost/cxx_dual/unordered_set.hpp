//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file unordered_set.hpp
    @brief Dual library for the unordered_set implementation.
    
    Chooses either the Boost unordered_set implementation or the C++ standard unordered_set implementation.
*/

/** @def CXXD_UNORDERED_SET_HEADER
    @brief The unordered_set header file name.
    
    The object-like macro expands to the include header file designation for the unordered_set header file.
    The macro is used with the syntax: \#include CXXD_UNORDERED_SET_HEADER
*/

/** @def CXXD_UNORDERED_SET_NS
    @brief The unordered_set namespace.
    
    The object-like macro expands to the namespace for the unordered_set implementation.
*/

/** @def CXXD_UNORDERED_SET_USE_BOOST
    @brief Override macro for Boost unordered_set implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost unordered_set implementation.
*/

/** @def CXXD_UNORDERED_SET_USE_STD
    @brief Override macro for C++ standard unordered_set implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard unordered_set implementation. If the
    C++ standard unordered_set implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_UNORDERED_SET
    @brief Determines whether the C++ standard unordered_set implementation or the Boost unordered_set implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard unordered_set implementation has been chosen
    0 if the Boost unordered_set implementation has been chosen.
*/

#if !defined(CXXD_UNORDERED_SET_ERROR)
	#if (defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_UNORDERED_SET_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for unordered_set
	#elif defined(CXXD_HAS_STD_UNORDERED_SET) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_UNORDERED_SET && (defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_UNORDERED_SET_ERROR
            #error CXXD: Previous use of C++ standard unordered_set erroneously overridden
        #elif !CXXD_HAS_STD_UNORDERED_SET && (defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_UNORDERED_SET_ERROR
            #error CXXD: Previous use of Boost unordered_set erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_UNORDERED_SET) || defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_UNORDERED_SET)) || defined(CXXD_UNORDERED_SET_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_UNORDERED_SET_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_UNORDERED_SET_ERROR
                #error CXXD: C++ standard unordered_set is not available
            #else
                #if defined(CXXD_HAS_STD_UNORDERED_SET)
                    #undef CXXD_HAS_STD_UNORDERED_SET
                    #undef CXXD_UNORDERED_SET_HEADER
                #endif
                #define CXXD_HAS_STD_UNORDERED_SET 0
                #define CXXD_UNORDERED_SET_HEADER <boost/cxx_dual/detail/unordered_set.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_UNORDERED_SET)
                #undef CXXD_HAS_STD_UNORDERED_SET
                #undef CXXD_UNORDERED_SET_HEADER
            #endif
            #define CXXD_HAS_STD_UNORDERED_SET 1
            #define CXXD_UNORDERED_SET_HEADER <boost/cxx_dual/detail/unordered_set.hpp>
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
    #define CXXD_UNORDERED_SET_USE_STD
    #define CXXD_UNORDERED_SET_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
