
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/detail/lightweight_test.hpp>

#define CXXD_TEST_NOT(expr) BOOST_TEST(!(expr))

#include <boost/cxx_dual/impl/unordered_set.hpp>

int main()
    {
  
    cxxd_unordered_set_ns::unordered_set<int> numbers;
    
    BOOST_TEST(numbers.empty());
 
    numbers.insert(42);
    numbers.insert(13317); 
    
    CXXD_TEST_NOT(numbers.empty());
    
    typedef cxxd_unordered_set_ns::unordered_set<int>::iterator it;
    
    it search = numbers.find(13317);
    
    BOOST_TEST(search != numbers.end());
  
    search = numbers.find(22);
    
    BOOST_TEST(search == numbers.end());
    
    return boost::report_errors();
    }
