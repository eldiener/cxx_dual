
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_valid_variants5 test

#else

#define CXXD_NO_CONFIG

#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

#define CXXD_HASH_USE_BOOST
#define CXXD_RANDOM_USE_BOOST
#define CXXD_RATIO_USE_BOOST
#define CXXD_REF_USE_STD
#define CXXD_REGEX_USE_STD
#define CXXD_SHARED_MUTEX_USE_STD
#define CXXD_SHARED_PTR_USE_BOOST

#include <boost/cxx_dual/impl/hash.hpp>
#include <boost/cxx_dual/impl/random.hpp>
#include <boost/cxx_dual/impl/ratio.hpp>
#include <boost/cxx_dual/impl/ref.hpp>
#include <boost/cxx_dual/impl/regex.hpp>
#include <boost/cxx_dual/impl/shared_mutex.hpp>
#include <boost/cxx_dual/impl/shared_ptr.hpp>

int main()
  {
  
  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_REF,1)(CXXD_REGEX,1)(CXXD_SHARED_MUTEX,1)(CXXD_HASH,1)(CXXD_SHARED_PTR,0)(CXXD_RANDOM,0),
        (CXXD_MODS_ALL,0),
        (CXXD_RATIO,0)(CXXD_REF,1)(CXXD_REGEX,1)(CXXD_SHARED_MUTEX,1)(CXXD_SHARED_PTR,0)(CXXD_RANDOM,0)
        )
    );
    
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_REF,1)(CXXD_REGEX,1)(CXXD_SHARED_MUTEX,1)(CXXD_HASH,1)(CXXD_SHARED_PTR,0)(CXXD_RANDOM,0),
        (CXXD_MODS_ALL,0),
        (CXXD_RATIO,0)(CXXD_REF,1)(CXXD_REGEX,1)(CXXD_SHARED_MUTEX,1)(CXXD_SHARED_PTR,1)(CXXD_RANDOM,0)
        )
    );
    
  return boost::report_errors();
  }

#endif
  