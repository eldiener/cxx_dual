//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TYPE_TRAITS_HPP)
#define CXXD_DETAIL_TYPE_TRAITS_HPP

#if CXXD_HAS_STD_TYPE_TRAITS

#define CXXD_TYPE_TRAITS_NS std
#include <type_traits>
namespace cxxd_type_traits_ns = std ;

#else

#define CXXD_TYPE_TRAITS_NS boost
#include <boost/type_traits.hpp>
namespace cxxd_type_traits_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_TYPE_TRAITS_HPP)
