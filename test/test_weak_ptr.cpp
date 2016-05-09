
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/cxx_dual/weak_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SHARED_PTR_ONLY_HEADER
#include CXXD_WEAK_PTR_HEADER

CXXD_WEAK_PTR_NS::weak_ptr<int> gw;
 
void f()
{
    if (CXXD_SHARED_PTR_NS::shared_ptr<int> spt = gw.lock())
        { // Has to be copied into a shared_ptr before usage
        std::cout << *spt << "\n";
        }
    else 
        {
        std::cout << "gw is expired\n";
        }
}

int main()
  {
  
    {
    CXXD_SHARED_PTR_NS::shared_ptr<int> sp(new int(42));
	gw = sp;
	f();
    }
  f();
  return boost::report_errors();
  }
