
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG
#define CXXD_NO_CONSISTENCY

#include <boost/cxx_dual/library_name.hpp>
#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#define CXXD_ARRAY_USE_BOOST
#define CXXD_ATOMIC_USE_STD
#define CXXD_BIND_USE_BOOST
#define CXXD_CHRONO_USE_STD
#define CXXD_CONDITION_VARIABLE_USE_STD

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

#define BOOST_VMD_REGISTER_ALib_at_ch_cv (ALib_at_ch_cv)
#define BOOST_VMD_DETECT_ALib_at_ch_cv_ALib_at_ch_cv
#define BOOST_VMD_REGISTER_ALib_arrayBoostChStandard_at_cv (ALib_arrayBoostChStandard_at_cv)
#define BOOST_VMD_DETECT_ALib_arrayBoostChStandard_at_cv_ALib_arrayBoostChStandard_at_cv

#include <boost/cxx_dual/cxx_mods.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_at_ch_cv));
  
  BOOST_TEST
    (
    BOOST_VMD_EQUAL
        (
        CXXD_LIBRARY_NAME
            (
            ALib,
            (CXXD_ARRAY,_arrayStandard,_arrayBoost),
            (CXXD_CHRONO,ChStandard,ChBoost)
            ),
        ALib_arrayBoostChStandard_at_cv
        )
    );
  
#include <libs/cxx_dual/test/test_library_name_override_reset.hpp>

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

#define BOOST_VMD_REGISTER_ALib (ALib)
#define BOOST_VMD_DETECT_ALib_ALib

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib));
  
  return boost::report_errors();
  }
