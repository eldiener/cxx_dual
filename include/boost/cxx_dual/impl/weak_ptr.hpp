//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_WEAK_PTR)
#include <boost/cxx_dual/weak_ptr.hpp>
#endif

#if CXXD_HAS_STD_WEAK_PTR

#define CXXD_WEAK_PTR_NS std
#include <memory>
namespace cxxd_weak_ptr_ns = std ;

#else

#define CXXD_WEAK_PTR_NS boost
#include <boost/weak_ptr.hpp>
namespace cxxd_weak_ptr_ns = boost ;

#endif
