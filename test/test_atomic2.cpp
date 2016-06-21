
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/impl/atomic.hpp>

/*

    This code replicates the Boost wait-free ring buffer example.

*/

template<typename T, size_t Size>
class ringbuffer {
public:
  ringbuffer() : head_(0), tail_(0) {}

  bool push(const T & value)
  {
    size_t head = head_.load(cxxd_atomic_ns::memory_order_relaxed);
    size_t next_head = next(head);
    if (next_head == tail_.load(cxxd_atomic_ns::memory_order_acquire))
      return false;
    ring_[head] = value;
    head_.store(next_head, cxxd_atomic_ns::memory_order_release);
    return true;
  }
  bool pop(T & value)
  {
    size_t tail = tail_.load(cxxd_atomic_ns::memory_order_relaxed);
    if (tail == head_.load(cxxd_atomic_ns::memory_order_acquire))
      return false;
    value = ring_[tail];
    tail_.store(next(tail), cxxd_atomic_ns::memory_order_release);
    return true;
  }
private:
  size_t next(size_t current)
  {
    return (current + 1) % Size;
  }
  T ring_[Size];
  cxxd_atomic_ns::atomic<size_t> head_, tail_;
};

int main()
    {
    
    ringbuffer<int, 32> r;

    // try to insert an element
    if (r.push(42)) { /* succeeded */ }
    else { /* buffer full */ }

    // try to retrieve an element
    int value;
    if (r.pop(value)) { /* succeeded */ }
    else { /* buffer empty */ }
    
    return 0;
    }
