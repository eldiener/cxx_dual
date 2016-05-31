
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name6 test

#else

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>

#define CXXD_SYSTEM_ERROR_USE_STD
#define CXXD_THREAD_USE_STD
#define CXXD_TUPLE_USE_BOOST
#define CXXD_TYPE_INDEX_USE_STD
#define CXXD_TYPE_TRAITS_USE_STD
#define CXXD_UNORDERED_MULTIMAP_USE_BOOST

#include <boost/cxx_dual/system_error.hpp>
#include <boost/cxx_dual/thread.hpp>
#include <boost/cxx_dual/tuple.hpp>
#include <boost/cxx_dual/type_index.hpp>
#include <boost/cxx_dual/type_traits.hpp>
#include <boost/cxx_dual/unordered_multimap.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_se_th_ti_tt (ALib_se_th_ti_tt)
#define BOOST_VMD_DETECT_ALib_se_th_ti_tt_ALib_se_th_ti_tt
#define BOOST_VMD_REGISTER_ALib_bmmpStdTI_th_tt (ALib_bmmpStdTI_th_tt)
#define BOOST_VMD_DETECT_ALib_bmmpStdTI_th_tt_ALib_bmmpStdTI_th_tt

#include <boost/cxx_dual/library_name.hpp>

  #define CXXD_TEST_LBN1_RESULT CXXD_LIBRARY_NAME(ALib)
  #define CXXD_TEST_LBN2_RESULT CXXD_LIBRARY_NAME \
                                    ( \
                                    ALib, \
                                    (), \
                                    (DUBIOUS), \
                                    (CXXD_UNORDERED_MULTIMAP,_smmp,_bmmp), \
                                    (CXXD_TYPE_INDEX,StdTI,BoostTI), \
                                    (CXXD_SYSTEM_ERROR,,BoostSys) \
                                    ) \
  /**/

#include <boost/cxx_dual/library_name_post.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN1_RESULT,ALib_se_th_ti_tt));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN2_RESULT,ALib_bmmpStdTI_th_tt));
    
  return boost::report_errors();
  }

#endif
