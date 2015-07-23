//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_BIND_HPP)
#define CXXD_BIND_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_BIND_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_BIND_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#error CXXD: C++ standard bind is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for bind
#endif
#endif
#define CXXD_HAS_STD_BIND 0
#define CXXD_BIND_NS boost
#define CXXD_BIND_HEADER <boost/bind/bind.hpp>
#else
#define CXXD_HAS_STD_BIND 1
#define CXXD_BIND_NS std
#define CXXD_BIND_HEADER <functional>
#endif

#endif // !defined(CXXD_BIND_HPP)
