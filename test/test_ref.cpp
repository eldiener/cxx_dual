
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/bind.hpp>
#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/impl/bind.hpp>
#include <boost/cxx_dual/impl/function.hpp>
#include <boost/cxx_dual/impl/ref.hpp>

void f(int& n1, int& n2, const int& n3)
{
  BOOST_TEST_EQ(n1,1);
  BOOST_TEST_EQ(n2,11);
  BOOST_TEST_EQ(n3,12);
    ++n1; // increments the copy of n1 stored in the function object
    ++n2; // increments the main()'s n2
    // ++n3; // compile error
}

int main()
  {
  
  int n1 = 1, n2 = 2, n3 = 3;
  cxxd_function_ns::function<void()> bound_f = cxxd_bind_ns::bind(f, n1, cxxd_ref_ns::ref(n2), cxxd_ref_ns::cref(n3));
  
  n1 = 10;
  n2 = 11;
  n3 = 12;
  bound_f();
  
  BOOST_TEST_EQ(n1,10);
  BOOST_TEST_EQ(n2,12);
  BOOST_TEST_EQ(n3,12);
  
  return boost::report_errors();
  }
