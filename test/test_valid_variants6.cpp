
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_valid_variants6 test

#else

#define CXXD_NO_CONFIG

#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

#define CXXD_RATIO_USE_BOOST
#define CXXD_REF_USE_BOOST
#define CXXD_SHARED_MUTEX_USE_BOOST
#define CXXD_SHARED_PTR_USE_BOOST
#define CXXD_SYSTEM_ERROR_USE_STD
#define CXXD_THREAD_USE_STD
#define CXXD_TUPLE_USE_BOOST
#define CXXD_TYPE_INDEX_USE_STD
#define CXXD_TYPE_TRAITS_USE_STD

#include <boost/cxx_dual/impl/ratio.hpp>
#include <boost/cxx_dual/impl/ref.hpp>
#include <boost/cxx_dual/impl/shared_mutex.hpp>
#include <boost/cxx_dual/impl/shared_ptr.hpp>
#include <boost/cxx_dual/impl/system_error.hpp>
#include <boost/cxx_dual/impl/thread.hpp>
#include <boost/cxx_dual/impl/tuple.hpp>
#include <boost/cxx_dual/impl/type_index.hpp>
#include <boost/cxx_dual/impl/type_traits.hpp>

int main()
  {
  
  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_SYSTEM_ERROR,1)(CXXD_THREAD,1)(CXXD_TUPLE,1),
        (CXXD_SYSTEM_ERROR,1)(CXXD_THREAD,1)(CXXD_TUPLE,0)(CXXD_TYPE_INDEX,1)(CXXD_RATIO,0)(CXXD_REF,0)(CXXD_SHARED_MUTEX,0)(CXXD_SHARED_PTR,0)(CXXD_TYPE_TRAITS,1),
        (CXXD_MODS_ALL,1)
        )
    );
    
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_MODS_ALL,1),
        (CXXD_SYSTEM_ERROR,1)(CXXD_THREAD,1)(CXXD_TUPLE,1),
        (CXXD_SYSTEM_ERROR,1)(CXXD_THREAD,1)(CXXD_TUPLE,0)(CXXD_TYPE_INDEX,1)(CXXD_RATIO,0)(CXXD_REF,1)(CXXD_SHARED_MUTEX,0)(CXXD_SHARED_PTR,0)(CXXD_TYPE_TRAITS,1)
        )
    );
    
  return boost::report_errors();
  }

#endif
  