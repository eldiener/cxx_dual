//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_SHARED_PTR_HPP)
#define CXXD_SHARED_PTR_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_SMART_PTR) || defined(CXXD_SHARED_PTR_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_SHARED_PTR_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_SMART_PTR)
#error CXXD: C++ standard shared pointer is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for shared pointer
#endif
#endif
#define CXXD_HAS_STD_SHARED_PTR 0
#define CXXD_SHARED_PTR_NS boost
#define CXXD_SHARED_PTR_HEADER <boost/shared_ptr.hpp>
#else
#define CXXD_HAS_STD_SHARED_PTR 1
#define CXXD_SHARED_PTR_NS std
#define CXXD_SHARED_PTR_HEADER <memory>
#endif

#endif // !defined(CXXD_SHARED_PTR_HPP)
