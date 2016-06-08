//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_CONDITION_VARIABLE_HPP)
#define CXXD_DETAIL_CONDITION_VARIABLE_HPP

#if CXXD_HAS_STD_CONDITION_VARIABLE

#define CXXD_CONDITION_VARIABLE_NS std
#include <condition_variable>
namespace cxxd_condition_variable_ns = std ;

#else

#define CXXD_CONDITION_VARIABLE_NS boost
#include <boost/thread/condition_variable.hpp>
namespace cxxd_condition_variable_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_CONDITION_VARIABLE_HPP)
