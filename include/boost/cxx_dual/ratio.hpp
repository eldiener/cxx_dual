//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_RATIO_HPP)
#define CXXD_RATIO_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_RATIO) || defined(CXXD_RATIO_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_RATIO_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_RATIO)
#error CXXD: C++ standard ratio is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for ratio
#endif
#endif
#define CXXD_HAS_STD_RATIO 0
#define CXXD_RATIO_NS boost
#define CXXD_RATIO_HEADER <boost/ratio.hpp>
#else
#define CXXD_HAS_STD_RATIO 1
#define CXXD_RATIO_NS std
#define CXXD_RATIO_HEADER <ratio>
#endif

#endif // !defined(CXXD_RATIO_HPP)
