
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <map>
#include <typeinfo>
#include <string>
#include <boost/cxx_dual/shared_ptr.hpp>
#include <boost/cxx_dual/type_index.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_SHARED_PTR_ONLY_HEADER
#include CXXD_TYPE_INDEX_HEADER
 
struct A {
    virtual ~A() {}
};
 
struct B : A {};
struct C : A {};

int main()
    {
  
    std::map<CXXD_TYPE_INDEX_NS::type_index, std::string> type_names;
 
    type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(int))] = "int";
    type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(double))] = "double";
    type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(A))] = "A";
    type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(B))] = "B";
    type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(C))] = "C";
 
    int i;
    double d;
    A a;
 
    // note that we're storing pointer to type A
    CXXD_SHARED_PTR_NS::shared_ptr<A> b(new B);
    CXXD_SHARED_PTR_NS::shared_ptr<A> c(new C);
 
    std::cout << "i is " << type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(i))] << '\n';
    std::cout << "d is " << type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(d))] << '\n';
    std::cout << "a is " << type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(a))] << '\n';
    std::cout << "b is " << type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(*b))] << '\n';
    std::cout << "c is " << type_names[CXXD_TYPE_INDEX_NS::type_index(typeid(*c))] << '\n';
  
    return boost::report_errors();
    }   
