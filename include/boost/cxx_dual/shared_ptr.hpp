//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_SHARED_PTR_HPP)
#define CXX_DUAL_SHARED_PTR_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_SMART_PTR) || defined(CXX_DUAL_SHARED_PTR_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_SHARED_PTR_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_SMART_PTR)
#error CXX_DUAL: C++ standard shared pointer is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for shared pointer
#endif
#endif
#define CXX_DUAL_HAS_STD_SHARED_PTR 0
#define CXX_DUAL_SHARED_PTR_NS boost
#define CXX_DUAL_SHARED_PTR_HEADER <boost/shared_ptr.hpp>
#else
#define CXX_DUAL_HAS_STD_SHARED_PTR 1
#define CXX_DUAL_SHARED_PTR_NS std
#define CXX_DUAL_SHARED_PTR_HEADER <memory>
#endif

#endif // !defined(CXX_DUAL_SHARED_PTR_HPP)
