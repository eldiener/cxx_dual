//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_REF_HPP)
#define CXXD_REF_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) || defined(CXXD_REF_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_REF_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#error CXXD: C++ standard ref is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for ref
#endif
#endif
#define CXXD_HAS_STD_REF 0
#define CXXD_REF_NS boost
#define CXXD_REF_HEADER <boost/core/ref.hpp>
#else
#define CXXD_HAS_STD_REF 1
#define CXXD_REF_NS std
#define CXXD_REF_HEADER <functional>
#endif

#endif // !defined(CXXD_REF_HPP)
