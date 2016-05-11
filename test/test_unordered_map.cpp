
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <string>
#include <boost/cxx_dual/unordered_map.hpp>
#include <boost/foreach.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_UNORDERED_MAP_HEADER

int main()
    {
  
    // Create an unordered_map of three strings (that map to strings)
    CXXD_UNORDERED_MAP_NS::unordered_map<std::string, std::string> u;
 
    u["RED"] = "#FF0000";
    u["GREEN"] = "#00FF00";
    u["BLUE"] = "#0000FF";
    
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    
#else

    typedef CXXD_UNORDERED_MAP_NS::unordered_map<std::string, std::string>::value_type vt;

    BOOST_FOREACH(const vt& n,u)
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
      
#endif
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
 
    // Output values by key
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";
  
    return boost::report_errors();
    }
