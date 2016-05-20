
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <boost/config.hpp>
#include <boost/cxx_dual/array.hpp>
#include <boost/detail/lightweight_test.hpp>

#if defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) || defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
#include <boost/foreach.hpp>
#endif

#include CXXD_ARRAY_HEADER

int main()
    {
  
#if defined(BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX)
  
    CXXD_ARRAY_NS::array<int, 3> a1 = {3, 2, 1};
  
#else
  
    // construction uses aggregate initialization
    CXXD_ARRAY_NS::array<int, 3> a1{ {3, 2, 1} };
  
#endif
  
    CXXD_ARRAY_NS::array<int, 3> a2 = {1, 2, 3};
    CXXD_ARRAY_NS::array<std::string, 2> a3 = { std::string("a"), "b" };
    std::vector<int> vec;

    // container operations are supported
    std::sort(a1.begin(), a1.end());
    BOOST_TEST_EQ(a1[0],1);
    BOOST_TEST_EQ(a1[1],2);
    BOOST_TEST_EQ(a1[2],3);
    std::reverse_copy(a2.begin(), a2.end(), std::back_inserter(vec));
    BOOST_TEST_EQ(vec[0],3);
    BOOST_TEST_EQ(vec[1],2);
    BOOST_TEST_EQ(vec[2],1);
  
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
 
    // ranged for loop is supported
    for(const auto& s: a3)
        {
        BOOST_TEST(s == "a" || s == "b");
        }
      
#else

    BOOST_FOREACH(const std::string& s,a3)
        {
        BOOST_TEST(s == "a" || s == "b");
        }
      
#endif
  
    return boost::report_errors();
    }
