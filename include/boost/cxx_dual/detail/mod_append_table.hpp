//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_MOD_APPEND_TABLE_HPP)
#define CXXD_DETAIL_MOD_APPEND_TABLE_HPP

#include <boost/cxx_dual/detail/table_find.hpp>
#include <boost/cxx_dual/detail/library_name_register.hpp>
#include <boost/cxx_dual/detail/mods_all_register.hpp>
#include <boost/cxx_dual/detail/mod_append_table_pre.hpp>

#define CXXD_DETAIL_MOD_APPEND_TABLE \
    ( \
    (CXXD_ARRAY,_ar), \
    (CXXD_ATOMIC,_at), \
    (CXXD_BIND,_bd), \
    (CXXD_CHRONO,_ch), \
    (CXXD_CONDITION_VARIABLE,_cv), \
    (CXXD_ENABLE_SHARED_FROM_THIS,_es), \
    (CXXD_FUNCTION,_fn), \
    (CXXD_HASH,_ha), \
    (CXXD_MAKE_SHARED,_ms), \
    (CXXD_MEM_FN,_mf), \
    (CXXD_MOVE,_mv), \
    (CXXD_MUTEX,_mx), \
    (CXXD_RANDOM,_rd), \
    (CXXD_RATIO,_ra), \
    (CXXD_REF,_rf), \
    (CXXD_REGEX,_rx), \
    (CXXD_SHARED_MUTEX,_sm), \
    (CXXD_SHARED_PTR,_sp), \
    (CXXD_SYSTEM_ERROR,_se), \
    (CXXD_THREAD,_th), \
    (CXXD_TUPLE,_tu), \
    (CXXD_TYPE_INDEX,_ti), \
    (CXXD_TYPE_TRAITS,_tt), \
    (CXXD_UNORDERED_MAP,_um), \
    (CXXD_UNORDERED_MULTIMAP,_up), \
    (CXXD_UNORDERED_MULTISET,_ut), \
    (CXXD_UNORDERED_SET,_us), \
    (CXXD_WEAK_PTR,_wp), \
    (CXXD_MODS_ALL,_std) \
    ) \
/**/

/*

    Finds the default append mnemonic for a specific mod id
    
    modid = mod id to look for in the mod append table
    
    expands to append mnemonic or emptiness if mod id not valid

*/

#define CXXD_DETAIL_FIND_DEFAULT_APPEND(modid) \
    CXXD_DETAIL_TABLE_FIND(CXXD_DETAIL_MOD_APPEND_TABLE,0,modid,1) \
/**/

#endif // !defined(CXXD_DETAIL_MOD_APPEND_TABLE_HPP)
