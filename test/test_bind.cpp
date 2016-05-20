
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/cxx_dual/bind.hpp>
#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/detail/lightweight_test.hpp>
#include CXXD_BIND_HEADER
#include CXXD_FUNCTION_HEADER
#include CXXD_REF_HEADER

int f(int n1, int n2, int n3, const int& n4, int n5)
{
    return (n1 + n2 + n3 - n4 + n5);
}
 
int g(int n1)
{
    return -n1;
}
 
struct Foo {
    int do_calc(int n1, int n2)
        {
        return (n1 * n2);
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
    CXXD_FUNCTION_NS::function<int (int,int,int)> fun(CXXD_BIND_NS::bind(f, _2, _1, 42, rwrap, n));
    n = 10;
    BOOST_TEST_EQ((fun(1, 2, 1001)),42);
 
    // nested bind subexpressions share the placeholders
    BOOST_TEST_EQ((CXXD_BIND_NS::bind(f, _3, CXXD_BIND_NS::bind(g, _3), _3, 4, 5)(10, 11, 12)),13);
 
    // bind to a member function
    Foo foo;
    foo.data = 10;
    BOOST_TEST_EQ((CXXD_BIND_NS::bind(&Foo::do_calc, &foo, 95, _1)(5)),475);
 
    // bind to member data
    BOOST_TEST_EQ((CXXD_BIND_NS::bind(&Foo::data, _1)(foo)),10);
    
    F f;
    int x = 104;
    long y = 204;
    BOOST_TEST_EQ((CXXD_BIND_NS::bind<int>(f, _1, _1)(x)),0);
    BOOST_TEST((CXXD_BIND_NS::bind<bool>(f, _1, _1)(y)));
 
    return boost::report_errors();
  } 
