//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_DUAL_ATOMIC_HPP)
#define CXX_DUAL_ATOMIC_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_ATOMIC) || defined(CXX_DUAL_ATOMIC_USE_BOOST) || defined(CXX_DUAL_USE_BOOST)
#if defined(CXX_DUAL_ATOMIC_USE_STD) || defined(CXX_DUAL_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_ATOMIC)
#error CXX_DUAL: C++ standard atomic is not available
#else
#error CXX_DUAL: Using C++ standard and using Boost are both defined for atomic
#endif
#endif
#define CXX_DUAL_HAS_STD_ATOMIC 0
#define CXX_DUAL_ATOMIC_NS boost
#define CXX_DUAL_ATOMIC_HEADER <boost/atomic/atomic.hpp>
#define CXX_DUAL_ATOMIC_MACRO(macro) BOOST_ ## macro
#else
#define CXX_DUAL_HAS_STD_ATOMIC 1
#define CXX_DUAL_ATOMIC_NS std
#define CXX_DUAL_ATOMIC_HEADER <atomic>
#define CXX_DUAL_ATOMIC_MACRO(macro) macro
#endif

#endif // !defined(CXX_DUAL_ATOMIC_HPP)
