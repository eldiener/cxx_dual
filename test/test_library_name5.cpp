
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>

#define CXXD_RATIO_USE_BOOST
#define CXXD_REF_USE_STD
#define CXXD_REGEX_USE_STD
#define CXXD_SHARED_MUTEX_USE_STD
#define CXXD_SHARED_PTR_USE_BOOST

#include <boost/cxx_dual/ratio.hpp>
#include <boost/cxx_dual/ref.hpp>
#include <boost/cxx_dual/regex.hpp>
#include <boost/cxx_dual/shared_mutex.hpp>
#include <boost/cxx_dual/shared_ptr.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_rf_rx_sm (ALib_rf_rx_sm)
#define BOOST_VMD_DETECT_ALib_rf_rx_sm_ALib_rf_rx_sm
#define BOOST_VMD_REGISTER_ALibSSM_srefRatioBoost_rx (ALibSSM_srefRatioBoost_rx)
#define BOOST_VMD_DETECT_ALibSSM_srefRatioBoost_rx_ALibSSM_srefRatioBoost_rx

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

    
  return boost::report_errors();
  }
