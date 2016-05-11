
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <string>
#include <stdexcept>

#include <boost/cxx_dual/tuple.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_TUPLE_HEADER

CXXD_TUPLE_NS::tuple<double, char, std::string> get_student(int id)
    {
    if (id == 0) return CXXD_TUPLE_NS::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return CXXD_TUPLE_NS::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return CXXD_TUPLE_NS::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
    }
  
int main()
    {
  
    CXXD_TUPLE_NS::tuple<double, char, std::string> student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << CXXD_TUPLE_NS::get<0>(student0) << ", "
              << "grade: " << CXXD_TUPLE_NS::get<1>(student0) << ", "
              << "name: " << CXXD_TUPLE_NS::get<2>(student0) << '\n';
 
    double gpa1;
    char grade1;
    std::string name1;
    CXXD_TUPLE_NS::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';
  
    return boost::report_errors();
    }
