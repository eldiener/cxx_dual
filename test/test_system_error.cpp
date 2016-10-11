
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/system_error.hpp>
#include <boost/cxx_dual/thread.hpp>

int main()
  {
  
  try 
    {
        cxxd_thread_ns::thread().detach(); // attempt to detach a non-thread
    } 
  catch(const cxxd_system_error_ns::system_error& e) 
    {
        std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << '\n';
    }
    
  return boost::report_errors();
  }
