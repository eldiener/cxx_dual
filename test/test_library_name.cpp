
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_library_name test

#else

#define CXXD_NO_CONFIG

#include <boost/vmd/equal.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/library_name.hpp>

#define CXXD_ARRAY_USE_BOOST
#define CXXD_ATOMIC_USE_STD
#define CXXD_BIND_USE_BOOST
#define CXXD_CHRONO_USE_STD
#define CXXD_CONDITION_VARIABLE_USE_STD

#include <boost/cxx_dual/array.hpp>
#include <boost/cxx_dual/atomic.hpp>
#include <boost/cxx_dual/bind.hpp>
#include <boost/cxx_dual/chrono.hpp>
#include <boost/cxx_dual/condition_variable.hpp>

int main()
  {
  
#define BOOST_VMD_REGISTER_ALib_at_ch_cv (ALib_at_ch_cv)
#define BOOST_VMD_DETECT_ALib_at_ch_cv_ALib_at_ch_cv
#define BOOST_VMD_REGISTER_ALib_arrayBoostChStandard_at_cv (ALib_arrayBoostChStandard_at_cv)
#define BOOST_VMD_DETECT_ALib_arrayBoostChStandard_at_cv_ALib_arrayBoostChStandard_at_cv

  BOOST_TEST(BOOST_VMD_EQUAL(CXXD_LIBRARY_NAME(ALib),ALib_at_ch_cv));
  
  BOOST_TEST
    (
    BOOST_VMD_EQUAL
        (
        CXXD_LIBRARY_NAME
            (
            ALib,
            (CXXD_BIND,StandardBind,),
            (CXXD_ARRAY,_arrayStandard,_arrayBoost),
            (CXXD_CHRONO,ChStandard,ChBoost)
            ),
        ALib_arrayBoostChStandard_at_cv
        )
    );
    
  return boost::report_errors();
  }

#endif
