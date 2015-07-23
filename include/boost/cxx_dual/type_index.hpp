//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_TYPE_INDEX_HPP)
#define CXXD_TYPE_INDEX_HPP

#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_TYPEINDEX) || defined(CXXD_TYPE_INDEX_USE_BOOST) || defined(CXXD_USE_BOOST)
#if defined(CXXD_TYPE_INDEX_USE_STD) || defined(CXXD_USE_STD)
#if defined(BOOST_NO_CXX11_HDR_TYPEINDEX)
#error CXXD: C++ standard type index is not available
#else
#error CXXD: Using C++ standard and using Boost are both defined for type index
#endif
#endif
#define CXXD_HAS_STD_TYPE_INDEX 0
#define CXXD_TYPE_INDEX_NS boost::typeindex
#define CXXD_TYPE_INDEX_HEADER <boost/type_index.hpp>
#else
#define CXXD_HAS_STD_TYPE_INDEX 1
#define CXXD_TYPE_INDEX_NS std
#define CXXD_TYPE_INDEX_HEADER <typeindex>
#endif

#endif // !defined(CXXD_TYPE_INDEX_HPP)
