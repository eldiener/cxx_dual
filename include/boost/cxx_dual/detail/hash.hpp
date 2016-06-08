//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_DETAIL_HASH_HPP)
#define CXXD_DETAIL_HASH_HPP

#if CXXD_HAS_STD_HASH

#define CXXD_HASH_NS std
#include <functional>
namespace cxxd_hash_ns = std ;

#else

#define CXXD_HASH_NS boost
#include <boost/functional/hash.hpp>
namespace cxxd_hash_ns = boost ;

#endif

#endif // !defined(CXXD_DETAIL_HASH_HPP)
