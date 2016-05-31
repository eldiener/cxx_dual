
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name1 test

#else

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>

#define CXXD_TUPLE_USE_BOOST
#define CXXD_UNORDERED_MAP_USE_BOOST
#define CXXD_UNORDERED_MULTIMAP_USE_STD
#define CXXD_UNORDERED_MULTISET_USE_STD
#define CXXD_UNORDERED_SET_USE_BOOST

#include <boost/cxx_dual/tuple.hpp>
#include <boost/cxx_dual/unordered_map.hpp>
#include <boost/cxx_dual/unordered_multimap.hpp>
#include <boost/cxx_dual/unordered_multiset.hpp>
#include <boost/cxx_dual/unordered_set.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_up_ut (ALib_up_ut)
#define BOOST_VMD_DETECT_ALib_up_ut_ALib_up_ut
#define BOOST_VMD_REGISTER_ALib_bumpBoostSysMSetStd_up (ALib_bumpBoostSysMSetStd_up)
#define BOOST_VMD_DETECT_ALib_bumpBoostSysMSetStd_up_ALib_bumpBoostSysMSetStd_up

#include <boost/cxx_dual/library_name.hpp>

  #define CXXD_TEST_LBN1_RESULT CXXD_LIBRARY_NAME(ALib)
  #define CXXD_TEST_LBN2_RESULT CXXD_LIBRARY_NAME \
                                    ( \
                                    ALib, \
                                    (CXXD_UNORDERED_MAP,,_bump), \
                                    (CXXD_TUPLE,,BoostSys), \
                                    (CXXD_MODS_ALL,AllStd,AllBoost), \
                                    (CXXD_UNORDERED_MULTISET,MSetStd,MSetBoost) \
                                    ) \
  /**/

  
#include <boost/cxx_dual/library_name_post.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN1_RESULT,ALib_up_ut));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN2_RESULT,ALib_bumpBoostSysMSetStd_up));
    
  return boost::report_errors();
  }

#endif
