
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <cassert>
#include <boost/cxx_dual/enable_shared_from_this.hpp>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_ENABLE_SHARED_FROM_THIS_HEADER
#include CXXD_SHARED_PTR_ONLY_HEADER

class Y: public CXXD_ENABLE_SHARED_FROM_THIS_NS::enable_shared_from_this<Y>
{
public:

    CXXD_SHARED_PTR_NS::shared_ptr<Y> f()
    {
        return shared_from_this();
    }
};

int main()
  {
  
  CXXD_SHARED_PTR_NS::shared_ptr<Y> p(new Y);
  CXXD_SHARED_PTR_NS::shared_ptr<Y> q = p->f();
  assert(p == q);
  assert(!(p < q || q < p)); // p and q must share ownership
  
  return boost::report_errors();
  }
