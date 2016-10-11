
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_vv_result test

#elif !defined(CXXD_VV)

#error Valid variant macro CXXD_VV must be specified.

#else

#include <boost/cxx_dual/impl/cxx_mods.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

#if ! CXXD_VALID_VARIANTS(CXXD_VV)

#error Valid variant test fails.

#endif

int main()
  {
  return 0;
  }

#endif
