//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_TYPE_INDEX_HPP)
#define CXXD_IMPL_TYPE_INDEX_HPP

#if !defined(CXXD_HAS_STD_TYPE_INDEX)
#include <boost/cxx_dual/type_index.hpp>
#endif

#if CXXD_HAS_STD_TYPE_INDEX

#define CXXD_TYPE_INDEX_NS std
#include <typeindex>
namespace cxxd_type_index_ns = std ;

#else

#define CXXD_TYPE_INDEX_NS boost::typeindex
#include <boost/type_index.hpp>
namespace cxxd_type_index_ns = boost::typeindex ;

#endif

#endif // !defined(CXXD_IMPL_TYPE_INDEX_HPP)
