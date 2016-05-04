
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <boost/cxx_dual/bind.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/detail/lightweight_test.hpp>
#include CXXD_BIND_HEADER
#include CXXD_REF_HEADER

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}
 
int g(int n1)
{
    return n1;
}
 
struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data;
};

struct F
{
    int operator()(int a, int b) { return a - b; }
    bool operator()(long a, long b) { return a == b; }
};

int main()
  {
    using namespace CXXD_BIND_NS::placeholders;  // for _1, _2, _3...
 
    // demonstrates argument reordering and pass-by-reference
    int n = 7;
    // (_1 and _2 are from CXXD_BIND_NS::placeholders, and represent future
    // arguments that will be passed to f1)
    CXXD_REF_NS::reference_wrapper<int const> const rwrap(CXXD_REF_NS::cref(n));
    n = 10;
    CXXD_BIND_NS::bind(f, _2, _1, 42, rwrap, n)(1, 2, 1001); // 1 is bound by _2, 2 is bound by _1, 1001 is unused
 
    // nested bind subexpressions share the placeholders
    CXXD_BIND_NS::bind(f, _3, CXXD_BIND_NS::bind(g, _3), _3, 4, 5)(10, 11, 12);
 
    // bind to a member function
    Foo foo;
    foo.data = 10;
    CXXD_BIND_NS::bind(&Foo::print_sum, &foo, 95, _1)(5);
 
    // bind to member data
    std::cout << CXXD_BIND_NS::bind(&Foo::data, _1)(foo) << '\n';
    
    F f;
    int x = 104;
    CXXD_BIND_NS::bind<int>(f, _1, _1)(x);
 
    return boost::report_errors();
  } 
