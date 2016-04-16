
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
#define BOOST_VMD_REGISTER_ALibAllBoost (ALibAllBoost)
#define BOOST_VMD_DETECT_ALibAllBoost_ALibAllBoost

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_MODS_ALL,AllStd,AllBoost)),ALibAllBoost));
  
#include <libs/cxx_dual/test/test_library_name_override_reset.hpp>

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

#define BOOST_VMD_REGISTER_ALib_std (ALib_std)
#define BOOST_VMD_DETECT_ALib_std_ALib_std
#define BOOST_VMD_REGISTER_ALibAllStd (ALibAllStd)
#define BOOST_VMD_DETECT_ALibAllStd_ALibAllStd

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_std));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_MODS_ALL,AllStd,AllBoost)),ALibAllStd));
  
#include <libs/cxx_dual/test/test_library_name_override_reset.hpp>

#define CXXD_ARRAY_USE_BOOST
#define CXXD_ATOMIC_USE_BOOST
#define CXXD_BIND_USE_BOOST
#define CXXD_CHRONO_USE_BOOST
#define CXXD_CONDITION_VARIABLE_USE_BOOST

#define CXXD_FUNCTION_USE_STD
#define CXXD_HASH_USE_BOOST
#define CXXD_MEM_FN_USE_BOOST
#define CXXD_MUTEX_USE_BOOST
#define CXXD_RANDOM_USE_STD

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

#define BOOST_VMD_REGISTER_ALib_fn_rd (ALib_fn_rd)
#define BOOST_VMD_DETECT_ALib_fn_rd_ALib_fn_rd
#define BOOST_VMD_REGISTER_ALibSrd_HB_fn (ALibSrd_HB_fn)
#define BOOST_VMD_DETECT_ALibSrd_HB_fn_ALibSrd_HB_fn

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_fn_rd));
  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib,(CXXD_RANDOM,Srd,Brd),(CXXD_MUTEX,SMut),(CXXD_HASH,,_HB)),ALibSrd_HB_fn));
  
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
#define CXXD_REF_USE_STD
#define CXXD_REGEX_USE_STD
#define CXXD_SHARED_MUTEX_USE_STD
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

#define BOOST_VMD_REGISTER_ALib_rf_rx_sm (ALib_rf_rx_sm)
#define BOOST_VMD_DETECT_ALib_rf_rx_sm_ALib_rf_rx_sm
#define BOOST_VMD_REGISTER_ALibSSM_srefRatioBoost_rx (ALibSSM_srefRatioBoost_rx)
#define BOOST_VMD_DETECT_ALibSSM_srefRatioBoost_rx_ALibSSM_srefRatioBoost_rx

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_rf_rx_sm));
  
  BOOST_TEST
    (
    BOOST_VMD_EQUAL
        (
        CXXD_LIBRARY_NAME
            (
            ALib,
            (CXXD_SHARED_PTR),
            (CXXD_SHARED_MUTEX,SSM,BSM),
            (CXXD_REF,_sref,_bref),
            (CXXD_RATIO,RatioStandard,RatioBoost)
            ),
        ALibSSM_srefRatioBoost_rx
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

#define CXXD_SYSTEM_USE_STD
#define CXXD_THREAD_USE_STD
#define CXXD_TUPLE_USE_BOOST
#define CXXD_TYPE_INDEX_USE_STD
#define CXXD_TYPE_TRAITS_USE_STD

#define CXXD_UNORDERED_MAP_USE_BOOST
#define CXXD_UNORDERED_MULTIMAP_USE_BOOST
#define CXXD_UNORDERED_MULTISET_USE_BOOST
#define CXXD_UNORDERED_SET_USE_BOOST

#define BOOST_VMD_REGISTER_ALib_sy_th_ti_tt (ALib_sy_th_ti_tt)
#define BOOST_VMD_DETECT_ALib_sy_th_ti_tt_ALib_sy_th_ti_tt
#define BOOST_VMD_REGISTER_ALib_bmmpStdTI_th_tt (ALib_bmmpStdTI_th_tt)
#define BOOST_VMD_DETECT_ALib_bmmpStdTI_th_tt_ALib_bmmpStdTI_th_tt

#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_sy_th_ti_tt));
  
  BOOST_TEST
    (
    BOOST_VMD_EQUAL
        (
        CXXD_LIBRARY_NAME
            (
            ALib,
            (),
            (DUBIOUS),
            (CXXD_UNORDERED_MULTIMAP,_smmp,_bmmp),
            (CXXD_TYPE_INDEX,StdTI,BoostTI),
            (CXXD_SYSTEM,,BoostSys)
            ),
        ALib_bmmpStdTI_th_tt
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
#define CXXD_UNORDERED_MULTIMAP_USE_STD
#define CXXD_UNORDERED_MULTISET_USE_STD
#define CXXD_UNORDERED_SET_USE_BOOST

#define BOOST_VMD_REGISTER_ALib_up_ut (ALib_up_ut)
#define BOOST_VMD_DETECT_ALib_up_ut_ALib_up_ut
#define BOOST_VMD_REGISTER_ALib_bumpBoostSysMSetStd_up (ALib_bumpBoostSysMSetStd_up)
#define BOOST_VMD_DETECT_ALib_bumpBoostSysMSetStd_up_ALib_bumpBoostSysMSetStd_up


#include <libs/cxx_dual/test/test_library_name_include.hpp>

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_up_ut));
  
  BOOST_TEST
    (
    BOOST_VMD_EQUAL
        (
        CXXD_LIBRARY_NAME
            (
            ALib,
            (CXXD_UNORDERED_MAP,,_bump),
            (CXXD_TUPLE,,BoostSys),
            (CXXD_MODS_ALL,AllStd,AllBoost),
            (CXXD_UNORDERED_MULTISET,MSetStd,MSetBoost)
            ),
        ALib_bumpBoostSysMSetStd_up
        )
    );
    
  return boost::report_errors();
  }
