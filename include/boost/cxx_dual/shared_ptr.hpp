//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file shared_ptr.hpp
    @brief Dual library for the shared_ptr implementation.
    
    Chooses either the Boost shared_ptr implementation or the C++ standard shared_ptr implementation.
*/

/** @def CXXD_SHARED_PTR_HEADER
    @brief The shared_ptr header file name.
    
    The object-like macro expands to the include header file designation for the shared_ptr header file.
    The macro is used with the syntax: \#include CXXD_SHARED_PTR_HEADER
    
    The included header file includes the shared_ptr implementation as well as
    the weak_ptr, make_shared, and enable_shared_from_this implementations.
*/

/** @def CXXD_SHARED_PTR_ONLY_HEADER
    @brief The shared_ptr header file name.
    
    The object-like macro expands to the include header file designation for the shared_ptr header file.
    The macro is used with the syntax: \#include CXXD_SHARED_PTR_HEADER
    
    The included header file includes only the shared_ptr implementation.
*/

/** @def CXXD_SHARED_PTR_NS
    @brief The shared_ptr namespace.
    
    The object-like macro expands to the namespace for the shared_ptr implementation.
*/

/** @def CXXD_SHARED_PTR_USE_BOOST
    @brief Override macro for Boost shared_ptr implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost shared_ptr implementation.
*/

/** @def CXXD_SHARED_PTR_USE_STD
    @brief Override macro for C++ standard shared_ptr implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard shared_ptr implementation. If the
    C++ standard shared_ptr implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_SHARED_PTR
    @brief Determines whether the C++ standard shared_ptr implementation or the Boost shared_ptr implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard shared_ptr implementation has been chosen
    0 if the Boost shared_ptr implementation has been chosen.
*/

#if !defined(CXXD_SHARED_PTR_ERROR)
	#if (defined(CXXD_SHARED_PTR_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_SHARED_PTR_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_SHARED_PTR_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for shared_ptr
	#elif defined(CXXD_HAS_STD_SHARED_PTR) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_SHARED_PTR && (defined(CXXD_SHARED_PTR_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_SHARED_PTR_ERROR
            #error CXXD: Previous use of C++ standard shared_ptr erroneously overridden
        #elif !CXXD_HAS_STD_SHARED_PTR && (defined(CXXD_SHARED_PTR_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_SHARED_PTR_ERROR
            #error CXXD: Previous use of Boost shared_ptr erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_SHARED_PTR) || defined(CXXD_SHARED_PTR_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_SHARED_PTR_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_SMART_PTR)) || defined(CXXD_SHARED_PTR_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_SHARED_PTR_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_SHARED_PTR_ERROR
                #error CXXD: C++ standard shared_ptr is not available
            #else
                #if defined(CXXD_HAS_STD_SHARED_PTR)
                    #undef CXXD_HAS_STD_SHARED_PTR
                    #undef CXXD_SHARED_PTR_HEADER
                    #undef CXXD_SHARED_PTR_ONLY_HEADER
                #endif
                #define CXXD_HAS_STD_SHARED_PTR 0
                #define CXXD_SHARED_PTR_HEADER <boost/cxx_dual/detail/shared_ptr.hpp>
                #define CXXD_SHARED_PTR_ONLY_HEADER <boost/cxx_dual/detail/shared_ptr_only.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_SHARED_PTR)
                #undef CXXD_HAS_STD_SHARED_PTR
                #undef CXXD_SHARED_PTR_HEADER
                #undef CXXD_SHARED_PTR_ONLY_HEADER
            #endif
            #define CXXD_HAS_STD_SHARED_PTR 1
            #define CXXD_SHARED_PTR_HEADER <boost/cxx_dual/detail/shared_ptr.hpp>
            #define CXXD_SHARED_PTR_ONLY_HEADER <boost/cxx_dual/detail/shared_ptr_only.hpp>
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
    #define CXXD_SHARED_PTR_USE_STD
    #define CXXD_SHARED_PTR_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
