//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_SHARED_MUTEX_HPP)
#define CXXD_IMPL_SHARED_MUTEX_HPP

#if !defined(CXXD_HAS_STD_SHARED_MUTEX)
#include <boost/cxx_dual/shared_mutex.hpp>
#endif

#include CXXD_SHARED_MUTEX_HEADER
namespace cxxd_shared_mutex_ns = CXXD_SHARED_MUTEX_NS ;

#endif // !defined(CXXD_IMPL_SHARED_MUTEX_HPP)
