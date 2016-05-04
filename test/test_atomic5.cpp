
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/atomic.hpp>
#include CXXD_ATOMIC_HEADER

CXXD_ATOMIC_NS::atomic<int>  ai;
 
int  tst_val= 4;
int  new_val= 5;
bool exchanged= false;
 
void valsout()
{
    std::cout << "ai= " << ai
	      << "  tst_val= " << tst_val
	      << "  new_val= " << new_val
	      << "  exchanged= " << std::boolalpha << exchanged
	      << "\n";
}

int main()
    {
    
    ai= 3;
    valsout();
 
    // tst_val != ai   ==>  tst_val is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();
 
    // tst_val == ai   ==>  ai is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();
 
    return 0;
    
    }
