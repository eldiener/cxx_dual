
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/atomic.hpp>

cxxd_atomic_ns::atomic<int>  ai;
 
int  tst_val= 4;
int  new_val= 5;
 
int main()
    {
    
    ai = 3;
 
    // tst_val != ai   ==>  tst_val is modified
    ai.compare_exchange_strong( tst_val, new_val );
    BOOST_TEST_EQ(ai,tst_val);
 
    // tst_val == ai   ==>  ai is modified
    ai.compare_exchange_strong( tst_val, new_val );
    BOOST_TEST_EQ(ai,new_val);
 
    return boost::report_errors();
    }
