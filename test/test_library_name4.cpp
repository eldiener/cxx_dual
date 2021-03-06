
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name4 test

#else

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>

#define CXXD_FUNCTION_USE_STD
#define CXXD_HASH_USE_BOOST
#define CXXD_MEM_FN_USE_BOOST
#define CXXD_MUTEX_USE_BOOST
#define CXXD_RANDOM_USE_STD

#include <boost/cxx_dual/impl/function.hpp>
#include <boost/cxx_dual/impl/hash.hpp>
#include <boost/cxx_dual/impl/mem_fn.hpp>
#include <boost/cxx_dual/impl/mutex.hpp>
#include <boost/cxx_dual/impl/random.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_fn_rd (ALib_fn_rd)
#define BOOST_VMD_DETECT_ALib_fn_rd_ALib_fn_rd
#define BOOST_VMD_REGISTER_ALibSrd_HB_fn (ALibSrd_HB_fn)
#define BOOST_VMD_DETECT_ALibSrd_HB_fn_ALibSrd_HB_fn

#include <boost/cxx_dual/library_name.hpp>

  #define CXXD_TEST_LBN1_RESULT CXXD_LIBRARY_NAME(ALib)
  #define CXXD_TEST_LBN2_RESULT CXXD_LIBRARY_NAME(ALib,(CXXD_RANDOM,Srd,Brd),(CXXD_MUTEX,SMut),(CXXD_HASH,,_HB))

#include <boost/cxx_dual/library_name_post.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN1_RESULT,ALib_fn_rd));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_TEST_LBN2_RESULT,ALibSrd_HB_fn));
    
  return boost::report_errors();
  }

#endif
