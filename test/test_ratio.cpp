
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/ratio.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_RATIO_HEADER

int main()
  {
  
  if(CXXD_RATIO_NS::ratio_equal<CXXD_RATIO_NS::ratio<2,3>, CXXD_RATIO_NS::ratio<4,6> >::value)
    std::cout << "2/3 == 4/6\n";
  else 
    std::cout << "2/3 != 4/6\n";
    
  if(CXXD_RATIO_NS::ratio_not_equal<CXXD_RATIO_NS::ratio<2,3>, CXXD_RATIO_NS::ratio<1,3> >::value)
    std::cout << "2/3 != 1/3\n";
  else 
    std::cout << "2/3 == 1/3\n";
    
  if (CXXD_RATIO_NS::ratio_less<CXXD_RATIO_NS::ratio<23,37>, CXXD_RATIO_NS::ratio<57,90> >::value)
    std::cout << "23/37 < 57/90\n";
  else
    std::cout << "23/37 >= 57/90\n";
  
  if (CXXD_RATIO_NS::ratio_greater<CXXD_RATIO_NS::ratio<23,37>, CXXD_RATIO_NS::deci>::value)
    std::cout << "23/37 > deci\n";
  else
    std::cout << "23/37 <= deci\n";
  
  if (CXXD_RATIO_NS::ratio_less_equal<CXXD_RATIO_NS::ratio<19,30>, CXXD_RATIO_NS::ratio<57,90> >::value)
    std::cout << "19/30 <= 57/90\n";
  else
    std::cout << "19/30 > 57/90\n";
  
  if (CXXD_RATIO_NS::ratio_greater_equal<CXXD_RATIO_NS::deca, CXXD_RATIO_NS::deci>::value)
    std::cout << "deca >= deci\n";
  else
    std::cout << "deca < deci\n";
    
  typedef CXXD_RATIO_NS::ratio<2, 3> two_third;
  typedef CXXD_RATIO_NS::ratio<1, 6> one_sixth;
 
  typedef CXXD_RATIO_NS::ratio_add<two_third, one_sixth> sum;
  std::cout << "2/3 + 1/6 = " << sum::num << '/' << sum::den << '\n';  
  
  typedef CXXD_RATIO_NS::ratio_subtract<two_third, one_sixth> diff;
  std::cout << "2/3 - 1/6 = " << diff::num << '/' << diff::den << '\n';
  
  typedef CXXD_RATIO_NS::ratio_multiply<two_third, one_sixth> rm;
  std::cout << "2/3 * 1/6 = " << rm::num << '/' << rm::den << '\n';
  
  typedef CXXD_RATIO_NS::ratio_divide<two_third, one_sixth> rd;
  std::cout << "2/3 / 1/6 = " << rd::num << '/' << rd::den << '\n';
  
  return boost::report_errors();
  }
