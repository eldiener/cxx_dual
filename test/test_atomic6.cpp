
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/atomic.hpp>

#if !CXXD_HAS_STD_ATOMIC && defined(BOOST_ATOMIC_NO_ATOMIC_FLAG_INIT)

cxxd_atomic_ns::atomic_flag static_flag;

#else

cxxd_atomic_ns::atomic_flag static_flag = CXXD_ATOMIC_MACRO(ATOMIC_FLAG_INIT); // static initialization,
// guaranteed to be available during dynamic initialization of static objects.

#endif

int main()
    {
    
#if !CXXD_HAS_STD_ATOMIC && defined(BOOST_ATOMIC_NO_ATOMIC_FLAG_INIT)

    cxxd_atomic_ns::atomic_flag automatic_flag;
    
#else

    cxxd_atomic_ns::atomic_flag automatic_flag = CXXD_ATOMIC_MACRO(ATOMIC_FLAG_INIT); // guaranteed to work
    
#endif
 
    return 0;
    }
