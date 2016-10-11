
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

#include <boost/cxx_dual/unordered_multimap.hpp>

int main()
    {
    
    // Create an unordered_multimap of strings (that map to strings)
    cxxd_unordered_multimap_ns::unordered_multimap<std::string, std::string> u;
    
    typedef cxxd_unordered_multimap_ns::unordered_multimap<std::string, std::string>::value_type vt;
    typedef cxxd_unordered_multimap_ns::unordered_multimap<std::string, std::string>::iterator it;

    u.insert(vt("RED","#FF0000"));
    u.insert(vt("RED","#FE0000"));
    u.insert(vt("GREEN","#00FF00"));
    u.insert(vt("BLUE","#0000FF"));
 
#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(BOOST_NO_CXX11_RANGE_BASED_FOR)

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) 
        {
        if (n.first == "RED")
            {
            BOOST_TEST(n.second == std::string("#FF0000") || n.second == std::string("#FE0000"));
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

    BOOST_FOREACH(const vt& n,u)
        {
        if (n.first == "RED")
            {
            BOOST_TEST(n.second == std::string("#FF0000") || n.second == std::string("#FE0000"));
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
 
    // Add new entries to the unordered_multimap
    u.insert(vt("BLACK","#000000"));
    u.insert(vt("WHITE","#FFFFFF"));
    u.insert(vt("WHITE","#FFFFFE"));
 
    // Output values by key
    
    std::pair<it,it> rres(u.equal_range("RED"));
    std::pair<it,it> bres(u.equal_range("BLACK"));
    
    BOOST_TEST((*rres.first).second == std::string("#FF0000") || (*rres.first).second == std::string("#FE0000"));
    ++rres.first;
    BOOST_TEST((*rres.first).second == std::string("#FF0000") || (*rres.first).second == std::string("#FE0000"));
    BOOST_TEST_EQ((*bres.first).second,std::string("#000000"));
  
    return boost::report_errors();
    }
