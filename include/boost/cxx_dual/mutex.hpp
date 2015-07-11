//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_MUTEX_HPP)
#define CXX_DUAL_MUTEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_MUTEX) || defined(CXX_DUAL_MUTEX_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_MUTEX_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_MUTEX)
#error CXX_DUAL: C++ standard mutex is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for mutex
#endif
#endif
#define CXX_DUAL_HAS_STD_MUTEX 0
#define CXX_DUAL_MUTEX_NS boost
#define CXX_DUAL_MUTEX_HEADER <boost/thread/mutex.hpp>
#else
#define CXX_DUAL_HAS_STD_MUTEX 1
#define CXX_DUAL_MUTEX_NS std
#define CXX_DUAL_MUTEX_HEADER <mutex>
#endif

#endif // !defined(CXX_DUAL_MUTEX_HPP)
