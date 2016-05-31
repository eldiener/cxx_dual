
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name2 test

#else

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <libs/cxx_dual/test/test_library_name_use_boost.hpp>
#include <boost/cxx_dual/cxx_mods.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib (ALib)
#define BOOST_VMD_DETECT_ALib_ALib
#define BOOST_VMD_REGISTER_ALibAllBoost (ALibAllBoost)
#define BOOST_VMD_DETECT_ALibAllBoost_ALibAllBoost

#include <boost/cxx_dual/library_name.hpp>

  #define CXXD_TEST_LBN_RESULT1 CXXD_LIBRARY_NAME(ALib)
  #define CXXD_TEST_LBN_RESULT2 CXXD_LIBRARY_NAME(ALib,(CXXD_MODS_ALL,AllStd,AllBoost))

#include <boost/cxx_dual/library_name_post.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN_RESULT1,ALib));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN_RESULT2,ALibAllBoost));
    
  return boost::report_errors();
  }


#endif
