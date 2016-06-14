
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

#include <boost/cxx_dual/ratio.hpp>

#include CXXD_CHRONO_HEADER
#include CXXD_RATIO_HEADER

int main()
  {
  typedef CXXD_CHRONO_NS::duration<int, CXXD_RATIO_NS::ratio<1, 100000000> > shakes;
  typedef CXXD_CHRONO_NS::duration<int, CXXD_RATIO_NS::centi> jiffies;
  typedef CXXD_CHRONO_NS::duration<float, CXXD_RATIO_NS::ratio<12096,10000> > microfortnights;
  typedef CXXD_CHRONO_NS::duration<float, CXXD_RATIO_NS::ratio<3155,1000> > nanocenturies;
  
  CXXD_CHRONO_NS::seconds sec(1);
 
  std::cout << "1 second is:\n";
 
  std::cout << CXXD_CHRONO_NS::duration_cast<shakes>(sec).count()
              << " shakes\n";
  std::cout << CXXD_CHRONO_NS::duration_cast<jiffies>(sec).count()
              << " jiffies\n";
  std::cout << microfortnights(sec).count() << " microfortnights\n";
  std::cout << nanocenturies(sec).count() << " nanocenturies\n";
  return 0;
  }
