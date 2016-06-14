//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_RANDOM_HPP)
#define CXXD_IMPL_RANDOM_HPP

#if !defined(CXXD_HAS_STD_RANDOM)
#include <boost/cxx_dual/random.hpp>
#endif

#if CXXD_HAS_STD_RANDOM

#define CXXD_RANDOM_NS std
#include <random>
namespace cxxd_random_ns = std ;

#else

#define CXXD_RANDOM_NS boost::random
#include <boost/random.hpp>
namespace cxxd_random_ns = boost::random ;

#endif

#endif // !defined(CXXD_IMPL_RANDOM_HPP)
