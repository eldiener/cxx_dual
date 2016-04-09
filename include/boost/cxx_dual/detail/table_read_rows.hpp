//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TABLE_READ_ROWS_HPP)
#define CXXD_DETAIL_TABLE_READ_ROWS_HPP

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/logical/compl.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>

/*

    Reads each row in a table.
    
    A table is a tuple whose elements are tuples of the same tuple size.
    Therefore the table's rows are the individual tuples.
    
    table = the table to read.
    data = initial data when reading.
    ...  = variadic data
           The first required variadic parameter is:
           
               macro = macro to be called when reading each row.
                       the macro is of the form:
                
                       macro(d,row,data)
                    
                       where d    = the BOOST_PP_WHILE iteration
                             row  = the rwo of the table
                             data = transformed data
                          
                       if the second optional parameter is 0 ( the default )
                       the macro returns the new data
                       
                       if the second optional parameter is 1
                       the macro returns a tuple where the first
                       tuple element is 1 ( stop reading ) or 0 ( continue reading ),
                       and the second tuple element is the new data.
                       
           The second optional variadic parameter is:
               
               0 = read all rows, the default
               1 = may stop before reading all rows
            
    The entire macro returns the final data.
            
*/

#define CXXD_DETAIL_TABLE_READ_ROWS(table,data,...) \
    CXXD_DETAIL_TABLE_READ_ROWS_VD(table,data,__VA_ARGS__) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_D(d,table,data,...) \
    CXXD_DETAIL_TABLE_READ_ROWS_VD_D(d,table,data,__VA_ARGS__) \
/**/

#if BOOST_PP_VARIADICS_MSVC

#define CXXD_DETAIL_TABLE_READ_ROWS_VD(table,data,...) \
    BOOST_PP_CAT \
        ( \
        BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_READ_ROWS_V,__VA_ARGS__)(table,data,__VA_ARGS__), \
        BOOST_PP_EMPTY() \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_VD_D(d,table,data,...) \
    BOOST_PP_CAT \
        ( \
        BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_READ_ROWS_D_V,__VA_ARGS__)(d,table,data,__VA_ARGS__), \
        BOOST_PP_EMPTY() \
        ) \
/**/

#else

#define CXXD_DETAIL_TABLE_READ_ROWS_VD(table,data,...) \
    BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_READ_ROWS_V,__VA_ARGS__)(table,data,__VA_ARGS__) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_VD_D(d,table,data,...) \
    BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_READ_ROWS_D_V,__VA_ARGS__)(d,table,data,__VA_ARGS__) \
/**/

#endif

#define CXXD_DETAIL_TABLE_READ_ROWS_V1(table,data,macro) \
    CXXD_DETAIL_TABLE_READ_ROWS_STOP(table,data,macro,0) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_V2(table,data,macro,stop) \
    CXXD_DETAIL_TABLE_READ_ROWS_STOP(table,data,macro,stop) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_D_V1(d,table,data,macro) \
    CXXD_DETAIL_TABLE_READ_ROWS_STOP_D(d,table,data,macro,0) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_D_V2(d,table,data,macro,stop) \
    CXXD_DETAIL_TABLE_READ_ROWS_STOP_D(d,table,data,macro,stop) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_STOP(table,data,macro,stop) \
    CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA \
        ( \
        BOOST_PP_WHILE \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS_PRED, \
            CXXD_DETAIL_TABLE_READ_ROWS_OP, \
            (table,0,BOOST_PP_TUPLE_SIZE(table),macro,data,stop,0) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_STOP_D(d,table,data,macro,stop) \
    CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA \
        ( \
        BOOST_PP_WHILE_ ## d \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS_PRED, \
            CXXD_DETAIL_TABLE_READ_ROWS_OP, \
            (table,0,BOOST_PP_TUPLE_SIZE(table),macro,data,stop,0) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_TABLE(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_SIZE(state) BOOST_PP_TUPLE_ELEM(2,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_MACRO(state) BOOST_PP_TUPLE_ELEM(3,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA(state) BOOST_PP_TUPLE_ELEM(4,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_ALLOW_STOP(state) BOOST_PP_TUPLE_ELEM(5,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_HAS_STOPPED(state) BOOST_PP_TUPLE_ELEM(6,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_OUTPUT_STOP(output) BOOST_PP_TUPLE_ELEM(0,output)
#define CXXD_DETAIL_TABLE_READ_ROWS_OUTPUT_DATA(output) BOOST_PP_TUPLE_ELEM(1,output)

#define CXXD_DETAIL_TABLE_READ_ROWS_CURRENT(state) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state), \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_TABLE(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_PRED(d,state) \
    BOOST_PP_BITAND \
        ( \
        BOOST_PP_COMPL(CXXD_DETAIL_TABLE_READ_ROWS_STATE_HAS_STOPPED(state)), \
        BOOST_PP_NOT_EQUAL \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state), \
            CXXD_DETAIL_TABLE_READ_ROWS_STATE_SIZE(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP(d,state) \
    CXXD_DETAIL_TABLE_READ_ROWS_OP_UI \
        ( \
        d, \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO \
            ( \
            d, \
            state, \
            CXXD_DETAIL_TABLE_READ_ROWS_STATE_MACRO(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO(d,state,macro) \
    CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT \
        ( \
        d, \
        state, \
        macro(d,CXXD_DETAIL_TABLE_READ_ROWS_CURRENT(state),CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA(state)) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT(d,state,output) \
    BOOST_PP_IIF \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_ALLOW_STOP(state), \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT_CR, \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT_REP \
        ) \
    (d,state,output) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT_CR(d,state,output) \
    BOOST_PP_IIF \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_OUTPUT_STOP(output), \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_DO_STOP, \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_DO_GO \
        ) \
    (d,state,output) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_DO_STOP(d,state,output) \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_DO_GO(d,state,output), \
        6, \
        1 \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_DO_GO(d,state,output) \
    CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT_REP \
        ( \
        d, \
        state, \
        CXXD_DETAIL_TABLE_READ_ROWS_OUTPUT_DATA(output) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_MACRO_OUTPUT_REP(d,state,output) \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        state, \
        4, \
        output \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_OP_UI(d,state) \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        state, \
        1, \
        BOOST_PP_INC(CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state)) \
        ) \
/**/

#endif // !defined(CXXD_DETAIL_TABLE_READ_ROWS_HPP)
