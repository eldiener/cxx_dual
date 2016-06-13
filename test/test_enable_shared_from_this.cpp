
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/enable_shared_from_this.hpp>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_ENABLE_SHARED_FROM_THIS_HEADER
#include CXXD_SHARED_PTR_ONLY_HEADER

class Y: public cxxd_enable_shared_from_this_ns::enable_shared_from_this<Y>
{
public:

    cxxd_shared_ptr_ns::shared_ptr<Y> f()
    {
        return shared_from_this();
    }
};

int main()
  {
  
  cxxd_shared_ptr_ns::shared_ptr<Y> p(new Y);
  cxxd_shared_ptr_ns::shared_ptr<Y> q = p->f();
  BOOST_TEST_EQ(p,q);
  BOOST_TEST(!(p < q || q < p));
  
  return boost::report_errors();
  }
