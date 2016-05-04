
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <boost/config.hpp>
#include <boost/cxx_dual/array.hpp>
#include <boost/foreach.hpp>
#include <boost/detail/lightweight_test.hpp>
#include CXXD_ARRAY_HEADER

int main()
  {
  
#if defined(BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX)
  
  CXXD_ARRAY_NS::array<int, 3> a1 = {1, 2, 3};
  
#else
  
  // construction uses aggregate initialization
  CXXD_ARRAY_NS::array<int, 3> a1{ {1, 2, 3} };
  
#endif
  
  CXXD_ARRAY_NS::array<int, 3> a2 = {1, 2, 3};
  CXXD_ARRAY_NS::array<std::string, 2> a3 = { std::string("a"), "b" };

  // container operations are supported
  std::sort(a1.begin(), a1.end());
  std::reverse_copy(a2.begin(), a2.end(), 
                    std::ostream_iterator<int>(std::cout, " "));
 
  std::cout << '\n';
  
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
 
  // ranged for loop is supported
  for(const auto& s: a3)
      std::cout << s << ' ';
      
#else

  BOOST_FOREACH(const std::string& s,a3)
      std::cout << s << ' ';
      
#endif
  
  return boost::report_errors();
  }
