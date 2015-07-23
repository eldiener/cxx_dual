//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_SHARED_MUTEX_HPP)
#define CXXD_SHARED_MUTEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX) || defined(CXXD_SHARED_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_SHARED_MUTEX_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX14_HDR_SHARED_MUTEX)
#error CXXD: C++ standard shared mutex is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for shared mutex
#endif
#endif
#define CXXD_HAS_STD_SHARED_MUTEX 0
#define CXXD_SHARED_MUTEX_NS boost
#define CXXD_SHARED_MUTEX_HEADER <boost/thread/shared_mutex.hpp>
#else
#define CXXD_HAS_STD_SHARED_MUTEX 1
#define CXXD_SHARED_MUTEX_NS std
#define CXXD_SHARED_MUTEX_HEADER <shared_mutex>
#endif

#endif // !defined(CXXD_SHARED_MUTEX_HPP)
