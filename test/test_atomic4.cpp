
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/atomic.hpp>
#include CXXD_ATOMIC_HEADER

template<typename T>
struct node
{
    T data;
    node* next;
    node(const T& data) : data(data), next(0) {}
};
 
template<typename T>
class stack
{
    CXXD_ATOMIC_NS::atomic<node<T>*> head;
 public:
    void push(const T& data)
    {
        node<T>* new_node = new node<T>(data);
 
      // put the current value of head into new_node->next
      new_node->next = head.load(CXXD_ATOMIC_NS::memory_order_relaxed);
 
      // now make new_node the new head, but if the head
      // is no longer what's stored in new_node->next
      // (some other thread must have inserted a node just now)
      // then put that new head into new_node->next and try again
      while(!head.compare_exchange_weak(new_node->next, new_node,
                                        CXXD_ATOMIC_NS::memory_order_release,
                                        CXXD_ATOMIC_NS::memory_order_relaxed))
          ; // the body of the loop is empty
 
// Note: the above use is not thread-safe in at least 
// GCC prior to 4.8.3 (bug 60272), clang prior to 2014-05-05 (bug 18899)
// MSVC prior to 2014-03-17 (bug 819819). The following is a workaround:
//      node<T>* old_head = head.load(CXXD_ATOMIC_NS::memory_order_relaxed);
//      do {
//          new_node->next = old_head;
//       } while(!head.compare_exchange_weak(old_head, new_node,
//                                           CXXD_ATOMIC_NS::memory_order_release,
//                                           CXXD_ATOMIC_NS::memory_order_relaxed));
    }
};

int main()
    {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    }
