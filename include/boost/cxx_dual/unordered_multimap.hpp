//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_UNORDERED_MULTIMAP_HPP)
#define CXXD_UNORDERED_MULTIMAP_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_UNORDERED_MAP) || defined(CXXD_UNORDERED_MULTIMAP_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_UNORDERED_MULTIMAP_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_UNORDERED_MAP)
#error CXXD: C++ standard unordered map is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for unordered map
#endif
#endif
#define CXXD_HAS_STD_UNORDERED_MULTIMAP 0
#define CXXD_UNORDERED_MULTIMAP_NS boost
#define CXXD_UNORDERED_MULTIMAP_HEADER <boost/unordered_map.hpp>
#else
#define CXXD_HAS_STD_UNORDERED_MULTIMAP 1
#define CXXD_UNORDERED_MULTIMAP_NS std
#define CXXD_UNORDERED_MULTIMAP_HEADER <unordered_map>
#endif

#endif // !defined(CXXD_UNORDERED_MULTIMAP_HPP)
