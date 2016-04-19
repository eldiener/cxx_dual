//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_VALID_VARIANTS_HPP)
#define CXXD_DETAIL_VALID_VARIANTS_HPP

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/vmd/equal.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/to_tuple.hpp>
#include <boost/cxx_dual/detail/create_id_table.hpp>
#include <boost/cxx_dual/detail/library_name_register.hpp>
#include <boost/cxx_dual/detail/mods_all_register.hpp>
#include <boost/cxx_dual/detail/table_find.hpp>
#include <boost/cxx_dual/detail/table_read_rows.hpp>

#define CXXD_DETAIL_VALID_VARIANTS(...) \
    CXXD_DETAIL_VV_TABLE(BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__)) \
/**/

#define CXXD_DETAIL_VV_STATE_RESULT(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_VV_STATE_IDT(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_VV_STATE_IDT_MODS_ALL_RESULT(state) BOOST_PP_TUPLE_ELEM(2,state)

#define CXXD_DETAIL_VV_TABLE(tbl) \
    CXXD_DETAIL_VV_STATE_RESULT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS(tbl,(0,CXXD_DETAIL_CREATE_ID_TABLE(),2),CXXD_DETAIL_VV_RRMAC,1) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC(d,row,state) \
    CXXD_DETAIL_VV_RRMAC_IDT \
        ( \
        d, \
        row, \
        CXXD_DETAIL_VV_STATE_IDT(state), \
        CXXD_DETAIL_VV_STATE_IDT_MODS_ALL_RESULT(state) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_IDT(d,row,idt,imres) \
    CXXD_DETAIL_VV_RRMAC_RES \
        ( \
        idt, \
        CXXD_DETAIL_VV_RRMAC_TABLE \
            ( \
            d, \
            BOOST_VMD_TO_TUPLE(row), \
            idt, \
            imres \
            ) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_RES_RESULT(res) BOOST_PP_TUPLE_ELEM(0,res)
#define CXXD_DETAIL_VV_RRMAC_RES_MRES(res) BOOST_PP_TUPLE_ELEM(1,res)

/*

    Returns the result for the combination
    
    idt = ID table
    res = result of the combination as a two element tuple
   
    The return is a tuple
        The first tuple element is 1 to stop reading further rows 
        or 0 to continue reading further rows.
        The second tuple element is a tuple
            The first element is 1 for a valid combination or 0 for an invalid combination
            The second element is the idt
            The third element is a possibly updated idt mods all setting.

*/

#define CXXD_DETAIL_VV_RRMAC_RES(idt,res) \
    BOOST_PP_IIF \
        ( \
        CXXD_DETAIL_VV_RRMAC_RES_RESULT(res), \
        (1,(1,,)), \
        (0,(0,idt,CXXD_DETAIL_VV_RRMAC_RES_MRES(res))) \
        ) \
/**/

/*
    
    Returns whether a particular combination is true (1) or false (0)
    
    tbl = combination where each tuple is a row in the table
    idt = included id table
    imres = mods all result
            2 = not yet retrieved
            0 = all Boost
            1 = a;; Standard
            empty = mixed
            
    returns a two-element tuple
            the first element is 1 or 0 depending on whether the combination is true or false
            the second element is a possibly updated 'imres'
    
*/

#define CXXD_DETAIL_VV_RRMAC_TABLE(d,tbl,idt,imres) \
    CXXD_DETAIL_VV_RRMAC_MALL_RES(d,tbl,idt,CXXD_DETAIL_VV_RRMAC_MALL(d,tbl),imres) \
/**/

/*

    Chcks whether there is a CXXD_MODS_ALL tuple in the combination
    
    returns 1 or 0 for the CXXD_MODS_ALL setting 
        or emptiness if no CXXD_MODS_ALL tuple in the combination

*/

#define CXXD_DETAIL_VV_RRMAC_MALL(d,tbl) \
    CXXD_DETAIL_TABLE_FIND_D(d,tbl,0,CXXD_MODS_ALL,1) \
/**/

/*

    Returns whether a particular combination is true (1) or false (0)
    
    tbl = table of combinations
    idt = id table
    mall = value for CXXD_MODS_ALL in combination or empty if no CXXD_MODS_ALL in combination
    imres = idt mods all value

    returns a two-element tuple
            the first element is 1 or 0 depending on whether the combination is true or false
            the second element is a possibly updated 'imres'
    
*/

#define CXXD_DETAIL_VV_RRMAC_MALL_RES(d,tbl,idt,mall,imres) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(mall), \
        CXXD_DETAIL_VV_RRMAC_NORM, \
        CXXD_DETAIL_VV_RRMAC_MCHECK \
        ) \
    (d,tbl,idt,mall,imres) \
/**/

/*

    Returns whether a particular combination is true (1) or false (0)
    
    (CXXD_MODS_ALL,0 or 1) has been found in the combination
    mall is 0 or 1 for CXXD_MODS
    imres is the result of all the mods in the idt table:
            2 = not yet retrieved
            0 = all Boost
            1 = a;; Standard
            empty = mixed

    returns a two-element tuple
            the first element is 1 or 0 depending on whether the combination is true or false
            the second element is a possibly updated 'imres'
    
*/

#define CXXD_DETAIL_VV_RRMAC_MCHECK(d,ignore,idt,mall,imres) \
    CXXD_DETAIL_VV_RRMAC_MCHECK_WITH_IM \
        ( \
        mall, \
        CXXD_DETAIL_VV_RRMAC_MCHECK_GET(d,idt,imres) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_MCHECK_WITH_IM(mall,imres) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_EQUAL(mall,imres), \
        (1,), \
        (0,imres) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_MCHECK_GET(d,idt,imres) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_EQUAL(imres,2), \
            CXXD_DETAIL_VV_RRMAC_MCHECK_DO_GET, \
            BOOST_VMD_IDENTITY(imres) \
            ) \
        (d,idt) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_MCHECK_DO_GET(d,idt) \
    CXXD_DETAIL_IDT_IS_MODS_ALL_D(d,idt) \
/**/

/*

    Returns whether a particular combination is true (1) or false (0)
    
    (CXXD_MODS_ALL,0 or 1) has not been found in the combination
    imres is the result of all the mods in the idt table:
            2 = not yet retrieved
            0 = all Boost
            1 = a;; Standard
            empty = mixed

    returns a two-element tuple
            the first element is 1 or 0 depending on whether the combination is true or false
            the second element is 'imres'
    
*/


#define CXXD_DETAIL_VV_RRMAC_NORM(d,tbl,idt,ignore,imres) \
    ( \
    CXXD_DETAIL_VV_RRMAC_NORM_STATE_RET \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_D(d,tbl,(0,idt),CXXD_DETAIL_VV_RRMAC_NORM_RRMAC,1) \
        ), \
    imres \
    ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_NORM_STATE_RET(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_VV_RRMAC_NORM_STATE_IDT(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_VV_RRMAC_NORM_ROW_ID(row) BOOST_PP_TUPLE_ELEM(0,row)
#define CXXD_DETAIL_VV_RRMAC_NORM_ROW_VALUE(row) BOOST_PP_TUPLE_ELEM(1,row)

#define CXXD_DETAIL_VV_RRMAC_NORM_RRMAC(d,row,data) \
    CXXD_DETAIL_VV_RRMAC_NORM_RRMAC_IDT(d,row,CXXD_DETAIL_VV_RRMAC_NORM_STATE_IDT(data)) \
/**/

#define CXXD_DETAIL_VV_RRMAC_NORM_RRMAC_IDT(d,row,idt) \
    CXXD_DETAIL_VV_RRMAC_NORM_RRMAC_IDT_FV \
        ( \
        row, \
        idt, \
        CXXD_DETAIL_TABLE_FIND_D(d,idt,0,CXXD_DETAIL_VV_RRMAC_NORM_ROW_ID(row),1) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_NORM_RRMAC_IDT_FV(row,idt,fv) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY(fv), \
            BOOST_VMD_IDENTITY((1,(0,))), \
            CXXD_DETAIL_VV_RRMAC_NORM_MATCH \
            ) \
        (row,idt,fv) \
        ) \
/**/

#define CXXD_DETAIL_VV_RRMAC_NORM_MATCH(row,idt,fv) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL \
            ( \
            fv, \
            CXXD_DETAIL_VV_RRMAC_NORM_ROW_VALUE(row) \
            ), \
        (0,(1,idt)), \
        (1,(0,)) \
        ) \
/**/

#endif // !defined(CXXD_DETAIL_VALID_VARIANTS_HPP)
