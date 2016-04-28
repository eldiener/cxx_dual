
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>

#define CXXD_ARRAY_USE_BOOST
#define CXXD_ATOMIC_USE_BOOST
#define CXXD_BIND_USE_BOOST
#define CXXD_CHRONO_USE_BOOST
#define CXXD_CONDITION_VARIABLE_USE_BOOST
#define CXXD_FUNCTION_USE_BOOST
#define CXXD_HASH_USE_BOOST
#define CXXD_MEM_FN_USE_BOOST
#define CXXD_MUTEX_USE_BOOST
#define CXXD_RANDOM_USE_BOOST
#define CXXD_RATIO_USE_BOOST
#define CXXD_REF_USE_BOOST
#define CXXD_REGEX_USE_BOOST
#define CXXD_SHARED_MUTEX_USE_BOOST
#define CXXD_SHARED_PTR_USE_BOOST
#define CXXD_SYSTEM_USE_BOOST
#define CXXD_THREAD_USE_BOOST
#define CXXD_TUPLE_USE_BOOST
#define CXXD_TYPE_INDEX_USE_BOOST
#define CXXD_TYPE_TRAITS_USE_BOOST
#define CXXD_UNORDERED_MAP_USE_BOOST
#define CXXD_UNORDERED_MULTIMAP_USE_BOOST
#define CXXD_UNORDERED_MULTISET_USE_BOOST
#define CXXD_UNORDERED_SET_USE_BOOST

#include <boost/cxx_dual/cxx_mods.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib (ALib)
#define BOOST_VMD_DETECT_ALib_ALib
#define BOOST_VMD_REGISTER_ALibAllBoost (ALibAllBoost)
#define BOOST_VMD_DETECT_ALibAllBoost_ALibAllBoost

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_MODS_ALL,AllStd,AllBoost)),ALibAllBoost));
    
  return boost::report_errors();
  }
