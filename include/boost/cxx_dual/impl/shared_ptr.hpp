//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_IMPL_SHARED_PTR_HPP)
#define CXXD_IMPL_SHARED_PTR_HPP

#if !defined(CXXD_HAS_STD_SHARED_PTR)
#include <boost/cxx_dual/shared_ptr.hpp>
#endif

#include CXXD_SHARED_PTR_HEADER
#if !defined(CXXD_IMPL_SHARED_PTR_ONLY_HPP)
namespace cxxd_shared_ptr_ns = CXXD_SHARED_PTR_NS ;
#endif

#endif // !defined(CXXD_IMPL_SHARED_PTR_HPP)
