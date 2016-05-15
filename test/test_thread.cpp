
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/chrono.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/cxx_dual/thread.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_CHRONO_HEADER
#include CXXD_REF_HEADER
#include CXXD_THREAD_HEADER

void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1 executing\n";
        ++n;
        CXXD_THREAD_NS::this_thread::sleep_for(CXXD_CHRONO_NS::milliseconds(10));
    }
}
 
void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing\n";
        ++n;
        CXXD_THREAD_NS::this_thread::sleep_for(CXXD_CHRONO_NS::milliseconds(10));
    }
}

int main()
    {
  
    int n = 0;
    CXXD_THREAD_NS::thread t1; // t1 is not a thread
    CXXD_THREAD_NS::thread t2(f1, n + 1); // pass by value
    CXXD_THREAD_NS::thread t3(f2, CXXD_REF_NS::ref(n)); // pass by reference
//    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    t2.join();
    t3.join();
//    t4.join();
    std::cout << "Final value of n is " << n << '\n';
  
    return boost::report_errors();
    }
