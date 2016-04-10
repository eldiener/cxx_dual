//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TABLE_FIND_HPP)
#define CXXD_DETAIL_TABLE_FIND_HPP

#include <boost/vmd/is_empty.hpp>

#if BOOST_VMD_MSVC
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#endif

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/expr_iif.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/repetition/for.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/equal.hpp>
#include <boost/vmd/is_number.hpp>
#include <boost/vmd/is_tuple.hpp>

/*

    Finds a specific value in a table.
    
    A table is a tuple whose elements are tuples of the same tuple size.
    Therefore the table's rows are the individual tuples and the
    table's columns are the elements of each tuple. All rows and column
    numbers ar numbers starting with 0.
    
    The macro looks for a specific value in a row of the table at a particular column in a row.
    When it finds the value it returns the value at another designated column of that row
    or it returns the entire row as a tuple. The two columns may be the same. The value
    for which it looks must be a valid Boost VMD data type. If it does not find the value
    it returns emptiness.
    
    table = the table in which to find the value.
    findex = the column where the value must be.
    ... = one or two variadic parameters.
        The first required variadic parameter is the value for which to look
        The second optional variadic parameter is the column whose value is returned.
            If the column is not specified or is empty, the entire row as a tuple is returned.
    
*/

#define CXXD_DETAIL_TABLE_FIND(table,findex,...) \
    CXXD_DETAIL_TABLE_FIND_OVR(table,findex,__VA_ARGS__) \
/**/

#if BOOST_VMD_MSVC

#define CXXD_DETAIL_TABLE_FIND_OVR(table,findex,...) \
    BOOST_PP_CAT(BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_FIND_OV,__VA_ARGS__)(table,findex,__VA_ARGS__),BOOST_PP_EMPTY()) \
/**/

#else

#define CXXD_DETAIL_TABLE_FIND_OVR(table,findex,...) \
    BOOST_PP_OVERLOAD(CXXD_DETAIL_TABLE_FIND_OV,__VA_ARGS__)(table,findex,__VA_ARGS__) \
/**/

#endif

#define CXXD_DETAIL_TABLE_FIND_OV1(table,findex,value) \
    CXXD_DETAIL_TABLE_FIND_PARAMS(table,findex,value,) \
/**/

#define CXXD_DETAIL_TABLE_FIND_OV2(table,findex,value,rindex) \
    CXXD_DETAIL_TABLE_FIND_PARAMS(table,findex,value,rindex) \
/**/

#define CXXD_DETAIL_TABLE_FIND_PARAMS(table,findex,value,rindex) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_BITAND \
            ( \
            BOOST_VMD_IS_TUPLE(table), \
            BOOST_PP_BITAND \
                ( \
                BOOST_VMD_IS_NUMBER(findex), \
                BOOST_PP_BITOR \
                    ( \
                    BOOST_VMD_IS_EMPTY(rindex), \
                    BOOST_VMD_IS_NUMBER(rindex) \
                    ) \
                ) \
            ), \
        CXXD_DETAIL_TABLE_FIND_PARAMS_GO, \
        BOOST_VMD_EMPTY \
        ) \
    (table,findex,value,rindex) \
/**/

#define CXXD_DETAIL_TABLE_FIND_PARAMS_GO(table,findex,value,rindex) \
    BOOST_PP_FOR \
        ( \
        (value,0,BOOST_PP_TUPLE_SIZE(table),table,findex,rindex), \
        CXXD_DETAIL_TABLE_FIND_PRED, \
        CXXD_DETAIL_TABLE_FIND_OP, \
        CXXD_DETAIL_TABLE_FIND_MACRO \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_VALUE(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_TABLE_INDEX(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_SIZE(state) BOOST_PP_TUPLE_ELEM(2,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_TABLE(state) BOOST_PP_TUPLE_ELEM(3,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_FIND_INDEX(state) BOOST_PP_TUPLE_ELEM(4,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_RETURN_INDEX(state) BOOST_PP_TUPLE_ELEM(5,state)

#define CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_VALUE(state) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        CXXD_DETAIL_TABLE_FIND_STATE_FIND_INDEX(state), \
        BOOST_PP_TUPLE_ELEM \
            ( \
            CXXD_DETAIL_TABLE_FIND_STATE_TABLE_INDEX(state), \
            CXXD_DETAIL_TABLE_FIND_STATE_TABLE(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW_EMPTY(row,ri) row

#define CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW_FULL(row,ri) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        ri, \
        row \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW(row,ri) \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_EMPTY(ri), \
        CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW_EMPTY, \
        CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW_FULL \
        ) \
    (row,ri) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE(state) \
    CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE_ROW \
        ( \
        BOOST_PP_TUPLE_ELEM \
            ( \
            CXXD_DETAIL_TABLE_FIND_STATE_TABLE_INDEX(state), \
            CXXD_DETAIL_TABLE_FIND_STATE_TABLE(state) \
            ), \
        CXXD_DETAIL_TABLE_FIND_STATE_RETURN_INDEX(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_INCREMENT(state) \
    BOOST_PP_INC(CXXD_DETAIL_TABLE_FIND_STATE_TABLE_INDEX(state)) \
/**/

#define CXXD_DETAIL_TABLE_FIND_VALUE_MATCH(state) \
    BOOST_VMD_EQUAL \
        ( \
        CXXD_DETAIL_TABLE_FIND_STATE_VALUE(state), \
        CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_VALUE(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_PRED(r,state) \
    BOOST_PP_NOT_EQUAL \
        ( \
        CXXD_DETAIL_TABLE_FIND_STATE_TABLE_INDEX(state), \
        CXXD_DETAIL_TABLE_FIND_STATE_SIZE(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_OP(r,state) \
    BOOST_PP_TUPLE_REPLACE \
        ( \
        state, \
        1, \
        BOOST_PP_IIF \
            ( \
            CXXD_DETAIL_TABLE_FIND_VALUE_MATCH(state), \
            CXXD_DETAIL_TABLE_FIND_STATE_SIZE, \
            CXXD_DETAIL_TABLE_FIND_INCREMENT \
            ) \
        (state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_MACRO(r,state) \
    BOOST_PP_EXPR_IIF \
        ( \
        CXXD_DETAIL_TABLE_FIND_VALUE_MATCH(state), \
        CXXD_DETAIL_TABLE_FIND_STATE_CURRENT_RETURN_VALUE(state) \
        ) \
/**/

#endif // !defined(CXXD_DETAIL_TABLE_FIND_HPP)
