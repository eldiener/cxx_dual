
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/shared_ptr_all.hpp>

void foo(const cxxd_shared_ptr_ns::shared_ptr<int>& i)
{
    (*i)++;
}

int main()
  {
  
  cxxd_shared_ptr_ns::shared_ptr<int> sp = cxxd_shared_ptr_ns::make_shared<int>(22);
  foo(sp);
  BOOST_TEST_EQ(*sp,23);
  
  return boost::report_errors();
  }
