//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_TYPE_TRAITS_HPP)
#define CXXD_TYPE_TRAITS_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || defined(CXXD_TYPE_TRAITS_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_TYPE_TRAITS_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#error CXXD: C++ standard type traits is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for type traits
#endif
#endif
#define CXXD_HAS_STD_TYPE_TRAITS 0
#define CXXD_TYPE_TRAITS_NS boost
#define CXXD_TYPE_TRAITS_HEADER <boost/type_traits.hpp>
#else
#define CXXD_HAS_STD_TYPE_TRAITS 1
#define CXXD_TYPE_TRAITS_NS std
#define CXXD_TYPE_TRAITS_HEADER <type_traits>
#endif

#endif // !defined(CXXD_TYPE_TRAITS_HPP)
