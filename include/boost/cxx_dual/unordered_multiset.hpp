//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_UNORDERED_MULTISET_HPP)
#define CXXD_UNORDERED_MULTISET_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_UNORDERED_SET) || defined(CXXD_UNORDERED_MULTISET_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_UNORDERED_MULTISET_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_UNORDERED_SET)
#error CXXD: C++ standard unordered multiset is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for unordered multiset
#endif
#endif
#define CXXD_HAS_STD_UNORDERED_MULTISET 0
#define CXXD_UNORDERED_MULTISET_NS boost
#define CXXD_UNORDERED_MULTISET_HEADER <boost/unordered_set.hpp>
#else
#define CXXD_HAS_STD_UNORDERED_MULTISET 1
#define CXXD_UNORDERED_MULTISET_NS std
#define CXXD_UNORDERED_MULTISET_HEADER <unordered_set>
#endif

#endif // !defined(CXXD_UNORDERED_MULTISET_HPP)
