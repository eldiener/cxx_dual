//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_ENABLE_SHARED_FROM_THIS_HPP)
#define CXXD_IMPL_ENABLE_SHARED_FROM_THIS_HPP

#if !defined(CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS)
#include <boost/cxx_dual/enable_shared_from_this.hpp>
#endif

#if CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS

#define CXXD_ENABLE_SHARED_FROM_THIS_NS std
#include <memory>
namespace cxxd_enable_shared_from_this_ns = std ;

#else

#define CXXD_ENABLE_SHARED_FROM_THIS_NS boost
#include <boost/enable_shared_from_this.hpp>
namespace cxxd_enable_shared_from_this_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_ENABLE_SHARED_FROM_THIS_HPP)
