//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_CHRONO)
#include <boost/cxx_dual/chrono.hpp>
#endif

#if CXXD_HAS_STD_CHRONO

#define CXXD_CHRONO_NS std::chrono
#include <chrono>
namespace cxxd_chrono_ns = std::chrono ;

#else

#define CXXD_CHRONO_NS boost::chrono
#include <boost/chrono.hpp>
namespace cxxd_chrono_ns = boost::chrono ;

#endif
