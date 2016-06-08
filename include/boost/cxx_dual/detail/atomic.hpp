//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_ATOMIC_HPP)
#define CXXD_DETAIL_ATOMIC_HPP

#if CXXD_HAS_STD_ATOMIC

#define CXXD_ATOMIC_NS std
#include <atomic>
namespace cxxd_atomic_ns = std ;

#else

#define CXXD_ATOMIC_NS boost
#include <boost/atomic/atomic.hpp>
namespace cxxd_atomic_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_ATOMIC_HPP)
