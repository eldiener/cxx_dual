//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_REGEX_HPP)
#define CXXD_REGEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_REGEX) || defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_REGEX)
#error CXXD: C++ standard regex is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for regex
#endif
#endif
#define CXXD_HAS_STD_REGEX 0
#define CXXD_REGEX_NS boost
#define CXXD_REGEX_HEADER <boost/regex.hpp>
#else
#define CXXD_HAS_STD_REGEX 1
#define CXXD_REGEX_NS std
#define CXXD_REGEX_HEADER <regex>
#endif

#endif // !defined(CXXD_REGEX_HPP)
