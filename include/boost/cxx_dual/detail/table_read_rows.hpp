//  (C) Copyright Edward Diener 2016. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_TABLE_READ_ROWS_HPP)
#define CXXD_DETAIL_TABLE_READ_ROWS_HPP

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/detail/auto_rec.hpp>
#include <boost/preprocessor/punctuation/is_begin_parens.hpp>
#include <boost/cxx_dual/detail/table_read_rows_1.hpp>
#include <boost/cxx_dual/detail/table_read_rows_2.hpp>
#include <boost/cxx_dual/detail/table_read_rows_3.hpp>
#include <boost/cxx_dual/detail/table_read_rows_4.hpp>

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
                       tuple element is 0 ( stop reading ) or 1 ( continue reading ),
                       and the second tuple element is the new data.
                       
           The second optional variadic parameter is:
               
               0 = read all rows, the default
               1 = may stop before reading all rows
            
    The entire macro returns the final data.
            
*/

#define CXXD_DETAIL_TABLE_READ_ROWS \
    BOOST_PP_CAT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_, \
        BOOST_PP_AUTO_REC(CXXD_DETAIL_TABLE_READ_ROWS_AR_CHECK, 4) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_D \
    BOOST_PP_CAT \
        ( \
        CXXD_DETAIL_TABLE_READ_ROWS_D_, \
        BOOST_PP_AUTO_REC(CXXD_DETAIL_TABLE_READ_ROWS_AR_CHECK, 4) \
        ) \
/**/

#define CXXD_DETAIL_TABLE_READ_ROWS_AR_CHECK(n) \
    BOOST_PP_BITAND \
        ( \
        BOOST_PP_IS_BEGIN_PARENS(CXXD_DETAIL_TABLE_READ_ROWS_ ## n(,,)()), \
        BOOST_PP_IS_BEGIN_PARENS(CXXD_DETAIL_TABLE_READ_ROWS_D_ ## n(1,,,)()) \
        ) \
/**/

#endif // !defined(CXXD_DETAIL_TABLE_READ_ROWS_HPP)
