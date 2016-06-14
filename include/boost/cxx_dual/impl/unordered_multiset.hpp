//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_UNORDERED_MULTISET_HPP)
#define CXXD_IMPL_UNORDERED_MULTISET_HPP

#if !defined(CXXD_HAS_STD_UNORDERED_MULTISET)
#include <boost/cxx_dual/unordered_multiset.hpp>
#endif

#if CXXD_HAS_STD_UNORDERED_MULTISET

#define CXXD_UNORDERED_MULTISET_NS std
#include <unordered_set>
namespace cxxd_unordered_multiset_ns = std ;

#else

#define CXXD_UNORDERED_MULTISET_NS boost
#include <boost/unordered_set.hpp>
namespace cxxd_unordered_multiset_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_UNORDERED_MULTISET_HPP)
