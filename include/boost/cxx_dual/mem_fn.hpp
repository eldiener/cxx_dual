//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_MEM_FN_HPP)
#define CXXD_MEM_FN_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_MEM_FN_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_MEM_FN_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#error CXXD: C++ standard mem_fn is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for mem_fn
#endif
#endif
#define CXXD_HAS_STD_MEM_FN 0
#define CXXD_MEM_FN_NS boost
#define CXXD_MEM_FN_HEADER <boost/mem_fn.hpp>
#else
#define CXXD_HAS_STD_MEM_FN 1
#define CXXD_MEM_FN_NS std
#define CXXD_MEM_FN_HEADER <functional>
#endif

#endif // !defined(CXXD_MEM_FN_HPP)
