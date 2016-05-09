
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/bind.hpp>
#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_BIND_HEADER
#include CXXD_FUNCTION_HEADER
#include CXXD_REF_HEADER

void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    ++n1; // increments the copy of n1 stored in the function object
    ++n2; // increments the main()'s n2
    // ++n3; // compile error
}

int main()
  {
  
  int n1 = 1, n2 = 2, n3 = 3;
  CXXD_FUNCTION_NS::function<void()> bound_f = CXXD_BIND_NS::bind(f, n1, CXXD_REF_NS::ref(n2), CXXD_REF_NS::cref(n3));
  
  n1 = 10;
  n2 = 11;
  n3 = 12;
  std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
  bound_f();
  std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
  
  return boost::report_errors();
  }
