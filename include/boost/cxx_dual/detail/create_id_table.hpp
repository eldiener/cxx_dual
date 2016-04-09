//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
#define CXXD_DETAIL_CREATE_ID_TABLE_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/is_number.hpp>
#include <boost/vmd/tuple/push_back.hpp>
#include <boost/cxx_dual/detail/mod_table.hpp>

/*

    Expands to a table of all included CXXD-mods
    
    The table consists of: 
        CXXD mod id
        0 or 1, for Boost implementation or C++ standard implementation respectively

*/

#define CXXD_DETAIL_CREATE_ID_TABLE() \
    CXXD_DETAIL_CREATE_ID_TABLE_RESULT \
        ( \
        BOOST_PP_WHILE \
            ( \
            CXXD_DETAIL_CREATE_ID_TABLE_PRED, \
            CXXD_DETAIL_CREATE_ID_TABLE_OP, \
                ( \
                CXXD_DETAIL_MOD_TABLE, \
                0, \
                BOOST_PP_TUPLE_SIZE(CXXD_DETAIL_MOD_TABLE), \
                ) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_MODS(state) BOOST_PP_TUPLE_ELEM(0,state)
#define CXXD_DETAIL_CREATE_ID_TABLE_INDEX(state) BOOST_PP_TUPLE_ELEM(1,state)
#define CXXD_DETAIL_CREATE_ID_TABLE_SIZE(state) BOOST_PP_TUPLE_ELEM(2,state)
#define CXXD_DETAIL_CREATE_ID_TABLE_RESULT(state) BOOST_PP_TUPLE_ELEM(3,state)

#define CXXD_DETAIL_CREATE_ID_TABLE_CURRENT_ID(state) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        0, \
        BOOST_PP_TUPLE_ELEM \
            ( \
            CXXD_DETAIL_CREATE_ID_TABLE_INDEX(state), \
            CXXD_DETAIL_CREATE_ID_TABLE_MODS(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_CURRENT_CHECK(state) \
    BOOST_PP_TUPLE_ELEM \
        ( \
        1, \
        BOOST_PP_TUPLE_ELEM \
            ( \
            CXXD_DETAIL_CREATE_ID_TABLE_INDEX(state), \
            CXXD_DETAIL_CREATE_ID_TABLE_MODS(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_PRED(d,state) \
    BOOST_PP_NOT_EQUAL \
        ( \
        CXXD_DETAIL_CREATE_ID_TABLE_INDEX(state), \
        CXXD_DETAIL_CREATE_ID_TABLE_SIZE(state) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_OP_RES(state) \
    BOOST_VMD_TUPLE_PUSH_BACK \
        ( \
        CXXD_DETAIL_CREATE_ID_TABLE_RESULT(state), \
            ( \
            CXXD_DETAIL_CREATE_ID_TABLE_CURRENT_ID(state), \
            CXXD_DETAIL_CREATE_ID_TABLE_CURRENT_CHECK(state) \
            ) \
        ) \
/**/

#define CXXD_DETAIL_CREATE_ID_TABLE_OP(d,state) \
    ( \
    CXXD_DETAIL_CREATE_ID_TABLE_MODS(state), \
    BOOST_PP_INC(CXXD_DETAIL_CREATE_ID_TABLE_INDEX(state)), \
    CXXD_DETAIL_CREATE_ID_TABLE_SIZE(state), \
    BOOST_PP_IIF \
        ( \
        BOOST_VMD_IS_NUMBER(CXXD_DETAIL_CREATE_ID_TABLE_CURRENT_CHECK(state)), \
        CXXD_DETAIL_CREATE_ID_TABLE_OP_RES, \
        CXXD_DETAIL_CREATE_ID_TABLE_RESULT \
        ) \
    (state) \
    ) \
/**/

#endif // !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
