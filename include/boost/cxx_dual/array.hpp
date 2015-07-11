//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_ARRAY_HPP)
#define CXX_DUAL_ARRAY_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_ARRAY) || defined(CXX_DUAL_ARRAY_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_ARRAY_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_ARRAY)
#error CXX_DUAL: C++ standard array is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for array
#endif
#endif
#define CXX_DUAL_HAS_STD_ARRAY 0
#define CXX_DUAL_ARRAY_NS boost
#define CXX_DUAL_ARRAY_HEADER <boost/array.hpp>
#else
#define CXX_DUAL_HAS_STD_ARRAY 1
#define CXX_DUAL_ARRAY_NS std
#define CXX_DUAL_ARRAY_HEADER <array>
#endif

#endif // !defined(CXX_DUAL_ARRAY_HPP)
