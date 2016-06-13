
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/make_shared.hpp>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_MAKE_SHARED_HEADER
#include CXXD_SHARED_PTR_ONLY_HEADER

void foo(const cxxd_shared_ptr_ns::shared_ptr<int>& i)
{
    (*i)++;
}

int main()
  {
  
  cxxd_shared_ptr_ns::shared_ptr<int> sp = cxxd_make_shared_ns::make_shared<int>(12);
  foo(sp);
  BOOST_TEST_EQ(*sp,13);
  
  return boost::report_errors();
  }
