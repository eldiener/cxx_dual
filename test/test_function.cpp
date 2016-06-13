
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/config.hpp>
#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/bind.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_FUNCTION_HEADER
#include CXXD_BIND_HEADER

struct Foo {
    Foo(int num) : num_(num) {}
    int print_add(int i) const { return (num_ + i); }
    int num_;
};
 
int print_num(int i)
{
    return (i * 237);
}
 
struct PrintNum {
    int operator()(int i) const
    {
        return (i / 2);
    }
};

int main()
  {
  
  // store a free function
  cxxd_function_ns::function<int(int)> f_display = print_num;
  BOOST_TEST_EQ(f_display(-9),-9 * 237);
 
  #if !defined(BOOST_NO_CXX11_LAMBDAS)
  
  // store a lambda
  cxxd_function_ns::function<int()> f_display_42 = []() { return print_num(42); };
  BOOST_TEST_EQ(f_display_42(),42 * 237);
  
  #endif
 
  // store the result of a call to cxxd_bind_ns::bind
  cxxd_function_ns::function<int()> f_display_31337 = cxxd_bind_ns::bind(print_num, 31337);
  BOOST_TEST_EQ(f_display_31337(),31337 * 237);
 
  // store a call to a member function
  cxxd_function_ns::function<int(const Foo&, int)> f_add_display = &Foo::print_add;
  const Foo foo(314159);
  BOOST_TEST_EQ(f_add_display(foo, 1),314159 + 1);
 
  // store a call to a member function and object
  using cxxd_bind_ns::placeholders::_1;
  cxxd_function_ns::function<int(int)> f_add_display2= cxxd_bind_ns::bind( &Foo::print_add, foo, _1 );
  BOOST_TEST_EQ(f_add_display2(2),314159 + 2);
 
  // store a call to a member function and object ptr
  cxxd_function_ns::function<int(int)> f_add_display3= cxxd_bind_ns::bind( &Foo::print_add, &foo, _1 );
  BOOST_TEST_EQ(f_add_display3(3),314159 + 3);
 
  // store a call to a function object
  cxxd_function_ns::function<int(int)> f_display_obj = PrintNum();
  BOOST_TEST_EQ(f_display_obj(18),9);
  
  return boost::report_errors();
  }
