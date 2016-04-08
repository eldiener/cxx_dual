//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TABLE_READ_ROWS_HPP)
#define CXXD_DETAIL_TABLE_READ_ROWS_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>

/*

    Reads each row in a table.
    
    A table is a tuple whose elements are tuples of the same tuple size.
    Therefore the table's rows are the individual tuples.
    
    table = the table to read.
    data = initial data when reading.
    macro = macro to be called when reading each row.
            the macro is of the form:
        
            macro(d,row,data)
            
            where d    = the BOOST_PP_WHILE iteration
                  row  = the rwo of the table
                  data = transformed data
                  
            the macro returns the new data
            
    The entire macro returns the final data.
            
*/

#define CXXD_DETAIL_TABLE_READ_ROWS(table,data,macro) \
    CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA \
        ( \
        BOOST_PP_WHILE \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS_PRED, \
            CXXD_DETAIL_TABLE_READ_ROWS_OP, \
            (table,0,BOOST_PP_TUPLE_SIZE(table),macro,data) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_D(d,table,data,macro) \
    CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA \
        ( \
        BOOST_PP_WHILE_ ## d \
            ( \
            CXXD_DETAIL_TABLE_READ_ROWS_PRED, \
            CXXD_DETAIL_TABLE_READ_ROWS_OP, \
            (table,0,BOOST_PP_TUPLE_SIZE(table),macro,data) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_TABLE(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_SIZE(state) BOOST_PP_TUPLE_ELEM(2,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_MACRO(state) BOOST_PP_TUPLE_ELEM(3,state)
#define CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA(state) BOOST_PP_TUPLE_ELEM(4,state)

#define CXXD_DETAIL_TABLE_READ_ROWS_CURRENT(state) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state), \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_TABLE(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_PRED(d,state) \
    BOOST_PP_NOT_EQUAL \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_INDEX(state), \
        CXXD_DETAIL_TABLE_READ_ROWS_STATE_SIZE(state) \
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
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        state, \
        4, \
        macro(d,CXXD_DETAIL_TABLE_READ_ROWS_CURRENT(state),CXXD_DETAIL_TABLE_READ_ROWS_STATE_DATA(state)) \
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
