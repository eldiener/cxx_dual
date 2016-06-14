//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_UNORDERED_SET_HPP)
#define CXXD_IMPL_UNORDERED_SET_HPP

#if !defined(CXXD_HAS_STD_UNORDERED_SET)
#include <boost/cxx_dual/unordered_set.hpp>
#endif

#if CXXD_HAS_STD_UNORDERED_SET

#define CXXD_UNORDERED_SET_NS std
#include <unordered_set>
namespace cxxd_unordered_set_ns = std ;

#else

#define CXXD_UNORDERED_SET_NS boost
#include <boost/unordered_set.hpp>
namespace cxxd_unordered_set_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_UNORDERED_SET_HPP)
