
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/ratio.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_RATIO_HEADER

int main()
  {
  
  BOOST_TEST((CXXD_RATIO_NS::ratio_equal<CXXD_RATIO_NS::ratio<2,3>, CXXD_RATIO_NS::ratio<4,6> >::value));
  BOOST_TEST((CXXD_RATIO_NS::ratio_not_equal<CXXD_RATIO_NS::ratio<2,3>, CXXD_RATIO_NS::ratio<1,3> >::value));
  BOOST_TEST((CXXD_RATIO_NS::ratio_less<CXXD_RATIO_NS::ratio<23,37>, CXXD_RATIO_NS::ratio<57,90> >::value));
  BOOST_TEST((CXXD_RATIO_NS::ratio_greater<CXXD_RATIO_NS::ratio<23,37>, CXXD_RATIO_NS::deci>::value));
  BOOST_TEST((CXXD_RATIO_NS::ratio_less_equal<CXXD_RATIO_NS::ratio<19,30>, CXXD_RATIO_NS::ratio<57,90> >::value));
  BOOST_TEST((CXXD_RATIO_NS::ratio_greater_equal<CXXD_RATIO_NS::deca, CXXD_RATIO_NS::deci>::value));
  
  typedef CXXD_RATIO_NS::ratio<2, 3> two_third;
  typedef CXXD_RATIO_NS::ratio<1, 6> one_sixth;
 
  typedef CXXD_RATIO_NS::ratio_add<two_third, one_sixth> sum;
  
  BOOST_TEST_EQ(sum::num,5);
  BOOST_TEST_EQ(sum::den,6);
  
  typedef CXXD_RATIO_NS::ratio_subtract<two_third, one_sixth> diff;
  
  BOOST_TEST_EQ(diff::num,1);
  BOOST_TEST_EQ(diff::den,2);
  
  typedef CXXD_RATIO_NS::ratio_multiply<two_third, one_sixth> rm;
  
  BOOST_TEST_EQ(rm::num,1);
  BOOST_TEST_EQ(rm::den,9);
  
  typedef CXXD_RATIO_NS::ratio_divide<two_third, one_sixth> rd;
  
  BOOST_TEST_EQ(rd::num,4);
  BOOST_TEST_EQ(rd::den,1);
  
  return boost::report_errors();
  }
