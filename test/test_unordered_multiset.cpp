
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/unordered_multiset.hpp>
#include <boost/detail/lightweight_test.hpp>

#define CXXD_TEST_NOT(expr) BOOST_TEST(!(expr))

#include <boost/cxx_dual/impl/unordered_multiset.hpp>

int main()
    {
  
    cxxd_unordered_multiset_ns::unordered_multiset<int> numbers;
    
    BOOST_TEST(numbers.empty());
 
    numbers.insert(42);
    numbers.insert(13317); 
    numbers.insert(13317); 
    numbers.insert(688); 
    numbers.insert(688); 
    numbers.insert(688); 
    numbers.insert(689); 
    
    CXXD_TEST_NOT(numbers.empty());
    
    typedef cxxd_unordered_multiset_ns::unordered_multiset<int>::iterator it;
    
    it search = numbers.find(13317);
    
    BOOST_TEST(search != numbers.end());
    
    cxxd_unordered_multiset_ns::unordered_multiset<int>::size_type cnt(numbers.count(688));
    
    BOOST_TEST_EQ(cnt,static_cast<unsigned>(3));
    
    numbers.erase(688);
    cnt = numbers.count(688);
    BOOST_TEST_EQ(cnt,static_cast<unsigned>(0));
  
    return boost::report_errors();
    }
