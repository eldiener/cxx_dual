
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/detail/lightweight_test.hpp>

int main()
    {
    
    namespace cxxd_test_alias = std;
    
    namespace cxxd_test_alias = boost;
  
    return boost::report_errors();
    }
