//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_ARRAY_HPP)
#define CXXD_ARRAY_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_ARRAY) || defined(CXXD_ARRAY_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_ARRAY_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_ARRAY)
#error CXXD: C++ standard array is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for array
#endif
#endif
#define CXXD_HAS_STD_ARRAY 0
#define CXXD_ARRAY_NS boost
#define CXXD_ARRAY_HEADER <boost/array.hpp>
#else
#define CXXD_HAS_STD_ARRAY 1
#define CXXD_ARRAY_NS std
#define CXXD_ARRAY_HEADER <array>
#endif

#endif // !defined(CXXD_ARRAY_HPP)
