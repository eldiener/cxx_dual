
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

//  Copyright Beman Dawes 2001.  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/detail/lightweight_test.hpp>
#include <libs/cxx_dual/test/test_shared_ptr2_example.hpp>

int main()
  {
  example a;
  a.do_something();
  example b(a);
  b.do_something();
  example c;
  c = a;
  c.do_something();
  return boost::report_errors();
  }
