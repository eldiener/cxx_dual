
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_valid_variants test

#else

#define CXXD_NO_CONFIG

#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

#define CXXD_ARRAY_USE_BOOST
#define CXXD_ATOMIC_USE_STD
#define CXXD_BIND_USE_BOOST
#define CXXD_CHRONO_USE_STD
#define CXXD_CONDITION_VARIABLE_USE_STD

#include <boost/cxx_dual/impl/array.hpp>
#include <boost/cxx_dual/impl/atomic.hpp>
#include <boost/cxx_dual/impl/bind.hpp>
#include <boost/cxx_dual/impl/chrono.hpp>
#include <boost/cxx_dual/impl/condition_variable.hpp>

int main()
  {
  
  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_ARRAY,0)(CXXD_BIND,0)(CXXD_CHRONO,0)(CXXD_CONDITION_VARIABLE,1),
        (CXXD_MODS_ALL,0),
        (CXXD_CHRONO,1)(CXXD_ATOMIC,1)(CXXD_BIND,0)
        )
    );
  
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_ARRAY,0)(CXXD_BIND,0)(CXXD_CHRONO,0)(CXXD_CONDITION_VARIABLE,1),
        (CXXD_MODS_ALL,0),
        (CXXD_CHRONO,1)(CXXD_ATOMIC,1)(CXXD_BIND,1)
        )
    );
    
  return boost::report_errors();
  }

#endif
