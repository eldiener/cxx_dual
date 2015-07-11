//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_CHRONO_HPP)
#define CXX_DUAL_CHRONO_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_CHRONO) || defined(CXX_DUAL_CHRONO_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_CHRONO_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_CHRONO)
#error CXX_DUAL: C++ standard chrono is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for chrono
#endif
#endif
#define CXX_DUAL_HAS_STD_CHRONO 0
#define CXX_DUAL_CHRONO_NS boost
#define CXX_DUAL_CHRONO_HEADER <boost/chrono.hpp>
#else
#define CXX_DUAL_HAS_STD_CHRONO 1
#define CXX_DUAL_CHRONO_NS std
#define CXX_DUAL_CHRONO_HEADER <chrono>
#endif

#endif // !defined(CXX_DUAL_CHRONO_HPP)
