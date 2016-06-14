//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_TUPLE_HPP)
#define CXXD_IMPL_TUPLE_HPP

#if !defined(CXXD_HAS_STD_TUPLE)
#include <boost/cxx_dual/tuple.hpp>
#endif

#if CXXD_HAS_STD_TUPLE

#define CXXD_TUPLE_NS std
#include <tuple>
namespace cxxd_tuple_ns = std ;

#else

#define CXXD_TUPLE_NS boost::tuples
#include <boost/tuple/tuple.hpp>
namespace cxxd_tuple_ns = boost::tuples ;

#endif

#endif // !defined(CXXD_IMPL_TUPLE_HPP)
