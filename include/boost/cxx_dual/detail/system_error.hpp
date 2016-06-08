//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_SYSTEM_ERROR_HPP)
#define CXXD_DETAIL_SYSTEM_ERROR_HPP

#if CXXD_HAS_STD_SYSTEM_ERROR

#define CXXD_SYSTEM_ERROR_NS std
#include <system_error>
namespace cxxd_system_error_ns = std ;

#else

#define CXXD_SYSTEM_ERROR_NS boost::system
#include <boost/system/system_error.hpp>
namespace cxxd_system_error_ns = boost::system ;

#endif

#endif // !defined(CXXD_DETAIL_SYSTEM_ERROR_HPP)
