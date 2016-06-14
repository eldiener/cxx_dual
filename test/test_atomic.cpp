
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/atomic.hpp>
#include <boost/cxx_dual/impl/atomic.hpp>

/*

    This code replicates the Boost atomic spinlock example.

*/

class spinlock
    {
    private:
        typedef enum {Locked, Unlocked} LockState;
        cxxd_atomic_ns::atomic<LockState> state_;
    
    public:
        spinlock() : state_(Unlocked) {}
    
        void lock()
            {
            while (state_.exchange(Locked, cxxd_atomic_ns::memory_order_acquire) == Locked)
                {
                /* busy-wait */
                }
            }
        void unlock()
            {
            state_.store(Unlocked, cxxd_atomic_ns::memory_order_release);
            }
    };
        
int main()
    {
  
    spinlock s;

    s.lock();
    // access data structure here
    s.unlock();
    
    return 0;
    }
