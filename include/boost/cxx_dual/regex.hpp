//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file regex.hpp
    @brief Dual library for the regex implementation.
    
    Chooses either the Boost regex implementation or the C++ standard regex implementation.
*/

/** @def CXXD_REGEX_HEADER
    @brief The regex header file name.
    
    The object-like macro expands to the include header file designation for the regex header file.
    The macro is used with the syntax: \#include CXXD_REGEX_HEADER
*/

/** @def CXXD_REGEX_NS
    @brief The regex namespace.
    
    The object-like macro expands to the namespace for the regex implementation.
*/

/** @def CXXD_REGEX_USE_BOOST
    @brief Override macro for Boost regex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file, 
    forces the dual library choice of the Boost regex implementation.
*/

/** @def CXXD_REGEX_USE_STD
    @brief Override macro for C++ standard regex implementation.
    
    The object-like macro, when defined to nothing prior to including this header file,
    forces the dual library choice of the C++ standard regex implementation. If the
    C++ standard regex implementation is not available a preprocessor error is generated.
*/

/** @def CXXD_HAS_STD_REGEX
    @brief Determines whether the C++ standard regex implementation or the Boost regex implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard regex implementation has been chosen
    0 if the Boost regex implementation has been chosen.
*/

#if !defined(CXXD_REGEX_ERROR)
	#if (defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_REGEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for regex
	#elif defined(CXXD_HAS_STD_REGEX) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_REGEX && (defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_REGEX_ERROR
            #error CXXD: Previous use of C++ standard regex erroneously overridden
        #elif !CXXD_HAS_STD_REGEX && (defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_REGEX_ERROR
            #error CXXD: Previous use of Boost regex erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_REGEX) || defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_REGEX)) || defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_REGEX_ERROR
                #error CXXD: C++ standard regex is not available
            #else
                #if defined(CXXD_HAS_STD_REGEX)
                    #undef CXXD_HAS_STD_REGEX
                    #undef CXXD_REGEX_NS
                    #undef CXXD_REGEX_HEADER
                #endif
                #define CXXD_HAS_STD_REGEX 0
                #define CXXD_REGEX_NS boost
                #define CXXD_REGEX_HEADER <boost/regex.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_REGEX)
                #undef CXXD_HAS_STD_REGEX
                #undef CXXD_REGEX_NS
                #undef CXXD_REGEX_HEADER
            #endif
            #define CXXD_HAS_STD_REGEX 1
            #define CXXD_REGEX_NS std
            #define CXXD_REGEX_HEADER <regex>
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
    #define CXXD_REGEX_USE_STD
    #define CXXD_REGEX_USE_BOOST
#endif // defined(CXXD_DOXYGEN)
