
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
cxxd_mutex_ns::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    cxxd_thread_ns::this_thread::sleep_for(cxxd_chrono_ns::seconds(2));
    std::string result = "fake content";
 
    cxxd_thread_ns::lock_guard<cxxd_mutex_ns::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}

int main()
    {
  
    cxxd_thread_ns::thread t1(save_page, "http://foo");
    cxxd_thread_ns::thread t2(save_page, "http://bar");
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
