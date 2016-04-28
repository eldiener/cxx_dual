
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>

#define CXXD_FUNCTION_USE_STD
#define CXXD_HASH_USE_BOOST
#define CXXD_MEM_FN_USE_BOOST
#define CXXD_MUTEX_USE_BOOST
#define CXXD_RANDOM_USE_STD

#include <boost/cxx_dual/function.hpp>
#include <boost/cxx_dual/hash.hpp>
#include <boost/cxx_dual/mem_fn.hpp>
#include <boost/cxx_dual/mutex.hpp>
#include <boost/cxx_dual/random.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_fn_rd (ALib_fn_rd)
#define BOOST_VMD_DETECT_ALib_fn_rd_ALib_fn_rd
#define BOOST_VMD_REGISTER_ALibSrd_HB_fn (ALibSrd_HB_fn)
#define BOOST_VMD_DETECT_ALibSrd_HB_fn_ALibSrd_HB_fn

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_fn_rd));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_RANDOM,Srd,Brd),(CXXD_MUTEX,SMut),(CXXD_HASH,,_HB)),ALibSrd_HB_fn));
    
  return boost::report_errors();
  }
