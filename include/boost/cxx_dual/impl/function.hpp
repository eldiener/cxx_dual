//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_FUNCTION)
#include <boost/cxx_dual/function.hpp>
#endif

#if CXXD_HAS_STD_FUNCTION

#define CXXD_FUNCTION_NS std
#include <functional>
namespace cxxd_function_ns = std ;

#else

#define CXXD_FUNCTION_NS boost
#include <boost/function.hpp>
namespace cxxd_function_ns = boost ;

#endif
