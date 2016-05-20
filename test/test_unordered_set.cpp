
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/unordered_set.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_UNORDERED_SET_HEADER

int main()
    {
  
    CXXD_UNORDERED_SET_NS::unordered_set<int> numbers;
    
    BOOST_TEST(numbers.empty());
 
    numbers.insert(42);
    numbers.insert(13317); 
    
    BOOST_TEST_NOT(numbers.empty());
    
    typedef CXXD_UNORDERED_SET_NS::unordered_set<int>::iterator it;
    
    it search = numbers.find(13317);
    
    BOOST_TEST(search != numbers.end());
  
    search = numbers.find(22);
    
    BOOST_TEST(search == numbers.end());
    
    return boost::report_errors();
    }
