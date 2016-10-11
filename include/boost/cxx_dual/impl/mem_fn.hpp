//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file mem_fn.hpp
    @brief Dual library for the mem_fn implementation.
    
    Chooses either the Boost mem_fn implementation or the C++ standard mem_fn implementation.
*/

/** @def CXXD_MEM_FN_HEADER
    @brief The mem_fn header file name.
    
    The object-like macro expands to the include header file designation for the mem_fn header file.
    The macro is used with the syntax: \#include CXXD_MEM_FN_HEADER
*/

/** @def CXXD_MEM_FN_NS
    @brief The mem_fn namespace.
    
    The object-like macro expands to the namespace for the mem_fn implementation.
*/

/** @def CXXD_MEM_FN_USE_BOOST
    @brief Override macro for Boost mem_fn implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost mem_fn implementation.
*/

/** @def CXXD_MEM_FN_USE_STD
    @brief Override macro for C++ standard mem_fn implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard mem_fn implementation. If the
    C++ standard mem_fn implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_MEM_FN
    @brief Determines whether the C++ standard mem_fn implementation or the Boost mem_fn implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard mem_fn implementation has been chosen
    0 if the Boost mem_fn implementation has been chosen.
*/

#if !defined(CXXD_MEM_FN_ERROR)
	#if (defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MEM_FN_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for mem_fn
	#elif defined(CXXD_HAS_STD_MEM_FN)
        #if CXXD_HAS_STD_MEM_FN && (defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_MEM_FN_ERROR
            #error CXXD: Previous use of C++ standard mem_fn erroneously overridden
        #elif !CXXD_HAS_STD_MEM_FN && (defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_MEM_FN_ERROR
            #error CXXD: Previous use of Boost mem_fn erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_MEM_FN) || defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)) || defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_MEM_FN_ERROR
                #error CXXD: C++ standard mem_fn is not available
            #else
                #if defined(CXXD_HAS_STD_MEM_FN)
                    #undef CXXD_HAS_STD_MEM_FN
                    #undef CXXD_MEM_FN_NS
                    #undef CXXD_MEM_FN_HEADER
                #endif
                #define CXXD_HAS_STD_MEM_FN 0
                #define CXXD_MEM_FN_NS boost
                #define CXXD_MEM_FN_HEADER <boost/mem_fn.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_MEM_FN)
                #undef CXXD_HAS_STD_MEM_FN
                #undef CXXD_MEM_FN_NS
                #undef CXXD_MEM_FN_HEADER
            #endif
            #define CXXD_HAS_STD_MEM_FN 1
            #define CXXD_MEM_FN_NS std
            #define CXXD_MEM_FN_HEADER <functional>
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
    #define CXXD_MEM_FN_USE_STD
    #define CXXD_MEM_FN_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
