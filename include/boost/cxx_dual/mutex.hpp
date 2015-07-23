//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_MUTEX_HPP)
#define CXXD_MUTEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_MUTEX) || defined(CXXD_MUTEX_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_MUTEX_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_MUTEX)
#error CXXD: C++ standard mutex is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for mutex
#endif
#endif
#define CXXD_HAS_STD_MUTEX 0
#define CXXD_MUTEX_NS boost
#define CXXD_MUTEX_HEADER <boost/thread/mutex.hpp>
#else
#define CXXD_HAS_STD_MUTEX 1
#define CXXD_MUTEX_NS std
#define CXXD_MUTEX_HEADER <mutex>
#endif

#endif // !defined(CXXD_MUTEX_HPP)
