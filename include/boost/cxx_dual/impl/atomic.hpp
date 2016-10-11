//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file atomic.hpp
    @brief Dual library for atomic data type.
    
    Chooses either the Boost atomic implementation or the C++ standard atomic implementation.
*/

/** @def CXXD_ATOMIC_HEADER
    @brief The atomic header file name.
    
    The object-like macro expands to the include header file designation for the atomic header file.
    The macro is used with the syntax: \#include CXXD_ATOMIC_HEADER
*/

/** @def CXXD_ATOMIC_MACRO(macro)
    @brief Generates an object-like macro name from the 'macro' name passed to it.
    
    The function-like macro expands to the name of an atmomic object-like macro name
    for any given atomic macro name passed to it.
*/

/** @def CXXD_ATOMIC_NS
    @brief The atomic namespace.
    
    The object-like macro expands to the namespace for the atomic implementation.
*/

/** @def CXXD_ATOMIC_USE_BOOST
    @brief Override macro for Boost atomic implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost atomic implementation.
*/

/** @def CXXD_ATOMIC_USE_STD
    @brief Override macro for C++ standard atomic implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard atomic implementation. If the
    C++ standard atomic implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_ATOMIC
    @brief Determines whether the C++ standard atomic implementation or the Boost atomic implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard atomic implementation has been chosen
    0 if the Boost atomic implementation has been chosen.
*/

#if !defined(CXXD_ATOMIC_ERROR)
	#if (defined(CXXD_ATOMIC_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_ATOMIC_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_ATOMIC_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for atomic
	#elif defined(CXXD_HAS_STD_ATOMIC)
        #if CXXD_HAS_STD_ATOMIC && (defined(CXXD_ATOMIC_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_ATOMIC_ERROR
            #error CXXD: Previous use of C++ standard atomic erroneously overridden
        #elif !CXXD_HAS_STD_ATOMIC && (defined(CXXD_ATOMIC_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_ATOMIC_ERROR
            #error CXXD: Previous use of Boost atomic erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_ATOMIC) || defined(CXXD_ATOMIC_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_ATOMIC_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_ATOMIC)) || defined(CXXD_ATOMIC_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_ATOMIC_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_ATOMIC_ERROR
                #error CXXD: C++ standard atomic is not available
            #else
                #if defined(CXXD_HAS_STD_ATOMIC)
                    #undef CXXD_HAS_STD_ATOMIC
                    #undef CXXD_ATOMIC_NS
                    #undef CXXD_ATOMIC_HEADER
                    #undef CXXD_ATOMIC_MACRO
                #endif
                #define CXXD_HAS_STD_ATOMIC 0
                #define CXXD_ATOMIC_NS boost
                #define CXXD_ATOMIC_HEADER <boost/atomic/atomic.hpp>
                #define CXXD_ATOMIC_MACRO(macro) BOOST_ ## macro
            #endif
        #else
            #if defined(CXXD_HAS_STD_ATOMIC)
                #undef CXXD_HAS_STD_ATOMIC
                #undef CXXD_ATOMIC_NS
                #undef CXXD_ATOMIC_HEADER
                #undef CXXD_ATOMIC_MACRO
            #endif
            #define CXXD_HAS_STD_ATOMIC 1
            #define CXXD_ATOMIC_NS std
            #define CXXD_ATOMIC_HEADER <atomic>
            #define CXXD_ATOMIC_MACRO(macro) macro
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
    #define CXXD_ATOMIC_USE_STD
    #define CXXD_ATOMIC_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
