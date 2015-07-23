//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_CONDITION_VARIABLE_HPP)
#define CXXD_CONDITION_VARIABLE_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_CONDITION_VARIABLE) || defined(CXXD_CONDITION_VARIABLE_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_CONDITION_VARIABLE_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_CONDITION_VARIABLE)
#error CXXD: C++ standard condition variable is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for condition variable
#endif
#endif
#define CXXD_HAS_STD_CONDITION_VARIABLE 0
#define CXXD_CONDITION_VARIABLE_NS boost
#define CXXD_CONDITION_VARIABLE_HEADER <boost/thread/condition_variable.hpp>
#else
#define CXXD_HAS_STD_CONDITION_VARIABLE 1
#define CXXD_CONDITION_VARIABLE_NS std
#define CXXD_CONDITION_VARIABLE_HEADER <condition_variable>
#endif

#endif // !defined(CXXD_CONDITION_VARIABLE_HPP)
