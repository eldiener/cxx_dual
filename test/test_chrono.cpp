
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/chrono.hpp>

#if !CXXD_HAS_STD_CHRONO
#define BOOST_CHRONO_HEADER_ONLY
#define BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
#define BOOST_SYSTEM_NO_DEPRECATED // Remove when chrono 'master' branch is updated from 'develop'
#endif

#include <boost/cxx_dual/impl/chrono.hpp>
#include <boost/cxx_dual/impl/ratio.hpp>

int main()
  {
  typedef cxxd_chrono_ns::duration<int, cxxd_ratio_ns::ratio<1, 100000000> > shakes;
  typedef cxxd_chrono_ns::duration<int, cxxd_ratio_ns::centi> jiffies;
  typedef cxxd_chrono_ns::duration<float, cxxd_ratio_ns::ratio<12096,10000> > microfortnights;
  typedef cxxd_chrono_ns::duration<float, cxxd_ratio_ns::ratio<3155,1000> > nanocenturies;
  
  cxxd_chrono_ns::seconds sec(1);
 
  std::cout << "1 second is:\n";
 
  std::cout << cxxd_chrono_ns::duration_cast<shakes>(sec).count()
              << " shakes\n";
  std::cout << cxxd_chrono_ns::duration_cast<jiffies>(sec).count()
              << " jiffies\n";
  std::cout << microfortnights(sec).count() << " microfortnights\n";
  std::cout << nanocenturies(sec).count() << " nanocenturies\n";
  return 0;
  }
