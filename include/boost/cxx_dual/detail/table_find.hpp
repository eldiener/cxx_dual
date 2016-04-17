//  (C) Copyright Edward Diener 2016 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TABLE_FIND_HPP)
#define CXXD_DETAIL_TABLE_FIND_HPP

#include <boost/vmd/empty.hpp>

#if BOOST_VMD_MSVC
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#endif

#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>

#include <boost/vmd/equal.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/is_number.hpp>
#include <boost/vmd/is_tuple.hpp>

#include <boost/cxx_dual/detail/table_read_rows.hpp>

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
    CXXD_DETAIL_TABLE_FIND_STATE_RETURN_VALUE \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS(table,(findex,value,rindex,),CXXD_DETAIL_TABLE_FIND_PARAMS_RRMAC,1) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_PARAMS_RRMAC(d,row,state) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_EQUAL_D \
                ( \
                d, \
                CXXD_DETAIL_TABLE_FIND_STATE_VALUE(state), \
                CXXD_DETAIL_TABLE_FIND_STATE_ROW_FIND_VALUE(row,state) \
                ), \
            CXXD_DETAIL_TABLE_FIND_PARAMS_RRMAC_FOUND, \
            BOOST_VMD_IDENTITY((0,state)) \
            ) \
        (d,row,state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_PARAMS_RRMAC_FOUND(d,row,state) \
    ( \
    1, \
    BOOST_PP_TUPLE_REPLACE_D \
        ( \
        d, \
        state, \
        3, \
        CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE(row,state) \
        ) \
    ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_FIND_INDEX(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_VALUE(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_RETURN_INDEX(state) BOOST_PP_TUPLE_ELEM(2,state)
#define CXXD_DETAIL_TABLE_FIND_STATE_RETURN_VALUE(state) BOOST_PP_TUPLE_ELEM(3,state)

#define CXXD_DETAIL_TABLE_FIND_STATE_ROW_FIND_VALUE(row,state) \
    BOOST_PP_TUPLE_ELEM(CXXD_DETAIL_TABLE_FIND_STATE_FIND_INDEX(state),row) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE(row,state) \
    CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE_RI \
        ( \
        row, \
        state, \
        CXXD_DETAIL_TABLE_FIND_STATE_RETURN_INDEX(state) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE_RI(row,state,ri) \
    BOOST_VMD_IDENTITY_RESULT \
        ( \
        BOOST_PP_IIF \
            ( \
            BOOST_VMD_IS_EMPTY(ri), \
            BOOST_VMD_IDENTITY(row), \
            CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE_FIELD \
            ) \
        (row,state,ri) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_FIND_STATE_ROW_RETURN_VALUE_FIELD(row,state,ri) \
    BOOST_PP_TUPLE_ELEM(ri,row) \
/**/

#endif // !defined(CXXD_DETAIL_TABLE_FIND_HPP)
