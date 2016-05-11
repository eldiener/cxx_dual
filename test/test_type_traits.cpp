
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <string>
#include <stdexcept>
#include <boost/cxx_dual/type_traits.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/static_assert.hpp>

#include CXXD_TYPE_TRAITS_HEADER

class A {};

struct B {
    int m;
};
 
struct C {
    virtual ~C();
};

class X {};
class Y : public X {};
class Z {};

enum E {};
 
template <class T>
T f(T i)
{
    BOOST_STATIC_ASSERT_MSG(CXXD_TYPE_TRAITS_NS::is_integral<T>::value, "Integer required.");
    return i;
}

struct foo
{
    void m() { std::cout << "Non-cv\n"; }
    void m() const { std::cout << "Const\n"; }
};
 
template <class T>
void call_m()
{
    T().m();
}

template <typename T, typename U>
struct decay_equiv : 
    CXXD_TYPE_TRAITS_NS::is_same<typename CXXD_TYPE_TRAITS_NS::decay<T>::type, U>::type 
{};

int main()
    {
  
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_void<void>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_void<int>::value << '\n';
    
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_integral<A>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_integral<float>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_integral<int>::value << '\n';
    std::cout << f(123) << '\n';
    
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_floating_point<A>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_floating_point<float>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_floating_point<int>::value << '\n';
    
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<A>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<A[]>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<A[3]>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<float>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<int>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<int[]>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_array<int[3]>::value << '\n';
    
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_enum<A>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_enum<E>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_enum<int>::value << '\n';
    
    std::cout << (CXXD_TYPE_TRAITS_NS::is_compound<A>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';
    std::cout << (CXXD_TYPE_TRAITS_NS::is_compound<int>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';
                     
    std::cout << std::boolalpha;
    std::cout << CXXD_TYPE_TRAITS_NS::is_empty<A>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_empty<B>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::is_empty<C>::value << '\n';
    
    std::cout << std::boolalpha
              << "std::string has a virtual destructor? "
              << CXXD_TYPE_TRAITS_NS::has_virtual_destructor<std::string>::value << '\n'
              << "std::runtime_error has a virtual destructor? "
              << CXXD_TYPE_TRAITS_NS::has_virtual_destructor<std::runtime_error>::value << '\n';
              
    std::cout << CXXD_TYPE_TRAITS_NS::extent<int[3]>::value << '\n'; //< default dimension is 0
    std::cout << CXXD_TYPE_TRAITS_NS::extent<int[3][4], 0>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::extent<int[3][4], 1>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::extent<int[3][4], 2>::value << '\n';
    std::cout << CXXD_TYPE_TRAITS_NS::extent<int[]>::value << '\n';
 
    const int ext = CXXD_TYPE_TRAITS_NS::extent<int[9]>();
    std::cout << ext << '\n'; //< implicit conversion to std::size_t
    
    bool b2a = CXXD_TYPE_TRAITS_NS::is_convertible<B*, A*>::value;
    bool a2b = CXXD_TYPE_TRAITS_NS::is_convertible<A*, B*>::value;
    bool b2c = CXXD_TYPE_TRAITS_NS::is_convertible<B*, C*>::value;
 
    std::cout << std::boolalpha;
    std::cout << b2a << '\n';
    std::cout << a2b << '\n';
    std::cout << b2c << '\n';
    
    call_m<foo>();
    call_m<CXXD_TYPE_TRAITS_NS::add_const<foo>::type>();
    
    std::cout << std::boolalpha
              << decay_equiv<int, int>::value << '\n'
              << decay_equiv<int&, int>::value << '\n'
              << decay_equiv<const int&, int>::value << '\n'
              << decay_equiv<int[2], int*>::value << '\n'
              << decay_equiv<int(int), int(*)(int)>::value << '\n';
  
    return boost::report_errors();
    }
