
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/ratio.hpp>
#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/impl/ratio.hpp>

int main()
  {
  
  BOOST_TEST((cxxd_ratio_ns::ratio_equal<cxxd_ratio_ns::ratio<2,3>, cxxd_ratio_ns::ratio<4,6> >::value));
  BOOST_TEST((cxxd_ratio_ns::ratio_not_equal<cxxd_ratio_ns::ratio<2,3>, cxxd_ratio_ns::ratio<1,3> >::value));
  BOOST_TEST((cxxd_ratio_ns::ratio_less<cxxd_ratio_ns::ratio<23,37>, cxxd_ratio_ns::ratio<57,90> >::value));
  BOOST_TEST((cxxd_ratio_ns::ratio_greater<cxxd_ratio_ns::ratio<23,37>, cxxd_ratio_ns::deci>::value));
  BOOST_TEST((cxxd_ratio_ns::ratio_less_equal<cxxd_ratio_ns::ratio<19,30>, cxxd_ratio_ns::ratio<57,90> >::value));
  BOOST_TEST((cxxd_ratio_ns::ratio_greater_equal<cxxd_ratio_ns::deca, cxxd_ratio_ns::deci>::value));
  
  typedef cxxd_ratio_ns::ratio<2, 3> two_third;
  typedef cxxd_ratio_ns::ratio<1, 6> one_sixth;
 
  typedef cxxd_ratio_ns::ratio_add<two_third, one_sixth> sum;
  
  BOOST_TEST_EQ(sum::num,5);
  BOOST_TEST_EQ(sum::den,6);
  
  typedef cxxd_ratio_ns::ratio_subtract<two_third, one_sixth> diff;
  
  BOOST_TEST_EQ(diff::num,1);
  BOOST_TEST_EQ(diff::den,2);
  
  typedef cxxd_ratio_ns::ratio_multiply<two_third, one_sixth> rm;
  
  BOOST_TEST_EQ(rm::num,1);
  BOOST_TEST_EQ(rm::den,9);
  
  typedef cxxd_ratio_ns::ratio_divide<two_third, one_sixth> rd;
  
  BOOST_TEST_EQ(rd::num,4);
  BOOST_TEST_EQ(rd::den,1);
  
  return boost::report_errors();
  }
