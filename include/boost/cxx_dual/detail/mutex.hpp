//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_MUTEX_HPP)
#define CXXD_DETAIL_MUTEX_HPP

#if CXXD_HAS_STD_MUTEX

#define CXXD_MUTEX_NS std
#include <mutex>
namespace cxxd_mutex_ns = std ;

#else

#define CXXD_MUTEX_NS boost
#include <boost/cxx_dual/detail/mutex_include.hpp>
namespace cxxd_mutex_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_MUTEX_HPP)
