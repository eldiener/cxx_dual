
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/atomic.hpp>
#include CXXD_ATOMIC_HEADER

/*

    This code replicates the Boost wait-free multi-producer queue example with a few corrections.

*/

template<typename T>
class waitfree_queue {
public:
  struct node {
    T data;
    node * next;
  };
  void push(const T &data)
  {
    node * n = new node;
    n->data = data;
    node * stale_head = head_.load(CXXD_ATOMIC_NS::memory_order_relaxed);
    do {
      n->next = stale_head;
    } while (!head_.compare_exchange_weak(stale_head, n, CXXD_ATOMIC_NS::memory_order_release));
  }

  node * pop_all(void)
  {
    node * last = pop_all_reverse(), * first = 0;
    while(last) {
      node * tmp = last;
      last = last->next;
      tmp->next = first;
      first = tmp;
    }
    return first;
  }

  waitfree_queue() : head_(0) {}

  // alternative interface if ordering is of no importance
  node * pop_all_reverse(void)
  {
    return head_.exchange(0, CXXD_ATOMIC_NS::memory_order_consume);
  }
private:
  CXXD_ATOMIC_NS::atomic<node *> head_;
};

int main()
    {
    
    waitfree_queue<int> q;

    // insert elements
    q.push(42);
    q.push(2);

    // pop elements
    waitfree_queue<int>::node * x = q.pop_all();
    while(x) 
        {
        waitfree_queue<int>::node * tmp = x;
        x = x->next;
        // process tmp->data, probably delete it afterwards
        delete tmp;
        } 
    
    }
