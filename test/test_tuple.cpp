
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <string>
#include <stdexcept>

#include <boost/cxx_dual/tuple.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_TUPLE_HEADER

cxxd_tuple_ns::tuple<double, char, std::string> get_student(int id)
    {
    if (id == 0) return cxxd_tuple_ns::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return cxxd_tuple_ns::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return cxxd_tuple_ns::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
    }
  
int main()
    {
  
    cxxd_tuple_ns::tuple<double, char, std::string> student0 = get_student(0);
    
    BOOST_TEST_EQ(cxxd_tuple_ns::get<1>(student0),'A');
    BOOST_TEST_EQ(cxxd_tuple_ns::get<2>(student0),"Lisa Simpson");
    
    double gpa1;
    char grade1;
    std::string name1;
    cxxd_tuple_ns::tie(gpa1, grade1, name1) = get_student(1);
    
    BOOST_TEST_EQ(grade1,'C');
    BOOST_TEST_EQ(name1,"Milhouse Van Houten");
  
    return boost::report_errors();
    }
