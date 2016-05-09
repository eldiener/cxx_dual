
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>

#include <boost/cxx_dual/random.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/foreach.hpp>
#include <boost/math/special_functions/round.hpp>

#include CXXD_RANDOM_HEADER

#if !CXXD_HAS_STD_RANDOM
#include <boost/random/random_device.hpp>
#define default_random_engine minstd_rand
#endif

int main()
  {
  
  // Seed with a real random value, if available
  CXXD_RANDOM_NS::random_device r;
 
  // Choose a random mean between 1 and 6
  
  CXXD_RANDOM_NS::default_random_engine e1(r());
  CXXD_RANDOM_NS::uniform_int_distribution<int> uniform_dist(1, 6);
  int mean = uniform_dist(e1);
  std::cout << "Randomly-chosen mean: " << mean << '\n';
 
  // Generate a normal distribution around that mean
  
#if !defined(BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX)
  
  CXXD_RANDOM_NS::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
  
#else

  unsigned int sarr[8] = {r(), r(), r(), r(), r(), r(), r(), r()};
  CXXD_RANDOM_NS::seed_seq seed2(sarr);
  
#endif
  
  CXXD_RANDOM_NS::mt19937 e2(seed2);
  CXXD_RANDOM_NS::normal_distribution<> normal_dist(mean, 2);
 
  std::map<int, int> hist;
  for (int n = 0; n < 10000; ++n) {
        ++hist[boost::math::round(normal_dist(e2))];
  }
  std::cout << "Normal distribution around " << mean << ":\n";
  
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)

  for (auto p : hist) {
      std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                << p.first << ' ' << std::string(p.second/200, '*') << '\n';
  }

#else

  typedef std::pair<int const,int> bf_pair;

  BOOST_FOREACH(bf_pair const & p,hist)
      std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                << p.first << ' ' << std::string(p.second/200, '*') << '\n';
  
#endif
  
  return boost::report_errors();
  }
