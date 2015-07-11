//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_REGEX_HPP)
#define CXX_DUAL_REGEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_REGEX) || defined(CXX_DUAL_REGEX_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_REGEX_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_REGEX)
#error CXX_DUAL: C++ standard regex is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for regex
#endif
#endif
#define CXX_DUAL_HAS_STD_REGEX 0
#define CXX_DUAL_REGEX_NS boost
#define CXX_DUAL_REGEX_HEADER <boost/regex.hpp>
#else
#define CXX_DUAL_HAS_STD_REGEX 1
#define CXX_DUAL_REGEX_NS std
#define CXX_DUAL_REGEX_HEADER <regex>
#endif

#endif // !defined(CXX_DUAL_REGEX_HPP)
