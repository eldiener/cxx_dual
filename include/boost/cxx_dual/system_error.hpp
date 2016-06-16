//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file system_error.hpp
    @brief Dual library for the system error implementation.
    
    Chooses either the Boost system error implementation or the C++ standard system error implementation.
*/

/** @def CXXD_SYSTEM_ERROR_HEADER
    @brief The system error header file name.
    
    The object-like macro expands to the include header file designation for the system error header file.
    The macro is used with the syntax: \#include CXXD_SYSTEM_ERROR_HEADER
*/

/** @def CXXD_SYSTEM_ERROR_NS
    @brief The system error namespace.
    
    The object-like macro expands to the namespace for the system error implementation.
*/

/** @def CXXD_SYSTEM_ERROR_USE_BOOST
    @brief Override macro for Boost system error implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost system error implementation.
*/

/** @def CXXD_SYSTEM_ERROR_USE_STD
    @brief Override macro for C++ standard system error implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard system error implementation. If the
    C++ standard system error implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_SYSTEM_ERROR
    @brief Determines whether the C++ standard system error implementation or the Boost system error implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard system error implementation has been chosen
    0 if the Boost system error implementation has been chosen.
*/

#if !defined(CXXD_SYSTEM_ERROR)
	#if (defined(CXXD_SYSTEM_ERROR_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_SYSTEM_ERROR_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_SYSTEM_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for system error
	#elif defined(CXXD_HAS_STD_SYSTEM_ERROR) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_SYSTEM_ERROR && (defined(CXXD_SYSTEM_ERROR_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_SYSTEM_ERROR
            #error CXXD: Previous use of C++ standard system error erroneously overridden
        #elif !CXXD_HAS_STD_SYSTEM_ERROR && (defined(CXXD_SYSTEM_ERROR_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_SYSTEM_ERROR
            #error CXXD: Previous use of Boost system error erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_SYSTEM_ERROR) || defined(CXXD_SYSTEM_ERROR_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_SYSTEM_ERROR_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_SYSTEM_ERROR)) || defined(CXXD_SYSTEM_ERROR_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_SYSTEM_ERROR_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_SYSTEM_ERROR
                #error CXXD: C++ standard system error is not available
            #else
                #if defined(CXXD_HAS_STD_SYSTEM_ERROR)
                    #undef CXXD_HAS_STD_SYSTEM_ERROR
                    #undef CXXD_SYSTEM_ERROR_NS
                    #undef CXXD_SYSTEM_ERROR_HEADER
                #endif
                #define CXXD_HAS_STD_SYSTEM_ERROR 0
                #define CXXD_SYSTEM_ERROR_NS boost::system
                #define CXXD_SYSTEM_ERROR_HEADER <boost/system/system_error.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_SYSTEM_ERROR)
                #undef CXXD_HAS_STD_SYSTEM_ERROR
                #undef CXXD_SYSTEM_ERROR_NS
                #undef CXXD_SYSTEM_ERROR_HEADER
            #endif
            #define CXXD_HAS_STD_SYSTEM_ERROR 1
            #define CXXD_SYSTEM_ERROR_NS std
            #define CXXD_SYSTEM_ERROR_HEADER <system_error>
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
    #define CXXD_SYSTEM_ERROR_USE_STD
    #define CXXD_SYSTEM_ERROR_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
