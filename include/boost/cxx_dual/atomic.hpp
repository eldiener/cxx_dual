//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_ATOMIC_HPP)
#define CXXD_ATOMIC_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_ATOMIC) || defined(CXXD_ATOMIC_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_ATOMIC_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_ATOMIC)
#error CXXD: C++ standard atomic is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for atomic
#endif
#endif
#define CXXD_HAS_STD_ATOMIC 0
#define CXXD_ATOMIC_NS boost
#define CXXD_ATOMIC_HEADER <boost/atomic/atomic.hpp>
#define CXXD_ATOMIC_MACRO(macro) BOOST_ ## macro
#else
#define CXXD_HAS_STD_ATOMIC 1
#define CXXD_ATOMIC_NS std
#define CXXD_ATOMIC_HEADER <atomic>
#define CXXD_ATOMIC_MACRO(macro) macro
#endif

#endif // !defined(CXXD_ATOMIC_HPP)
