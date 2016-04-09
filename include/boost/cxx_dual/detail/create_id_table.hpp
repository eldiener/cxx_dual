//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
#define CXXD_DETAIL_CREATE_ID_TABLE_HPP

#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
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

#endif // !defined(CXXD_DETAIL_CREATE_ID_TABLE_HPP)
