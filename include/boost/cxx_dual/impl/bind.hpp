//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_BIND_HPP)
#define CXXD_IMPL_BIND_HPP

#if !defined(CXXD_HAS_STD_BIND)
#include <boost/cxx_dual/bind.hpp>
#endif

#if CXXD_HAS_STD_BIND

#define CXXD_BIND_NS std
#include <functional>
namespace cxxd_bind_ns = std ;

#else

#define CXXD_BIND_NS boost
#include <boost/bind/bind.hpp>
namespace cxxd_bind_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_BIND_HPP)
