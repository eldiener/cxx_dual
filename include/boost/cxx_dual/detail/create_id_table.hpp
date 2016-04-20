//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
#define CXXD_DETAIL_CREATE_ID_TABLE_HPP

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_number.hpp>
#include <boost/vmd/tuple/push_back.hpp>
#include <boost/cxx_dual/detail/mod_table.hpp>
#include <boost/cxx_dual/detail/table_read_rows.hpp>

/*

    Expands to a table of all included CXXD-mods
    
    The table consists of: 
        CXXD mod id
        0 or 1, for Boost implementation or C++ standard implementation respectively

*/

#define CXXD_DETAIL_CREATE_ID_TABLE() \
    CXXD_DETAIL_TABLE_READ_ROWS(CXXD_DETAIL_MOD_TABLE,,CXXD_DETAIL_CREATE_ID_TABLE_RRMAC) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_RRMAC(d,row,state) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_NUMBER(CXXD_DETAIL_CREATE_ID_TABLE_ROW_VALUE(row)), \
            CXXD_DETAIL_CREATE_ID_TABLE_RRMAC_RES, \
            BOOST_VMD_IDENTITY(state) \
            ) \
        (row,state) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_RRMAC_RES(row,state) \
    BOOST_VMD_TUPLE_PUSH_BACK \
        ( \
        state, \
            ( \
            CXXD_DETAIL_CREATE_ID_TABLE_ROW_ID(row), \
            CXXD_DETAIL_CREATE_ID_TABLE_ROW_VALUE(row) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_ROW_ID(row) BOOST_PP_TUPLE_ELEM(0,row)
#define CXXD_DETAIL_CREATE_ID_TABLE_ROW_VALUE(row) BOOST_PP_TUPLE_ELEM(1,row)

/*

    Retrieves whether all included mods have the C++ standard implementation set
    or the Boost implementation set or neither case
    
    idt = processed id table containing only are valid included values
          where a value for an included CXXD-mod is either 1 for the
          C++ standard implementation or 0 for the Boost implementation
          
    expands to 1 if all CXXD-mods use the C++ standard implementation
               0 if all CXXD-mods use the Boost implementation
               otherwise emptiness

*/

#define CXXD_DETAIL_IDT_IS_MODS_ALL(idt) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(BOOST_PP_TUPLE_SIZE(idt),1), \
        CXXD_DETAIL_IDT_IS_MODS_ALL_SINGLE, \
        CXXD_DETAIL_IDT_IS_MODS_ALL_MP \
        ) \
    (idt) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_D(d,idt) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(BOOST_PP_TUPLE_SIZE(idt),1), \
        CXXD_DETAIL_IDT_IS_MODS_ALL_SINGLE_D, \
        CXXD_DETAIL_IDT_IS_MODS_ALL_MP_D \
        ) \
    (d,idt) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_SINGLE(idt) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        1, \
        BOOST_PP_TUPLE_ELEM(0,idt) \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_SINGLE_D(ignore,idt) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        1, \
        BOOST_PP_TUPLE_ELEM(0,idt) \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_MP(idt) \
    CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_RESULT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS \
            ( \
            idt, \
            (,), \
            CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC, \
            1 \
            ) \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_MP_D(d,idt) \
    CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_RESULT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_D \
            ( \
            d, \
            idt, \
            (,), \
            CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC, \
            1 \
            ) \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC(d,row,state) \
    CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_VALUE \
        ( \
        CXXD_DETAIL_IDT_IS_MODS_ALL_ROW_VALUE(row), \
        state \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_VALUE(value,state) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_PREV(state)), \
        CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_FIRST, \
        CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_NORMAL \
        ) \
    (value,state) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_FIRST(value,ignore) \
    (1,(value,value)) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_RRMAC_NORMAL(value,state) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(value,CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_PREV(state)), \
        (1,state), \
        (0,(value,)) \
        ) \
/**/

#define CXXD_DETAIL_IDT_IS_MODS_ALL_ROW_VALUE(row) BOOST_PP_TUPLE_ELEM(1,row)
#define CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_PREV(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_IDT_IS_MODS_ALL_STATE_RESULT(state) BOOST_PP_TUPLE_ELEM(1,state)

#endif // !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
