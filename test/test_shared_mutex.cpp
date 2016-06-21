
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).


#include <iostream>
#include <boost/cxx_dual/shared_mutex.hpp>

#if !CXXD_HAS_STD_SHARED_MUTEX
#include <boost/thread/locks.hpp>
#define CXXD_MUTEX_USE_BOOST
#define CXXD_THREAD_USE_BOOST
#endif

#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/impl/shared_mutex.hpp>
#include <boost/cxx_dual/impl/mutex.hpp>
#include <boost/cxx_dual/impl/ref.hpp>
#include <boost/cxx_dual/impl/thread.hpp>

class ThreadSafeCounter {
 public:
  ThreadSafeCounter() : value_(0) {}
 
  // Multiple threads/readers can read the counter's value at the same time.
  unsigned int get() const {
    cxxd_shared_mutex_ns::shared_lock<cxxd_shared_mutex_ns::shared_timed_mutex> lock(mutex_);
    return value_;
  }
 
  // Only one thread/writer can increment/write the counter's value.
  void increment() {
    cxxd_mutex_ns::unique_lock<cxxd_shared_mutex_ns::shared_timed_mutex> lock(mutex_);
    value_++;
  }
 
  // Only one thread/writer can reset/write the counter's value.
  void reset() {
    cxxd_mutex_ns::unique_lock<cxxd_shared_mutex_ns::shared_timed_mutex> lock(mutex_);
    value_ = 0;
  }
 
 private:
  mutable cxxd_shared_mutex_ns::shared_timed_mutex mutex_;
  unsigned int value_;
};

void increment_and_print(ThreadSafeCounter & counter)
    {
    for (int i = 0; i < 3; i++) 
        {
        counter.increment();
        std::cout << cxxd_thread_ns::this_thread::get_id() << ' ' << counter.get() << '\n';
        // Note: Writing to std::cout actually needs to be synchronized as well
        // by another std::mutex. This has been omitted to keep the example small.
        }
    }

int main()
  {
  
  ThreadSafeCounter counter;
 
  cxxd_thread_ns::thread thread1(increment_and_print,cxxd_ref_ns::ref(counter));
  cxxd_thread_ns::thread thread2(increment_and_print,cxxd_ref_ns::ref(counter));
 
  thread1.join();
  thread2.join();
  
  return boost::report_errors();
  }
