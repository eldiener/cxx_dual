
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/atomic.hpp>
#include CXXD_ATOMIC_HEADER

/*

    This code replicates the Boost atomic spinlock example.

*/

class spinlock
    {
    private:
        typedef enum {Locked, Unlocked} LockState;
        CXXD_ATOMIC_NS::atomic<LockState> state_;
    
    public:
        spinlock() : state_(Unlocked) {}
    
        void lock()
            {
            while (state_.exchange(Locked, CXXD_ATOMIC_NS::memory_order_acquire) == Locked)
                {
                /* busy-wait */
                }
            }
        void unlock()
            {
            state_.store(Unlocked, CXXD_ATOMIC_NS::memory_order_release);
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
