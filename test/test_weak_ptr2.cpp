
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SHARED_PTR_HEADER

CXXD_SHARED_PTR_NS::weak_ptr<int> gw;
 
bool f()
{
    if (CXXD_SHARED_PTR_NS::shared_ptr<int> spt = gw.lock())
        { // Has to be copied into a shared_ptr before usage
        return true;
        }
    else 
        {
        return false;
        }
}

int main()
  {
  
    {
    CXXD_SHARED_PTR_NS::shared_ptr<int> sp(new int(42));
	gw = sp;
	BOOST_TEST(f());
    }
  BOOST_TEST_NOT(f());
  return boost::report_errors();
  }
