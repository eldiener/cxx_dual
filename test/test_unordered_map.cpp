
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <string>
#include <boost/config.hpp>

#include <boost/detail/lightweight_test.hpp>

#if defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) || defined(BOOST_NO_CXX11_RANGE_BASED_FOR)
#include <boost/foreach.hpp>
#endif

#include <boost/cxx_dual/impl/unordered_map.hpp>

int main()
    {
  
    // Create an unordered_map of three strings (that map to strings)
    cxxd_unordered_map_ns::unordered_map<std::string, std::string> u;
 
    u["RED"] = "#FF0000";
    u["GREEN"] = "#00FF00";
    u["BLUE"] = "#0000FF";
    
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) 
        {
        if (n.first == "RED")
            {
            BOOST_TEST_EQ(n.second,std::string("#FF0000"));
            }
        else if (n.first == "GREEN")
            {
            BOOST_TEST_EQ(n.second,std::string("#00FF00"));
            }
        else
            {
            BOOST_TEST_EQ(n.second,std::string("#0000FF"));
            }
        }
    
#else

    typedef cxxd_unordered_map_ns::unordered_map<std::string, std::string>::value_type vt;

    BOOST_FOREACH(const vt& n,u)
        {
        if (n.first == "RED")
            {
            BOOST_TEST_EQ(n.second,std::string("#FF0000"));
            }
        else if (n.first == "GREEN")
            {
            BOOST_TEST_EQ(n.second,std::string("#00FF00"));
            }
        else
            {
            BOOST_TEST_EQ(n.second,std::string("#0000FF"));
            }
        }
      
#endif
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
 
    // Output values by key
    BOOST_TEST_EQ(u["RED"],"#FF0000");
    BOOST_TEST_EQ(u["BLACK"],"#000000");
  
    return boost::report_errors();
    }
