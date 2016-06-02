
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

#include <boost/cxx_dual/mutex.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/cxx_dual/thread.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SHARED_MUTEX_HEADER
#include CXXD_MUTEX_HEADER
#include CXXD_REF_HEADER
#include CXXD_THREAD_HEADER

class ThreadSafeCounter {
 public:
  ThreadSafeCounter() : value_(0) {}
 
  // Multiple threads/readers can read the counter's value at the same time.
  unsigned int get() const {
    CXXD_SHARED_MUTEX_NS::shared_lock<CXXD_SHARED_MUTEX_NS::shared_timed_mutex> lock(mutex_);
    return value_;
  }
 
  // Only one thread/writer can increment/write the counter's value.
  void increment() {
    CXXD_MUTEX_NS::unique_lock<CXXD_SHARED_MUTEX_NS::shared_timed_mutex> lock(mutex_);
    value_++;
  }
 
  // Only one thread/writer can reset/write the counter's value.
  void reset() {
    CXXD_MUTEX_NS::unique_lock<CXXD_SHARED_MUTEX_NS::shared_timed_mutex> lock(mutex_);
    value_ = 0;
  }
 
 private:
  mutable CXXD_SHARED_MUTEX_NS::shared_timed_mutex mutex_;
  unsigned int value_;
};

void increment_and_print(ThreadSafeCounter & counter)
    {
    for (int i = 0; i < 3; i++) 
        {
        counter.increment();
        std::cout << CXXD_THREAD_NS::this_thread::get_id() << ' ' << counter.get() << '\n';
        // Note: Writing to std::cout actually needs to be synchronized as well
        // by another std::mutex. This has been omitted to keep the example small.
        }
    }

int main()
  {
  
  ThreadSafeCounter counter;
 
  CXXD_THREAD_NS::thread thread1(increment_and_print,CXXD_REF_NS::ref(counter));
  CXXD_THREAD_NS::thread thread2(increment_and_print,CXXD_REF_NS::ref(counter));
 
  thread1.join();
  thread2.join();
  
  return boost::report_errors();
  }
