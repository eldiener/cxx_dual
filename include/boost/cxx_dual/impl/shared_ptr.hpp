//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_SHARED_PTR_HPP)
#define CXXD_IMPL_SHARED_PTR_HPP

#if !defined(CXXD_HAS_STD_SHARED_PTR)
#include <boost/cxx_dual/shared_ptr.hpp>
#endif

#if CXXD_HAS_STD_SHARED_PTR

#define CXXD_SHARED_PTR_NS std
#include <memory>
namespace cxxd_shared_ptr_ns = std ;

#else

#define CXXD_SHARED_PTR_NS boost
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>
namespace cxxd_shared_ptr_ns = boost ;

#endif

#endif // !defined(CXXD_IMPL_SHARED_PTR_HPP)
