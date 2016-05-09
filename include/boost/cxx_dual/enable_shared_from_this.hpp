//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file enable_shared_from_this.hpp
    @brief Dual library for the enable_shared_from_this implementation.
    
    Chooses either the Boost enable_shared_from_this_implementation or the C++ standard enable_shared_from_this implementation.
*/

/** @def CXXD_ENABLE_SHARED_FROM_THIS_HEADER
    @brief The enable_shared_from_this header file name.
    
    The object-like macro expands to the include header file designation for the enable_shared_from_this header file.
    The macro is used with the syntax: \#include CXXD_ENABLE_SHARED_FROM_THIS_HEADER
*/

/** @def CXXD_ENABLE_SHARED_FROM_THIS_NS
    @brief The enable_shared_from_this namespace.
    
    The object-like macro expands to the namespace for the enable_shared_from_this implementation.
*/

/** @def CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST
    @brief Override macro for Boost enable_shared_from_this implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost enable_shared_from_this implementation.
*/

/** @def CXXD_ENABLE_SHARED_FROM_THIS_USE_STD
    @brief Override macro for C++ standard enable_shared_from_this implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard enable_shared_from_this implementation. If the
    C++ standard enable_shared_from_this implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS
    @brief Determines whether the C++ standard enable_shared_from_this implementation or the Boost enable_shared_from_this implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard enable_shared_from_this implementation has been chosen
    0 if the Boost enable_shared_from_this implementation has been chosen.
*/

#if !defined(CXXD_ENABLE_SHARED_FROM_THIS_ERROR)
	#if (defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_ENABLE_SHARED_FROM_THIS_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for enable_shared_from_this
	#elif defined(CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS && (defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_ENABLE_SHARED_FROM_THIS_ERROR
            #error CXXD: Previous use of C++ standard enable_shared_from_this erroneously overridden
        #elif !CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS && (defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_ENABLE_SHARED_FROM_THIS_ERROR
            #error CXXD: Previous use of Boost enable_shared_from_this erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS) || defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_SMART_PTR)) || defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_ENABLE_SHARED_FROM_THIS_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_ENABLE_SHARED_FROM_THIS_ERROR
                #error CXXD: C++ standard enable_shared_from_this is not available
            #else
                #if defined(CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS)
                    #undef CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS
                    #undef CXXD_ENABLE_SHARED_FROM_THIS_NS
                    #undef CXXD_ENABLE_SHARED_FROM_THIS_HEADER
                #endif
                #define CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS 0
                #define CXXD_ENABLE_SHARED_FROM_THIS_NS boost
                #define CXXD_ENABLE_SHARED_FROM_THIS_HEADER <boost/enable_shared_from_this.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS)
                #undef CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS
                #undef CXXD_ENABLE_SHARED_FROM_THIS_NS
                #undef CXXD_ENABLE_SHARED_FROM_THIS_HEADER
            #endif
            #define CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS 1
            #define CXXD_ENABLE_SHARED_FROM_THIS_NS std
            #define CXXD_ENABLE_SHARED_FROM_THIS_HEADER <memory>
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
    #define CXXD_ENABLE_SHARED_FROM_THIS_USE_STD
    #define CXXD_ENABLE_SHARED_FROM_THIS_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
