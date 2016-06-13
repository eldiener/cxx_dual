
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/mem_fn.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_MEM_FN_HEADER
 
struct Foo {
    char display_greeting() {
        return 'g';
    }
    int display_number(int i) {
        return (i + data + 26);
    }
    int data;
};

int main()
  {
  
  Foo f;
  f.data = 7;
 
  BOOST_TEST_EQ(cxxd_mem_fn_ns::mem_fn(&Foo::display_greeting)(f),'g');
 
  BOOST_TEST_EQ(cxxd_mem_fn_ns::mem_fn(&Foo::display_number)(f,42),75);
 
  BOOST_TEST_EQ(cxxd_mem_fn_ns::mem_fn(&Foo::data)(f),7);
  
  return boost::report_errors();
  }
