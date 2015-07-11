//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_SHARED_MUTEX_HPP)
#define CXX_DUAL_SHARED_MUTEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX) || defined(CXX_DUAL_SHARED_MUTEX_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_SHARED_MUTEX_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX)
#error CXX_DUAL: C++ standard shared mutex is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for shared mutex
#endif
#endif
#define CXX_DUAL_HAS_STD_SHARED_MUTEX 0
#define CXX_DUAL_SHARED_MUTEX_NS boost
#define CXX_DUAL_SHARED_MUTEX_HEADER <boost/thread/shared_mutex.hpp>
#else
#define CXX_DUAL_HAS_STD_SHARED_MUTEX 1
#define CXX_DUAL_SHARED_MUTEX_NS std
#define CXX_DUAL_SHARED_MUTEX_HEADER <shared_mutex>
#endif

#endif // !defined(CXX_DUAL_SHARED_MUTEX_HPP)
