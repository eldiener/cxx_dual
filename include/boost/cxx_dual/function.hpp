//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_FUNCTION_HPP)
#define CXXD_FUNCTION_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_FUNCTION_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_FUNCTION_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#error CXXD: C++ standard function is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for function
#endif
#endif
#define CXXD_HAS_STD_FUNCTION 0
#define CXXD_FUNCTION_NS boost
#define CXXD_FUNCTION_HEADER <boost/function.hpp>
#else
#define CXXD_HAS_STD_FUNCTION 1
#define CXXD_FUNCTION_NS std
#define CXXD_FUNCTION_HEADER <functional>
#endif

#endif // !defined(CXXD_FUNCTION_HPP)
