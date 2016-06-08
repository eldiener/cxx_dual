//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_MEM_FN_HPP)
#define CXXD_DETAIL_MEM_FN_HPP

#if CXXD_HAS_STD_MEM_FN

#define CXXD_MEM_FN_NS std
#include <functional>
namespace cxxd_mem_fn_ns = std ;

#else

#define CXXD_MEM_FN_NS boost
#include <boost/mem_fn.hpp>
namespace cxxd_mem_fn_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_MEM_FN_HPP)
