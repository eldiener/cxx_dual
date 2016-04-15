//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_LBN_HPP)
#define CXXD_DETAIL_LBN_HPP

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/logical/compl.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/punctuation/paren_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/remove.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/cxx_dual/detail/create_id_table.hpp>
#include <boost/cxx_dual/detail/library_name_register.hpp>
#include <boost/cxx_dual/detail/mod_append_table.hpp>
#include <boost/cxx_dual/detail/mods_all_register.hpp>
#include <boost/cxx_dual/detail/table_find.hpp>
#include <boost/cxx_dual/detail/table_read_rows.hpp>

#define CXXD_DETAIL_LIBRARY_NAME(...) \
    CXXD_DETAIL_LBN_PROC(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) \
/**/

#define CXXD_DETAIL_LBN_PROC(seq) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(seq),1), \
        CXXD_DETAIL_LBN_NOV, \
        CXXD_DETAIL_LBN_USER \
        ) \
    (seq) \
/**/

#define CXXD_DETAIL_LBN_NOV(seq) \
    CXXD_DETAIL_LBN_BN(BOOST_PP_SEQ_HEAD(seq)) \
/**/

#define CXXD_DETAIL_LBN_BN(bname) \
    CXXD_DETAIL_LBN_BN_IDT(bname,CXXD_DETAIL_CREATE_ID_TABLE()) \
/**/

#define CXXD_DETAIL_LBN_BN_IDT(bname,idt) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY(idt), \
            BOOST_VMD_IDENTITY(bname), \
            CXXD_DETAIL_LBN_BN_IDT_PROC \
            ) \
        (bname,idt) \
        ) \
/**/

#define CXXD_DETAIL_LBN_BN_IDT_PROC(bname,idt) \
    CXXD_DETAIL_LBN_BN_ALLRES(bname,idt,CXXD_DETAIL_LBN_IS_MODS_ALL(idt)) \
/**/

#define CXXD_DETAIL_LBN_BN_ALLRES(bname,idt,allres) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(allres), \
        CXXD_DETAIL_LBN_BN_APPEND, \
        CXXD_DETAIL_LBN_BN_ARESULT \
        ) \
    (bname,idt,allres) \
/**/

#define CXXD_DETAIL_LBN_BN_APPEND(bname,idt,ignore) \
    CXXD_DETAIL_LBN_NORM_PIDT(bname,idt,) \
/**/

#define CXXD_DETAIL_LBN_BN_ARESULT(bname,idt,allres) \
    CXXD_DETAIL_LBN_ALL_MKNAME(bname,allres,CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS()) \
/**/

/*

    Creates the library name when all included CXXD-mods are either
    all C++ standard implementation or Boost implementation.
    
    bname = base name
    allres = all C++ standard implementations if 1, all Boost implementations if 0
    tup_app = tuple for the append menmonics for all libraries
              where the first element is the C++ standard implementation append mnemonic
              and the second element is the Boost implementation append mnemonic

*/

#define CXXD_DETAIL_LBN_ALL_MKNAME(bname,allres,tup_app) \
    BOOST_PP_CAT \
        ( \
        bname, \
        BOOST_PP_TUPLE_ELEM \
            ( \
            BOOST_PP_COMPL(allres), \
            tup_app \
            ) \
        ) \
/**/

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

#define CXXD_DETAIL_LBN_IS_MODS_ALL(idt) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(BOOST_PP_TUPLE_SIZE(idt),1), \
        CXXD_DETAIL_LBN_IS_MODS_ALL_SINGLE, \
        CXXD_DETAIL_LBN_IS_MODS_ALL_MP \
        ) \
    (idt) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_SINGLE(idt) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        1, \
        BOOST_PP_TUPLE_ELEM(0,idt) \
        ) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_MP(idt) \
    CXXD_DETAIL_LBN_IS_MODS_ALL_STATE_RESULT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS \
            ( \
            idt, \
            (,), \
            CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC, \
            1 \
            ) \
        ) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC(d,row,state) \
    CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_VALUE \
        ( \
        CXXD_DETAIL_LBN_IS_MODS_ALL_ROW_VALUE(row), \
        state \
        ) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_VALUE(value,state) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(CXXD_DETAIL_LBN_IS_MODS_ALL_STATE_PREV(state)), \
        CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_FIRST, \
        CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_NORMAL \
        ) \
    (value,state) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_FIRST(value,ignore) \
    (0,(value,value)) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_RRMAC_NORMAL(value,state) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(value,CXXD_DETAIL_LBN_IS_MODS_ALL_STATE_PREV(state)), \
        (0,state), \
        (1,(value,)) \
        ) \
/**/

#define CXXD_DETAIL_LBN_IS_MODS_ALL_ROW_VALUE(row) BOOST_PP_TUPLE_ELEM(1,row)
#define CXXD_DETAIL_LBN_IS_MODS_ALL_STATE_PREV(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_LBN_IS_MODS_ALL_STATE_RESULT(state) BOOST_PP_TUPLE_ELEM(1,state)

/*

    Retrieves the CXXD_MODS_ALL append mnemonics as a two element tuple
    where the first element is the value for the C++ standard implementation
    and the second element is the value for the Boost implementation.
    
    ntup = user-defined tuple of 3-element tuples, may be emptiness
    
    first tuple element is CXXD-mod id
    second tuple element is append for C++ standard implementation, amy be emptiness
    third tuple element is append for Boost implementation, may be emptiness
    
    value for default CXXD_MODS_ALL append mnemonic is found in the CXXD_DETAIL_MOD_APPEND_TABLE
    and not hardcoded. This creates flexibility in favor of preprocessor speed.

*/

#define CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS(ntup) \
    CXXD_DETAIL_LBN_GET_MODS_ALL_RETRIEVE \
        ( \
        CXXD_DETAIL_FIND_DEFAULT_APPEND(CXXD_MODS_ALL), \
        CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER(ntup) \
        ) \
/**/

#define CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER(ntup) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_COMPL(BOOST_VMD_IS_EMPTY(ntup)), \
        CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER_TF, \
        BOOST_VMD_EMPTY \
        ) \
    (ntup) \
/**/

#define CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER_TF(ntup) \
    CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER_CHECK(CXXD_DETAIL_TABLE_FIND(ntup,0,CXXD_MODS_ALL,)) \
/**/

#define CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS_USER_CHECK(row) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_COMPL(BOOST_VMD_IS_EMPTY(row)), \
        BOOST_PP_TUPLE_REMOVE, \
        BOOST_VMD_EMPTY \
        ) \
    (row,0) \
/**/

#define CXXD_DETAIL_LBN_GET_MODS_ALL_RETRIEVE(defall,userall) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(userall), \
        (defall,), \
        userall \
        ) \
/**/

#define CXXD_DETAIL_LBN_USER(seq) \
    CXXD_DETAIL_LBN_NP \
        ( \
        BOOST_PP_SEQ_HEAD(seq), \
        BOOST_PP_SEQ_TAIL(seq) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NP(bname,seq) \
    CXXD_DETAIL_LBN_NP_IDT(bname,CXXD_DETAIL_CREATE_ID_TABLE(),seq) \
/**/

#define CXXD_DETAIL_LBN_NP_IDT(bname,idt,seq) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY(idt), \
            BOOST_VMD_IDENTITY(bname), \
            CXXD_DETAIL_LBN_NP_PROC \
            ) \
        (bname,idt,seq) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NP_PROC(bname,idt,seq) \
    CXXD_DETAIL_LBN_NORM(bname,idt,CXXD_DETAIL_LBN_NZSEQ(seq)) \
/**/

#define CXXD_DETAIL_LBN_NZSEQ(seq) \
    BOOST_PP_SEQ_FOR_EACH_I(CXXD_DETAIL_LBN_NZSEQ_MACRO,BOOST_PP_SEQ_SIZE(seq),seq) \
/**/

#define CXXD_DETAIL_LBN_NZSEQ_MACRO(r,size,index,elem) \
    BOOST_PP_LPAREN_IF(BOOST_PP_NOT(index)) \
    BOOST_PP_COMMA_IF(index) \
    CXXD_DETAIL_LBN_NZSEQ_MACRO_ELEM(elem,BOOST_PP_TUPLE_SIZE(elem)) \
    BOOST_PP_RPAREN_IF(BOOST_PP_EQUAL(size,BOOST_PP_INC(index))) \
/**/

#define CXXD_DETAIL_LBN_NZSEQ_MACRO_ELEM(elem,size) \
    ( \
    BOOST_PP_TUPLE_ELEM(0,elem), \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_GREATER(size,1), \
        BOOST_PP_TUPLE_ELEM, \
        BOOST_VMD_EMPTY \
        ) \
    (1,elem), \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_GREATER(size,2), \
        BOOST_PP_TUPLE_ELEM, \
        BOOST_VMD_EMPTY \
        ) \
    (2,elem) \
    ) \
/**/

#define CXXD_DETAIL_LBN_NORM(bname,idt,ntup) \
    CXXD_DETAIL_LBN_NORM_ALLRES(bname,idt,ntup,CXXD_DETAIL_LBN_IS_MODS_ALL(idt)) \
/**/

#define CXXD_DETAIL_LBN_NORM_ALLRES(bname,idt,ntup,allres) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(allres), \
        CXXD_DETAIL_LBN_NORM_PROCESS, \
        CXXD_DETAIL_LBN_NORM_ARESULT \
        ) \
    (bname,idt,ntup,allres) \
/**/

#define CXXD_DETAIL_LBN_NORM_ARESULT(bname,idt,ntup,allres) \
    CXXD_DETAIL_LBN_ALL_MKNAME(bname,allres,CXXD_DETAIL_LBN_GET_MODS_ALL_APPENDS(ntup)) \
/**/

#define CXXD_DETAIL_LBN_NORM_PROCESS(bname,idt,ntup,ignore) \
    CXXD_DETAIL_LBN_NORM_PIDT \
        ( \
        CXXD_DETAIL_LBN_NORM_PROCESS_DATA_BNAME \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS(ntup,(bname,idt),CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC) \
            ), \
        idt, \
        ntup \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PROCESS_DATA_BNAME(data) BOOST_PP_TUPLE_ELEM(0,data)
#define CXXD_DETAIL_LBN_NORM_PROCESS_DATA_IDT(data) BOOST_PP_TUPLE_ELEM(1,data)
#define CXXD_DETAIL_LBN_NORM_PROCESS_ROW_ID(row) BOOST_PP_TUPLE_ELEM(0,row)

#define CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC(d,row,data) \
    CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC_VALUE \
        ( \
        d, \
        row, \
        data, \
        CXXD_DETAIL_TABLE_FIND \
            ( \
            CXXD_DETAIL_LBN_NORM_PROCESS_DATA_IDT(data), \
            0, \
            CXXD_DETAIL_LBN_NORM_PROCESS_ROW_ID(row), \
            1 \
            ) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC_VALUE(d,row,data,value) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY(value), \
            BOOST_VMD_IDENTITY(data), \
            CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC_VALUE_REP \
            ) \
        (d,row,data,value) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PROCESS_RRMAC_VALUE_REP(d,row,data,value) \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        data, \
        0, \
        BOOST_PP_CAT \
            ( \
            CXXD_DETAIL_LBN_NORM_PROCESS_DATA_BNAME(data), \
            BOOST_PP_TUPLE_ELEM \
                ( \
                BOOST_PP_INC(BOOST_PP_COMPL(value)), \
                row \
                ) \
            ) \
        ) \
/**/

/*

    Loops through the ID table in order to append menmonics to the base name
    
    Returns the updated base name
    
    For each entry in the ID table first checks to make sure the ID is not
    in the user tuples, if it exists. If it is in the user tuples the
    entry has already been processed using the user appends. If the entry
    has not been processed checks to see if it is 1 for a C++ standard library
    append. If it is 1, adds the append mnemonic from the default append table
    to the base name.

*/

#define CXXD_DETAIL_LBN_NORM_PIDT(bname,idt,ntup) \
    CXXD_DETAIL_LBN_NORM_PIDT_DATA_BNAME \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS(idt,(bname,ntup),CXXD_DETAIL_LBN_NORM_PIDT_RRMAC) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PIDT_DATA_BNAME(data) BOOST_PP_TUPLE_ELEM(0,data)
#define CXXD_DETAIL_LBN_NORM_PIDT_DATA_NTUP(data) BOOST_PP_TUPLE_ELEM(1,data)
#define CXXD_DETAIL_LBN_NORM_PIDT_ROW_ID(row) BOOST_PP_TUPLE_ELEM(0,row)
#define CXXD_DETAIL_LBN_NORM_PIDT_ROW_VALUE(row) BOOST_PP_TUPLE_ELEM(1,row)

#define CXXD_DETAIL_LBN_NORM_PIDT_RRMAC(d,row,data) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(CXXD_DETAIL_LBN_NORM_PIDT_DATA_NTUP(data)), \
        CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_VALUE, \
        CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_NTUP \
        ) \
    (d,row,data) \
/**/

#define CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_VALUE(d,row,data) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            CXXD_DETAIL_LBN_NORM_PIDT_ROW_VALUE(row), \
            CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_VALUE_APPEND, \
            BOOST_VMD_IDENTITY(data) \
            ) \
        (d,row,data) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_VALUE_APPEND(d,row,data) \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        data, \
        0, \
        BOOST_PP_CAT \
            ( \
            CXXD_DETAIL_LBN_NORM_PIDT_DATA_BNAME(data), \
            CXXD_DETAIL_FIND_DEFAULT_APPEND(CXXD_DETAIL_LBN_NORM_PIDT_ROW_ID(row)) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_NTUP(d,row,data) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY \
                ( \
                CXXD_DETAIL_TABLE_FIND \
                    ( \
                    CXXD_DETAIL_LBN_NORM_PIDT_DATA_NTUP(data), \
                    0, \
                    CXXD_DETAIL_LBN_NORM_PIDT_ROW_ID(row) \
                    ) \
                ), \
            CXXD_DETAIL_LBN_NORM_PIDT_RRMAC_CHECK_VALUE, \
            BOOST_VMD_IDENTITY(data) \
            ) \
        (d,row,data) \
        ) \
/**/

#endif // !defined(CXXD_DETAIL_LBN_HPP)
