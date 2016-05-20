
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <map>
#include <string>
#include <boost/cxx_dual/chrono.hpp>
#include <boost/cxx_dual/mutex.hpp>
#include <boost/cxx_dual/thread.hpp>

#if defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) || defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
#include <boost/foreach.hpp>
#endif

#include CXXD_CHRONO_HEADER
#include CXXD_MUTEX_HEADER
#include CXXD_THREAD_HEADER

std::map<std::string, std::string> g_pages;
CXXD_MUTEX_NS::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    CXXD_THREAD_NS::this_thread::sleep_for(CXXD_CHRONO_NS::seconds(2));
    std::string result = "fake content";
 
    CXXD_THREAD_NS::lock_guard<CXXD_MUTEX_NS::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}

int main()
    {
  
    CXXD_THREAD_NS::thread t1(save_page, "http://foo");
    CXXD_THREAD_NS::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();
 
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
 
    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) 
        {
        std::cout << pair.first << " => " << pair.second << '\n';
        }
        
#else

    typedef std::map<std::string, std::string>::value_type vt;

    BOOST_FOREACH(const vt& pair,g_pages)
        std::cout << pair.first << " => " << pair.second << '\n';
      
#endif
  
    return 0;
    }
