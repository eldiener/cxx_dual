
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>

#define CXXD_ARRAY_USE_STD
#define CXXD_ATOMIC_USE_STD
#define CXXD_BIND_USE_STD
#define CXXD_CHRONO_USE_STD
#define CXXD_CONDITION_VARIABLE_USE_STD
#define CXXD_FUNCTION_USE_STD
#define CXXD_HASH_USE_STD
#define CXXD_MEM_FN_USE_STD
#define CXXD_MUTEX_USE_STD
#define CXXD_RANDOM_USE_STD
#define CXXD_RATIO_USE_STD
#define CXXD_REF_USE_STD
#define CXXD_REGEX_USE_STD
#define CXXD_SHARED_MUTEX_USE_STD
#define CXXD_SHARED_PTR_USE_STD
#define CXXD_SYSTEM_USE_STD
#define CXXD_THREAD_USE_STD
#define CXXD_TUPLE_USE_STD
#define CXXD_TYPE_INDEX_USE_STD
#define CXXD_TYPE_TRAITS_USE_STD
#define CXXD_UNORDERED_MAP_USE_STD
#define CXXD_UNORDERED_MULTIMAP_USE_STD
#define CXXD_UNORDERED_MULTISET_USE_STD
#define CXXD_UNORDERED_SET_USE_STD

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
