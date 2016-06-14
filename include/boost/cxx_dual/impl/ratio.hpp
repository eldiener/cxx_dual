//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_RATIO_HPP)
#define CXXD_IMPL_RATIO_HPP

#if !defined(CXXD_HAS_STD_RATIO)
#include <boost/cxx_dual/ratio.hpp>
#endif

#if CXXD_HAS_STD_RATIO

#define CXXD_RATIO_NS std
#include <ratio>
namespace cxxd_ratio_ns = std ;

#else

#define CXXD_RATIO_NS boost
#include <boost/ratio.hpp>
namespace cxxd_ratio_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_RATIO_HPP)
