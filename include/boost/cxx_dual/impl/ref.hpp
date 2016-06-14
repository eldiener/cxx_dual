//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_REF)
#include <boost/cxx_dual/ref.hpp>
#endif

#if CXXD_HAS_STD_REF

#define CXXD_REF_NS std
#include <functional>
namespace cxxd_ref_ns = std ;

#else

#define CXXD_REF_NS boost
#include <boost/core/ref.hpp>
namespace cxxd_ref_ns = boost ;

#endif
