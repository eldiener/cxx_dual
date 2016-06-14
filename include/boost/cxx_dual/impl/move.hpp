//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_HAS_STD_MOVE)
#include <boost/cxx_dual/move.hpp>
#endif

#if CXXD_HAS_STD_MOVE

#define CXXD_MOVE_NS std
#include <utility>
namespace cxxd_move_ns = std ;

#else

#define CXXD_MOVE_NS boost
#include <boost/move/move.hpp>
namespace cxxd_move_ns = boost ;

#endif
