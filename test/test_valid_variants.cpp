
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_NO_CONFIG
#define CXXD_NO_CONSISTENCY

#include <boost/cxx_dual/valid_variants.hpp>
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

#include <boost/cxx_dual/cxx_mods.hpp>

  BOOST_TEST
    (
    CXXD_VALID_VARIANTS
        (
        (CXXD_ARRAY,0)(CXXD_BIND,0)(CXXD_CHRONO,0)(CXXD_CONDITION_VARIABLE,1),
        (CXXD_MODS_ALL,0),
        (CXXD_CHRONO,1)(CXXD_ATOMIC,1)(CXXD_BIND,0)
        )
    );
  
  BOOST_TEST
    (
    !
    CXXD_VALID_VARIANTS
        (
        (CXXD_ARRAY,0)(CXXD_BIND,0)(CXXD_CHRONO,0)(CXXD_CONDITION_VARIABLE,1),
        (CXXD_MODS_ALL,0),
        (CXXD_CHRONO,1)(CXXD_ATOMIC,1)(CXXD_BIND,1)
        )
    );
  
#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

#include <libs/cxx_dual/test/test_override_reset.hpp>

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

#include <libs/cxx_dual/test/test_re_include.hpp>

  return boost::report_errors();
  }
