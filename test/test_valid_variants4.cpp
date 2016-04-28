
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG

#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

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
  
  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_MODS_ALL,0),
        (CXXD_FUNCTION,1)(CXXD_MEM_FN,1)(CXXD_MUTEX,0),
        (CXXD_FUNCTION,1)(CXXD_HASH,0)(CXXD_MEM_FN,0)(CXXD_MUTEX,0)(CXXD_RANDOM,1)
        )
    );
    
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_FUNCTION,1)(CXXD_MEM_FN,0)(CXXD_MUTEX,0)(CXXD_TUPLE,1),
        (CXXD_MODS_ALL,1),
        (CXXD_FUNCTION,1)(CXXD_HASH,0)(CXXD_MEM_FN,0)(CXXD_MUTEX,1)(CXXD_RANDOM,1)
        )
    );
    
  return boost::report_errors();
  }
