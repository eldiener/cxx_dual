
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/cxx_dual/unordered_multimap.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_UNORDERED_MULTIMAP_HEADER

int main()
    {
    
    // Create an unordered_multimap of strings (that map to strings)
    CXXD_UNORDERED_MULTIMAP_NS::unordered_multimap<std::string, std::string> u;
    
    typedef CXXD_UNORDERED_MULTIMAP_NS::unordered_multimap<std::string, std::string>::value_type vt;
    typedef CXXD_UNORDERED_MULTIMAP_NS::unordered_multimap<std::string, std::string>::iterator it;

    u.insert(vt("RED","#FF0000"));
    u.insert(vt("RED","#FE0000"));
    u.insert(vt("GREEN","#00FF00"));
    u.insert(vt("BLUE","#0000FF"));
 
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    
#else

    BOOST_FOREACH(const vt& n,u)
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
      
#endif
 
    // Add new entries to the unordered_multimap
    u.insert(vt("BLACK","#000000"));
    u.insert(vt("WHITE","#FFFFFF"));
    u.insert(vt("WHITE","#FFFFFE"));
 
    // Output values by key
    
    std::pair<it,it> rres(u.equal_range("RED"));
    std::pair<it,it> bres(u.equal_range("BLACK"));
    
    std::cout << "The HEX of the first color RED is:[" << (*rres.first).second << "]\n";
    std::cout << "The HEX of the second color RED is:[" << (*++rres.first).second << "]\n";
    std::cout << "The HEX of color BLACK is:[" << (*bres.first).second << "]\n";
  
    return boost::report_errors();
    }
