//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file function.hpp
    @brief Dual library for the function implementation.
    
    Chooses either the Boost function implementation or the C++ standard function implementation.
*/

/** @def CXXD_FUNCTION_HEADER
    @brief The function header file name.
    
    The object-like macro expands to the include header file designation for the function header file.
    The macro is used with the syntax: #include CXXD_FUNCTION_HEADER
*/

/** @def CXXD_FUNCTION_NS
    @brief The function namespace.
    
    The object-like macro expands to the namespace for the function implementation.
*/

/** @def CXXD_HAS_STD_FUNCTION
    @brief Determines whether the C++ standard function implementation or the Boost function implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard function implementation has been chosen
    0 if the Boost function implementation has been chosen.
*/

#if !defined(CXXD_FUNCTION_ERROR)
	#if (defined(CXXD_FUNCTION_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_FUNCTION_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_FUNCTION_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for function
	#elif defined(CXXD_HAS_STD_FUNCTION) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_FUNCTION && (defined(CXXD_FUNCTION_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_FUNCTION_ERROR
            #error CXXD: Previous use of C++ standard function erroneously overridden
        #elif !CXXD_HAS_STD_FUNCTION && (defined(CXXD_FUNCTION_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_FUNCTION_ERROR
            #error CXXD: Previous use of Boost function erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_FUNCTION) || defined(CXXD_FUNCTION_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_FUNCTION_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)) || defined(CXXD_FUNCTION_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_FUNCTION_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_FUNCTION_ERROR
                #error CXXD: C++ standard function is not available
            #else
                #if defined(CXXD_HAS_STD_FUNCTION)
                    #undef CXXD_HAS_STD_FUNCTION
                    #undef CXXD_FUNCTION_NS
                    #undef CXXD_FUNCTION_HEADER
                #endif
                #define CXXD_HAS_STD_FUNCTION 0
                #define CXXD_FUNCTION_NS boost
                #define CXXD_FUNCTION_HEADER <boost/function.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_FUNCTION)
                #undef CXXD_HAS_STD_FUNCTION
                #undef CXXD_FUNCTION_NS
                #undef CXXD_FUNCTION_HEADER
            #endif
            #define CXXD_HAS_STD_FUNCTION 1
            #define CXXD_FUNCTION_NS std
            #define CXXD_FUNCTION_HEADER <functional>
        #endif
    #endif
#endif
