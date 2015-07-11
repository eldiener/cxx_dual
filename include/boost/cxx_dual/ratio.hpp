//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_RATIO_HPP)
#define CXX_DUAL_RATIO_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_RATIO) || defined(CXX_DUAL_RATIO_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_RATIO_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_RATIO)
#error CXX_DUAL: C++ standard ratio is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for ratio
#endif
#endif
#define CXX_DUAL_HAS_STD_RATIO 0
#define CXX_DUAL_RATIO_NS boost
#define CXX_DUAL_RATIO_HEADER <boost/ratio.hpp>
#else
#define CXX_DUAL_HAS_STD_RATIO 1
#define CXX_DUAL_RATIO_NS std
#define CXX_DUAL_RATIO_HEADER <ratio>
#endif

#endif // !defined(CXX_DUAL_RATIO_HPP)
