//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_MAKE_SHARED)
#include <boost/cxx_dual/make_shared.hpp>
#endif

#if CXXD_HAS_STD_MAKE_SHARED

#define CXXD_MAKE_SHARED_NS std
#include <memory>
namespace cxxd_make_shared_ns = std ;

#else

#define CXXD_MAKE_SHARED_NS boost
#include <boost/make_shared.hpp>
namespace cxxd_make_shared_ns = boost ;

#endif
