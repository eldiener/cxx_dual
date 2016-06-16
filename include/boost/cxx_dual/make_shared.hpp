//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file make_shared.hpp
    @brief Dual library for the make_shared implementation.
    
    Chooses either the Boost make_shared implementation or the C++ standard make_shared implementation.
*/

/** @def CXXD_MAKE_SHARED_HEADER
    @brief The make_shared header file name.
    
    The object-like macro expands to the include header file designation for the make_shared header file.
    The macro is used with the syntax: \#include CXXD_MAKE_SHARED_HEADER
*/

/** @def CXXD_MAKE_SHARED_NS
    @brief The make_shared namespace.
    
    The object-like macro expands to the namespace for the make_shared implementation.
*/

/** @def CXXD_MAKE_SHARED_USE_BOOST
    @brief Override macro for Boost make_shared implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost make_shared implementation.
*/

/** @def CXXD_MAKE_SHARED_USE_STD
    @brief Override macro for C++ standard make_shared implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard make_shared implementation. If the
    C++ standard make_shared implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_MAKE_SHARED
    @brief Determines whether the C++ standard make_shared implementation or the Boost make_shared implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard make_shared implementation has been chosen
    0 if the Boost make_shared implementation has been chosen.
*/

#if !defined(CXXD_MAKE_SHARED_ERROR)
	#if (defined(CXXD_MAKE_SHARED_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_MAKE_SHARED_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_MAKE_SHARED_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for make_shared
	#elif defined(CXXD_HAS_STD_MAKE_SHARED) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_MAKE_SHARED && (defined(CXXD_MAKE_SHARED_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_MAKE_SHARED_ERROR
            #error CXXD: Previous use of C++ standard make_shared erroneously overridden
        #elif !CXXD_HAS_STD_MAKE_SHARED && (defined(CXXD_MAKE_SHARED_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_MAKE_SHARED_ERROR
            #error CXXD: Previous use of Boost make_shared erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_MAKE_SHARED) || defined(CXXD_MAKE_SHARED_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_MAKE_SHARED_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_SMART_PTR)) || defined(CXXD_MAKE_SHARED_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_MAKE_SHARED_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_MAKE_SHARED_ERROR
                #error CXXD: C++ standard make_shared is not available
            #else
                #if defined(CXXD_HAS_STD_MAKE_SHARED)
                    #undef CXXD_HAS_STD_MAKE_SHARED
                    #undef CXXD_MAKE_SHARED_NS
                    #undef CXXD_MAKE_SHARED_HEADER
                #endif
                #define CXXD_HAS_STD_MAKE_SHARED 0
                #define CXXD_MAKE_SHARED_NS boost
                #define CXXD_MAKE_SHARED_HEADER <boost/make_shared.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_MAKE_SHARED)
                #undef CXXD_HAS_STD_MAKE_SHARED
                #undef CXXD_MAKE_SHARED_NS
                #undef CXXD_MAKE_SHARED_HEADER
            #endif
            #define CXXD_HAS_STD_MAKE_SHARED 1
            #define CXXD_MAKE_SHARED_NS std
            #define CXXD_MAKE_SHARED_HEADER <memory>
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
    #define CXXD_MAKE_SHARED_USE_STD
    #define CXXD_MAKE_SHARED_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
