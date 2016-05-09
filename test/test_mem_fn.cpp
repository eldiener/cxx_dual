
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/mem_fn.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_MEM_FN_HEADER
 
struct Foo {
    void display_greeting() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data;
};

int main()
  {
  
  Foo f;
  f.data = 7;
 
  CXXD_MEM_FN_NS::mem_fn(&Foo::display_greeting)(f);
 
  CXXD_MEM_FN_NS::mem_fn(&Foo::display_number)(f,42);
 
  std::cout << "data: " << CXXD_MEM_FN_NS::mem_fn(&Foo::data)(f) << '\n';
  
  return boost::report_errors();
  }
