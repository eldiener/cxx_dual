
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name3 test

#else

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>
#include <libs/cxx_dual/test/test_library_name_use_std.hpp>
#include <boost/cxx_dual/cxx_mods.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_std (ALib_std)
#define BOOST_VMD_DETECT_ALib_std_ALib_std
#define BOOST_VMD_REGISTER_ALibAllStd (ALibAllStd)
#define BOOST_VMD_DETECT_ALibAllStd_ALibAllStd

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_std));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_MODS_ALL,AllStd,AllBoost)),ALibAllStd));
  
  return boost::report_errors();
  }

#endif
