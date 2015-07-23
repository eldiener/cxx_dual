//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_SYSTEM_HPP)
#define CXXD_SYSTEM_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_SYSTEM_ERROR) || defined(CXXD_SYSTEM_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_SYSTEM_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_SYSTEM_ERROR)
#error CXXD: C++ standard system error is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for system error
#endif
#endif
#define CXXD_HAS_STD_SYSTEM 0
#define CXXD_SYSTEM_NS boost
#define CXXD_SYSTEM_HEADER <boost/system/system_error.hpp>
#else
#define CXXD_HAS_STD_SYSTEM 1
#define CXXD_SYSTEM_NS std
#define CXXD_SYSTEM_HEADER <system_error>
#endif

#endif // !defined(CXXD_SYSTEM_HPP)
