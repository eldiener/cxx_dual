//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file chrono.hpp
    @brief Dual library for chrono implementation.
    
    Chooses either the Boost chrono implementation or the C++ standard chrono implementation.
*/

/** @def CXXD_CHRONO_HEADER
    @brief The chrono header file name.
    
    The object-like macro expands to the include header file designation for the chrono header file.
    The macro is used with the syntax: \#include CXXD_CHRONO_HEADER
*/

/** @def CXXD_CHRONO_NS
    @brief The chrono namespace.
    
    The object-like macro expands to the namespace for the chrono implementation.
*/

/** @def CXXD_CHRONO_USE_BOOST
    @brief Override macro for Boost chrono implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost chrono implementation.
*/

/** @def CXXD_CHRONO_USE_STD
    @brief Override macro for C++ standard chrono implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard chrono implementation. If the
    C++ standard chrono implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_CHRONO
    @brief Determines whether the C++ standard chrono implementation or the Boost chrono implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard chrono implementation has been chosen
    0 if the Boost chrono implementation has been chosen.
*/

#if !defined(CXXD_CHRONO_ERROR)
	#if (defined(CXXD_CHRONO_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_CHRONO_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_CHRONO_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for chrono
	#elif defined(CXXD_HAS_STD_CHRONO) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_CHRONO && (defined(CXXD_CHRONO_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_CHRONO_ERROR
            #error CXXD: Previous use of C++ standard chrono erroneously overridden
        #elif !CXXD_HAS_STD_CHRONO && (defined(CXXD_CHRONO_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_CHRONO_ERROR
            #error CXXD: Previous use of Boost chrono erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_CHRONO) || defined(CXXD_CHRONO_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_CHRONO_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_CHRONO)) || defined(CXXD_CHRONO_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_CHRONO_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_CHRONO_ERROR
                #error CXXD: C++ standard chrono is not available
            #else
                #if defined(CXXD_HAS_STD_CHRONO)
                    #undef CXXD_HAS_STD_CHRONO
                    #undef CXXD_CHRONO_NS
                    #undef CXXD_CHRONO_HEADER
                #endif
                #define CXXD_HAS_STD_CHRONO 0
                #define CXXD_CHRONO_NS boost::chrono
                #define CXXD_CHRONO_HEADER <boost/chrono.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_CHRONO)
                #undef CXXD_HAS_STD_CHRONO
                #undef CXXD_CHRONO_NS
                #undef CXXD_CHRONO_HEADER
            #endif
            #define CXXD_HAS_STD_CHRONO 1
            #define CXXD_CHRONO_NS std::chrono
            #define CXXD_CHRONO_HEADER <chrono>
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
    #define CXXD_CHRONO_USE_STD
    #define CXXD_CHRONO_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
