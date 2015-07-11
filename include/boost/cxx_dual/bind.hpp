//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_BIND_HPP)
#define CXX_DUAL_BIND_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXX_DUAL_BIND_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_BIND_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#error CXX_DUAL: C++ standard bind is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for bind
#endif
#endif
#define CXX_DUAL_HAS_STD_BIND 0
#define CXX_DUAL_BIND_NS boost
#define CXX_DUAL_BIND_HEADER <boost/bind/bind.hpp>
#else
#define CXX_DUAL_HAS_STD_BIND 1
#define CXX_DUAL_BIND_NS std
#define CXX_DUAL_BIND_HEADER <functional>
#endif

#endif // !defined(CXX_DUAL_BIND_HPP)
