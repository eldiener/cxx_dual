//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file ref.hpp
    @brief Dual library for the ref implementation.
    
    Chooses either the Boost ref implementation or the C++ standard ref implementation.
*/

/** @def CXXD_REF_HEADER
    @brief The ref header file name.
    
    The object-like macro expands to the include header file designation for the ref header file.
    The macro is used with the syntax: \#include CXXD_REF_HEADER
*/

/** @def CXXD_REF_NS
    @brief The ref namespace.
    
    The object-like macro expands to the namespace for the ref implementation.
*/

/** @def CXXD_REF_USE_BOOST
    @brief Override macro for Boost ref implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost ref implementation.
*/

/** @def CXXD_REF_USE_STD
    @brief Override macro for C++ standard ref implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard ref implementation. If the
    C++ standard ref implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_REF
    @brief Determines whether the C++ standard ref implementation or the Boost ref implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard ref implementation has been chosen
    0 if the Boost ref implementation has been chosen.
*/

#if !defined(CXXD_REF_ERROR)
	#if (defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_REF_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for ref
	#elif defined(CXXD_HAS_STD_REF)
        #if CXXD_HAS_STD_REF && (defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_REF_ERROR
            #error CXXD: Previous use of C++ standard ref erroneously overridden
        #elif !CXXD_HAS_STD_REF && (defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_REF_ERROR
            #error CXXD: Previous use of Boost ref erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_REF) || defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)) || defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_REF_ERROR
                #error CXXD: C++ standard ref is not available
            #else
                #if defined(CXXD_HAS_STD_REF)
                    #undef CXXD_HAS_STD_REF
                    #undef CXXD_REF_NS
                    #undef CXXD_REF_HEADER
                #endif
                #define CXXD_HAS_STD_REF 0
                #define CXXD_REF_NS boost
                #define CXXD_REF_HEADER <boost/core/ref.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_REF)
                #undef CXXD_HAS_STD_REF
                #undef CXXD_REF_NS
                #undef CXXD_REF_HEADER
            #endif
            #define CXXD_HAS_STD_REF 1
            #define CXXD_REF_NS std
            #define CXXD_REF_HEADER <functional>
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
    #define CXXD_REF_USE_STD
    #define CXXD_REF_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
