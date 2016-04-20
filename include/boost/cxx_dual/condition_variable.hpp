//  (C) Copyright Edward Diener 2015-2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

/** @file condition_variable.hpp
    @brief Dual library for the condition variable implementation.
    
    Chooses either the Boost condition variable implementation or the C++ standard condition variable implementation.
*/

/** @def CXXD_CONDITION_VARIABLE_HEADER
    @brief The condition variable header file name.
    
    The object-like macro expands to the include header file designation for the condition variable header file.
    The macro is used with the syntax: \#include CXXD_CONDITION_VARIABLE_HEADER
*/

/** @def CXXD_CONDITION_VARIABLE_NS
    @brief The condition variable namespace.
    
    The object-like macro expands to the namespace for the condition variable implementation.
*/

/** @def CXXD_HAS_STD_CONDITION_VARIABLE
    @brief Determines whether the C++ standard condition variable implementation or the Boost condition variable implementation has been chosen.
    
    The object-like macro expands to:
    1 if the C++ standard condition variable implementation has been chosen
    0 if the Boost condition variable library has been chosen.
*/

#if !defined(CXXD_CONDITION_VARIABLE_ERROR)
	#if (defined(CXXD_CONDITION_VARIABLE_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_CONDITION_VARIABLE_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_CONDITION_VARIABLE_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for condition variable
	#elif defined(CXXD_HAS_STD_CONDITION_VARIABLE) && !defined(CXXD_NO_CONSISTENCY)
        #if CXXD_HAS_STD_CONDITION_VARIABLE && (defined(CXXD_CONDITION_VARIABLE_USE_BOOST) || defined(CXXD_USE_BOOST))
            #define CXXD_CONDITION_VARIABLE_ERROR
            #error CXXD: Previous use of C++ standard condition variable erroneously overridden
        #elif !CXXD_HAS_STD_CONDITION_VARIABLE && (defined(CXXD_CONDITION_VARIABLE_USE_STD) || defined(CXXD_USE_STD))
            #define CXXD_CONDITION_VARIABLE_ERROR
            #error CXXD: Previous use of Boost condition variable erroneously overridden
        #endif
    #elif !defined(CXXD_HAS_STD_CONDITION_VARIABLE) || defined(CXXD_CONDITION_VARIABLE_USE_BOOST) || defined(CXXD_USE_BOOST) || defined(CXXD_CONDITION_VARIABLE_USE_STD) || defined(CXXD_USE_STD)
        #include <boost/config.hpp>
        #if (!defined(CXXD_NO_CONFIG) && defined(BOOST_NO_CXX11_HDR_CONDITION_VARIABLE)) || defined(CXXD_CONDITION_VARIABLE_USE_BOOST) || defined(CXXD_USE_BOOST)
            #if defined(CXXD_CONDITION_VARIABLE_USE_STD) || defined(CXXD_USE_STD)
                #define CXXD_CONDITION_VARIABLE_ERROR
                #error CXXD: C++ standard condition variable is not available
            #else
                #if defined(CXXD_HAS_STD_CONDITION_VARIABLE)
                    #undef CXXD_HAS_STD_CONDITION_VARIABLE
                    #undef CXXD_CONDITION_VARIABLE_NS
                    #undef CXXD_CONDITION_VARIABLE_HEADER
                #endif
                #define CXXD_HAS_STD_CONDITION_VARIABLE 0
                #define CXXD_CONDITION_VARIABLE_NS boost
                #define CXXD_CONDITION_VARIABLE_HEADER <boost/thread/condition_variable.hpp>
            #endif
        #else
            #if defined(CXXD_HAS_STD_CONDITION_VARIABLE)
                #undef CXXD_HAS_STD_CONDITION_VARIABLE
                #undef CXXD_CONDITION_VARIABLE_NS
                #undef CXXD_CONDITION_VARIABLE_HEADER
            #endif
            #define CXXD_HAS_STD_CONDITION_VARIABLE 1
            #define CXXD_CONDITION_VARIABLE_NS std
            #define CXXD_CONDITION_VARIABLE_HEADER <condition_variable>
        #endif
    #endif
#endif
