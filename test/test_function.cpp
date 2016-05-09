
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/config.hpp>
#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/bind.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_FUNCTION_HEADER
#include CXXD_BIND_HEADER

struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
  {
  
  // store a free function
  CXXD_FUNCTION_NS::function<void(int)> f_display = print_num;
  f_display(-9);
 
  #if !defined(BOOST_NO_CXX11_LAMBDAS)
  
  // store a lambda
  CXXD_FUNCTION_NS::function<void()> f_display_42 = []() { print_num(42); };
  f_display_42();
  
  #endif
 
  // store the result of a call to CXXD_BIND_NS::bind
  CXXD_FUNCTION_NS::function<void()> f_display_31337 = CXXD_BIND_NS::bind(print_num, 31337);
  f_display_31337();
 
  // store a call to a member function
  CXXD_FUNCTION_NS::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
  const Foo foo(314159);
  f_add_display(foo, 1);
 
  // store a call to a member function and object
  using CXXD_BIND_NS::placeholders::_1;
  CXXD_FUNCTION_NS::function<void(int)> f_add_display2= CXXD_BIND_NS::bind( &Foo::print_add, foo, _1 );
  f_add_display2(2);
 
  // store a call to a member function and object ptr
  CXXD_FUNCTION_NS::function<void(int)> f_add_display3= CXXD_BIND_NS::bind( &Foo::print_add, &foo, _1 );
  f_add_display3(3);
 
  // store a call to a function object
  CXXD_FUNCTION_NS::function<void(int)> f_display_obj = PrintNum();
  f_display_obj(18);
  
  return boost::report_errors();
  }
