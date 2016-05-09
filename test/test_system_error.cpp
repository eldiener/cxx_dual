
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/system_error.hpp>
#include <boost/cxx_dual/thread.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SYSTEM_ERROR_HEADER
#include CXXD_THREAD_HEADER

int main()
  {
  
  try 
    {
        CXXD_THREAD_NS::thread().detach(); // attempt to detach a non-thread
    } 
  catch(const CXXD_SYSTEM_ERROR_NS::system_error& e) 
    {
        std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << '\n';
    }
    
  return boost::report_errors();
  }
