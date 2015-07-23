//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_CHRONO_HPP)
#define CXXD_CHRONO_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_CHRONO) || defined(CXXD_CHRONO_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_CHRONO_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_CHRONO)
#error CXXD: C++ standard chrono is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for chrono
#endif
#endif
#define CXXD_HAS_STD_CHRONO 0
#define CXXD_CHRONO_NS boost
#define CXXD_CHRONO_HEADER <boost/chrono.hpp>
#else
#define CXXD_HAS_STD_CHRONO 1
#define CXXD_CHRONO_NS std
#define CXXD_CHRONO_HEADER <chrono>
#endif

#endif // !defined(CXXD_CHRONO_HPP)
