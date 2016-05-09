
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SHARED_PTR_HEADER

void foo(const CXXD_SHARED_PTR_NS::shared_ptr<int>& i)
{
    (*i)++;
}

int main()
  {
  
  CXXD_SHARED_PTR_NS::shared_ptr<int> sp = CXXD_SHARED_PTR_NS::make_shared<int>(12);
  foo(sp);
  std::cout << *sp << std::endl;
  
  return boost::report_errors();
  }
