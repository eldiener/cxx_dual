//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file weak_ptr.hpp
    @brief Dual library for the weak_ptr implementation.
    
    Chooses either the Boost weak_ptr implementation or the C++ standard weak_ptr implementation.
*/

/** @def CXXD_WEAK_PTR_HEADER
    @brief The weak_ptr header file name.
    
    The object-like macro expands to the include header file designation for the weak_ptr header file.
    The macro is used with the syntax: \#include CXXD_WEAK_PTR_HEADER
*/

/** @def CXXD_WEAK_PTR_NS
    @brief The weak_ptr namespace.
    
    The object-like macro expands to the namespace for the weak_ptr implementation.
*/

/** @def CXXD_WEAK_PTR_USE_BOOST
    @brief Override macro for Boost weak_ptr implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost weak_ptr implementation.
*/

/** @def CXXD_WEAK_PTR_USE_STD
    @brief Override macro for C++ standard weak_ptr implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard weak_ptr implementation. If the
    C++ standard weak_ptr implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_WEAK_PTR
    @brief Determines whether the C++ standard weak_ptr implementation or the Boost weak_ptr implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard weak_ptr implementation has been chosen
    0 if the Boost weak_ptr implementation has been chosen.
*/

#if !defined(CXXD_WEAK_PTR_ERROR)
	#if (defined(CXXD_WEAK_PTR_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_WEAK_PTR_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_WEAK_PTR_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for weak_ptr
	#elif defined(CXXD_HAS_STD_WEAK_PTR) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_WEAK_PTR && (defined(CXXD_WEAK_PTR_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_WEAK_PTR_ERROR
            #error CXXD: Previous use of C++ standard weak_ptr erroneously overridden
        #elif !CXXD_HAS_STD_WEAK_PTR && (defined(CXXD_WEAK_PTR_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_WEAK_PTR_ERROR
            #error CXXD: Previous use of Boost weak_ptr erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_WEAK_PTR) || defined(CXXD_WEAK_PTR_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_WEAK_PTR_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_SMART_PTR)) || defined(CXXD_WEAK_PTR_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_WEAK_PTR_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_WEAK_PTR_ERROR
                #error CXXD: C++ standard weak_ptr is not available
            #else
                #if defined(CXXD_HAS_STD_WEAK_PTR)
                    #undef CXXD_HAS_STD_WEAK_PTR
                    #undef CXXD_WEAK_PTR_HEADER
                #endif
                #define CXXD_HAS_STD_WEAK_PTR 0
                #define CXXD_WEAK_PTR_HEADER <boost/cxx_dual/detail/weak_ptr.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_WEAK_PTR)
                #undef CXXD_HAS_STD_WEAK_PTR
                #undef CXXD_WEAK_PTR_HEADER
            #endif
            #define CXXD_HAS_STD_WEAK_PTR 1
            #define CXXD_WEAK_PTR_HEADER <boost/cxx_dual/detail/weak_ptr.hpp>
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
    #define CXXD_WEAK_PTR_USE_STD
    #define CXXD_WEAK_PTR_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
