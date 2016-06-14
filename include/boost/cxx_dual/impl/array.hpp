//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_ARRAY_HPP)
#define CXXD_IMPL_ARRAY_HPP

#if !defined(CXXD_HAS_STD_ARRAY)
#include <boost/cxx_dual/array.hpp>
#endif

#if CXXD_HAS_STD_ARRAY

#define CXXD_ARRAY_NS std
#include <array>
namespace cxxd_array_ns = std ;

#else

#define CXXD_ARRAY_NS boost
#include <boost/array.hpp>
namespace cxxd_array_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_ARRAY_HPP)
