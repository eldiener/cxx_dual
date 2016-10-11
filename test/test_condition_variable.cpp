
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <string>
#include <boost/config.hpp>
 
#include <boost/cxx_dual/thread.hpp>
#include <boost/cxx_dual/mutex.hpp>
#include <boost/cxx_dual/condition_variable.hpp>

cxxd_mutex_ns::mutex m;
cxxd_condition_variable_ns::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;
 
#if defined(BOOST_NO_CXX11_LAMBDAS)

bool ReturnReady() {return ready;}
bool ReturnProcessed() {return processed;};
        
#endif
        
void worker_thread()
{
    // Wait until main() sends data
    cxxd_thread_ns::unique_lock<cxxd_mutex_ns::mutex> lk(m);
    
    #if defined(BOOST_NO_CXX11_LAMBDAS)
    
    cv.wait(lk, ReturnReady);
    
    #else
    
    cv.wait(lk, []{return ready;});
 
    #endif
    
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
 
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main()
  {
  
    cxxd_thread_ns::thread worker(worker_thread);
 
    data = "Example data";
    // send data to the worker thread
    {
        cxxd_thread_ns::lock_guard<cxxd_mutex_ns::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        cxxd_thread_ns::unique_lock<cxxd_mutex_ns::mutex> lk(m);
        
        #if defined(BOOST_NO_CXX11_LAMBDAS)
        
        cv.wait(lk, ReturnProcessed);
        
        #else
        
        cv.wait(lk, []{return processed;});
        
        #endif  
        
    }
    std::cout << "Back in main(), data = " << data << '\n';
 
    worker.join();
    
    return 0;
  }
