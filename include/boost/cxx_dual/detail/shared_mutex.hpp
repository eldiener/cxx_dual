//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_SHARED_MUTEX_HPP)
#define CXXD_DETAIL_SHARED_MUTEX_HPP

#if CXXD_HAS_STD_SHARED_MUTEX

#define CXXD_SHARED_MUTEX_NS std
#include <shared_mutex>
namespace cxxd_shared_mutex_ns = std ;

#else

#define CXXD_SHARED_MUTEX_NS boost
#include <boost/thread/shared_mutex.hpp>
namespace cxxd_shared_mutex_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_SHARED_MUTEX_HPP)
