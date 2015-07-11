//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_TUPLE_HPP)
#define CXX_DUAL_TUPLE_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_TUPLE) || defined(CXX_DUAL_TUPLE_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_TUPLE_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_TUPLE)
#error CXX_DUAL: C++ standard tuple is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for tuple
#endif
#endif
#define CXX_DUAL_HAS_STD_TUPLE 0
#define CXX_DUAL_TUPLE_NS boost
#define CXX_DUAL_TUPLE_HEADER <boost/tuple/tuple.hpp>
#else
#define CXX_DUAL_HAS_STD_TUPLE 1
#define CXX_DUAL_TUPLE_NS std
#define CXX_DUAL_TUPLE_HEADER <tuple>
#endif

#endif // !defined(CXX_DUAL_TUPLE_HPP)
