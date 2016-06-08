//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_REGEX_HPP)
#define CXXD_DETAIL_REGEX_HPP

#if CXXD_HAS_STD_REGEX

#define CXXD_REGEX_NS std
#include <regex>
namespace cxxd_regex_ns = std ;

#else

#define CXXD_REGEX_NS boost
#include <boost/regex.hpp>
namespace cxxd_regex_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_REGEX_HPP)
