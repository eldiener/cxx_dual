//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_RANDOM_HPP)
#define CXXD_RANDOM_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_RANDOM) || defined(CXXD_RANDOM_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_RANDOM_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_RANDOM)
#error CXXD: C++ standard random is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for random
#endif
#endif
#define CXXD_HAS_STD_RANDOM 0
#define CXXD_RANDOM_NS boost::random
#define CXXD_RANDOM_HEADER <boost/random.hpp>
#else
#define CXXD_HAS_STD_RANDOM 1
#define CXXD_RANDOM_NS std
#define CXXD_RANDOM_HEADER <random>
#endif

#endif // !defined(CXXD_RANDOM_HPP)
