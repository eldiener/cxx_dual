
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/preprocessor/config/config.hpp>

#if !BOOST_PP_VARIADICS

#error Variadic macros must be supported for test_valid_variants7 test

#else

#define CXXD_NO_CONFIG

#include <boost/detail/lightweight_test.hpp>
#include <boost/cxx_dual/valid_variants.hpp>

#define CXXD_REGEX_USE_BOOST
#define CXXD_SYSTEM_USE_BOOST
#define CXXD_TUPLE_USE_BOOST
#define CXXD_UNORDERED_MAP_USE_BOOST
#define CXXD_UNORDERED_MULTIMAP_USE_STD
#define CXXD_UNORDERED_MULTISET_USE_STD
#define CXXD_UNORDERED_SET_USE_BOOST

#include <boost/cxx_dual/regex.hpp>
#include <boost/cxx_dual/system.hpp>
#include <boost/cxx_dual/tuple.hpp>
#include <boost/cxx_dual/unordered_map.hpp>
#include <boost/cxx_dual/unordered_multimap.hpp>
#include <boost/cxx_dual/unordered_multiset.hpp>
#include <boost/cxx_dual/unordered_set.hpp>

int main()
  {
  
  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_UNORDERED_MAP,1)(CXXD_TUPLE,0)(CXXD_UNORDERED_MULTISET,1),
        (CXXD_UNORDERED_SET,0)(CXXD_SYSTEM,1)(CXXD_TUPLE,0),
        (CXXD_UNORDERED_MULTISET,1)(CXXD_UNORDERED_MAP,0)(CXXD_TUPLE,0)(CXXD_UNORDERED_MULTIMAP,1)(CXXD_UNORDERED_SET,0),
        (CXXD_UNORDERED_MULTIMAP,1)(CXXD_REGEX,1)(CXXD_TUPLE,0)
        )
    );
    
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_UNORDERED_MAP,1)(CXXD_TUPLE,0)(CXXD_UNORDERED_MULTISET,1),
        (CXXD_UNORDERED_MULTISET,1)(CXXD_UNORDERED_MAP,0)(CXXD_TUPLE,1)(CXXD_UNORDERED_MULTIMAP,1)(CXXD_UNORDERED_SET,0),
        (CXXD_UNORDERED_SET,0)(CXXD_SYSTEM,1)(CXXD_TUPLE,0),
        (CXXD_UNORDERED_MULTIMAP,1)(CXXD_REGEX,1)(CXXD_TUPLE,0)
        )
    );
    
  return boost::report_errors();
  }

#endif
