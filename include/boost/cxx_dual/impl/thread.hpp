//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_THREAD)
#include <boost/cxx_dual/thread.hpp>
#endif

#if CXXD_HAS_STD_THREAD

#define CXXD_THREAD_NS std
#include <thread>
namespace cxxd_thread_ns = std ;

#else

#define CXXD_THREAD_NS boost
#include <boost/thread/thread.hpp>
namespace cxxd_thread_ns = boost ;

#endif
