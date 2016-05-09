
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <ctime>
#include <iomanip>
#include <boost/cxx_dual/chrono.hpp>

#if !CXXD_HAS_STD_CHRONO
#define BOOST_CHRONO_HEADER_ONLY
#define BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
// #define BOOST_SYSTEM_NO_DEPRECATED
#endif                                                                         

#include <boost/detail/lightweight_test.hpp>
                                                       
#include CXXD_CHRONO_HEADER

int main()
  {
  CXXD_CHRONO_NS::chrono::system_clock::time_point now = CXXD_CHRONO_NS::chrono::system_clock::now();
  std::time_t now_c = CXXD_CHRONO_NS::chrono::system_clock::to_time_t(now - CXXD_CHRONO_NS::chrono::hours(24));
  std::cout << "24 hours ago, the time was "
            << std::ctime(&now_c) << '\n';
  CXXD_CHRONO_NS::chrono::steady_clock::time_point start = CXXD_CHRONO_NS::chrono::steady_clock::now();
  std::cout << "Hello World\n";
  CXXD_CHRONO_NS::chrono::steady_clock::time_point end = CXXD_CHRONO_NS::chrono::steady_clock::now();
  std::cout << "Printing took "
            << CXXD_CHRONO_NS::chrono::duration_cast<CXXD_CHRONO_NS::chrono::microseconds>(end - start).count()
            << "us.\n";
  return boost::report_errors();
  }
