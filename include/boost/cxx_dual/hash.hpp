//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file hash.hpp
    @brief Dual library for the hash implementation.
    
    Chooses either the Boost hash implementation or the C++ standard hash implementation.
*/

/** @def CXXD_HASH_HEADER
    @brief The hash header file name.
    
    The object-like macro expands to the include header file designation for the hash header file.
    The macro is used with the syntax: \#include CXXD_HASH_HEADER
*/

/** @def CXXD_HASH_NS
    @brief The hash namespace.
    
    The object-like macro expands to the namespace for the hash implementation.
*/

/** @def CXXD_HASH_USE_BOOST
    @brief Override macro for Boost hash implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost hash implementation.
*/

/** @def CXXD_HASH_USE_STD
    @brief Override macro for C++ standard hash implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard hash implementation. If the
    C++ standard hash implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_HASH
    @brief Determines whether the C++ standard hash implementation or the Boost hash implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard hash implementation has been chosen
    0 if the Boost hash implementation has been chosen.
*/

#if !defined(CXXD_HASH_ERROR)
	#if (defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_HASH_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for hash
	#elif defined(CXXD_HAS_STD_HASH) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_HASH && (defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_HASH_ERROR
            #error CXXD: Previous use of C++ standard hash erroneously overridden
        #elif !CXXD_HAS_STD_HASH && (defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_HASH_ERROR
            #error CXXD: Previous use of Boost hash erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_HASH) || defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)) || defined(CXXD_HASH_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_HASH_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_HASH_ERROR
                #error CXXD: C++ standard hash is not available
            #else
                #if defined(CXXD_HAS_STD_HASH)
                    #undef CXXD_HAS_STD_HASH
                    #undef CXXD_HASH_HEADER
                #endif
                #define CXXD_HAS_STD_HASH 0
                #define CXXD_HASH_HEADER <boost/cxx_dual/detail/hash.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_HASH)
                #undef CXXD_HAS_STD_HASH
                #undef CXXD_HASH_HEADER
            #endif
            #define CXXD_HAS_STD_HASH 1
            #define CXXD_HASH_HEADER <boost/cxx_dual/detail/hash.hpp>
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
    #define CXXD_HASH_USE_STD
    #define CXXD_HASH_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
