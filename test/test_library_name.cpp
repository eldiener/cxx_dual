
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#define CXXD_ARRAY_USE_BOOST
// #define CXXD_ARRAY_USE_STD
#include <boost/cxx_dual/array.hpp>
// #define CXXD_ATOMIC_USE_BOOST
#define CXXD_ATOMIC_USE_STD
#include <boost/cxx_dual/atomic.hpp>
// #define CXXD_BIND_USE_BOOST
// #define CXXD_BIND_USE_STD
#include <boost/cxx_dual/bind.hpp>
// #define CXXD_CHRONO_USE_BOOST
// #define CXXD_CHRONO_USE_STD
#include <boost/cxx_dual/chrono.hpp>
// #define CXXD_CONDITION_VARIABLE_USE_BOOST
#define CXXD_CONDITION_VARIABLE_USE_STD
#include <boost/cxx_dual/condition_variable.hpp>
// #define CXXD_FUNCTION_USE_BOOST
// #define CXXD_FUNCTION_USE_STD
// #include <boost/cxx_dual/function.hpp>
// #define CXXD_HASH_USE_BOOST
// #define CXXD_HASH_USE_STD
// #include <boost/cxx_dual/hash.hpp>
// #define CXXD_MEM_FN_USE_BOOST
// #define CXXD_MEM_FN_USE_STD
// #include <boost/cxx_dual/mem_fn.hpp>
// #define CXXD_MUTEX_USE_BOOST
// #define CXXD_MUTEX_USE_STD
// #include <boost/cxx_dual/mutex.hpp>
// #define CXXD_RANDOM_USE_BOOST
// #define CXXD_RANDOM_USE_STD
// #include <boost/cxx_dual/random.hpp>
// #define CXXD_RATIO_USE_BOOST
// #define CXXD_RATIO_USE_STD
// #include <boost/cxx_dual/ratio.hpp>
// #define CXXD_REF_USE_BOOST
// #define CXXD_REF_USE_STD
// #include <boost/cxx_dual/ref.hpp>
// #define CXXD_REGEX_USE_BOOST
// #define CXXD_REGEX_USE_STD
// #include <boost/cxx_dual/regex.hpp>
// #define CXXD_SHARED_MUTEX_USE_BOOST
// #define CXXD_SHARED_MUTEX_USE_STD
// #include <boost/cxx_dual/shared_mutex.hpp>
// #define CXXD_SHARED_PTR_USE_BOOST
// #define CXXD_SHARED_PTR_USE_STD
// #include <boost/cxx_dual/shared_ptr.hpp>
// #define CXXD_SYSTEM_USE_BOOST
// #define CXXD_SYSTEM_USE_STD
// #include <boost/cxx_dual/system.hpp>
// #define CXXD_THREAD_USE_BOOST
// #define CXXD_THREAD_USE_STD
// #include <boost/cxx_dual/thread.hpp>
// #define CXXD_TUPLE_USE_BOOST
// #define CXXD_TUPLE_USE_STD
// #include <boost/cxx_dual/tuple.hpp>
// #define CXXD_TYPE_INDEX_USE_BOOST
// #define CXXD_TYPE_INDEX_USE_STD
// #include <boost/cxx_dual/type_index.hpp>
// #define CXXD_TYPE_TRAITS_USE_BOOST
// #define CXXD_TYPE_TRAITS_USE_STD
// #include <boost/cxx_dual/type_traits.hpp>
// #define CXXD_UNORDERED_MAP_USE_BOOST
// #define CXXD_UNORDERED_MAP_USE_STD
// #include <boost/cxx_dual/unordered_map.hpp>
// #define CXXD_UNORDERED_MULTIMAP_USE_BOOST
// #define CXXD_UNORDERED_MULTIMAP_USE_STD
// #include <boost/cxx_dual/unordered_multimap.hpp>
// #define CXXD_UNORDERED_MULTISET_USE_BOOST
// #define CXXD_UNORDERED_MULTISET_USE_STD
// #include <boost/cxx_dual/unordered_multiset.hpp>
// #define CXXD_UNORDERED_SET_USE_BOOST
// #define CXXD_UNORDERED_SET_USE_STD
// #include <boost/cxx_dual/unordered_set.hpp>

#include <boost/preprocessor/tuple/size.hpp>
#include <boost/cxx_dual/detail/create_id_table.hpp>
#include <boost/cxx_dual/detail/library_name_register.hpp>
#include <boost/cxx_dual/detail/mods_all_register.hpp>
#include <boost/cxx_dual/detail/table_find.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  BOOST_TEST_EQ(BOOST_PP_TUPLE_SIZE(CXXD_DETAIL_CREATE_ID_TABLE()),5);
  BOOST_TEST_EQ(CXXD_DETAIL_TABLE_FIND(CXXD_DETAIL_CREATE_ID_TABLE(),0,CXXD_ARRAY,1),0);
  return boost::report_errors();
  }
