//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXX_MODS_IMPL_HPP)
#define CXX_MODS_IMPL_HPP

/** @file cxx_mods.hpp
    @brief Includes all dual libraries implementations in a single header.
    
    Header file to include all the dual libraries implementations with a single include.
*/

/** @def CXXD_USE_BOOST
    @brief Override macro for any Boost implementation.
    
    The object-like macro, when defined to nothing prior to including any CXXD-mod header file, 
    forces the dual library choice of the Boost implementation for that CXXD-mod.
*/

/** @def CXXD_USE_STD
    @brief Override macro for any C++ standard implementation.
    
    The object-like macro, when defined to nothing prior to including any CXXD-mod header file,
    forces the dual library choice of the C++ standard implementation for that CXXD-mod. If the
    C++ standard implementation for that CXXD-mod is not available a preprocessor error is generated.
*/

/** @def CXXD_NO_CONFIG
    @brief Macro which allows an override for the C++ standard implementation of a CXXD-mod to be successful even when it is unavailable.
    
    The object-like macro, when defined to nothing prior to including any CXXD-mod header file,
    allows the dual choice of the C++ standard implementation through a macro override to be successful
    even when the C++ standard implementation for that CXXD-mod is unavailable. CXXD determines
    availability of the C++ standard implementation of a particular CXXD-mod through settings in
    Boost.Config. When an override macro is used to force the dual library choice of the C++ standard
    implementation for a particular CXXD-mod, and CXXD determines through Boost.Config that the
    C++ standard implementation is not available, a preprocessing error normally occurs. Using
    this macro tells CXXD ro set the dual library choice to the C++ standard implementation
    without producing a preprocessor error.
*/

#include <boost/cxx_dual/impl/array.hpp>
#include <boost/cxx_dual/impl/atomic.hpp>
#include <boost/cxx_dual/impl/bind.hpp>
#include <boost/cxx_dual/impl/chrono.hpp>
#include <boost/cxx_dual/impl/condition_variable.hpp>
#include <boost/cxx_dual/impl/enable_shared_from_this.hpp>
#include <boost/cxx_dual/impl/function.hpp>
#include <boost/cxx_dual/impl/hash.hpp>
#include <boost/cxx_dual/impl/make_shared.hpp>
#include <boost/cxx_dual/impl/mem_fn.hpp>
#include <boost/cxx_dual/impl/move.hpp>
#include <boost/cxx_dual/impl/mutex.hpp>
#include <boost/cxx_dual/impl/random.hpp>
#include <boost/cxx_dual/impl/ratio.hpp>
#include <boost/cxx_dual/impl/ref.hpp>
#include <boost/cxx_dual/impl/regex.hpp>
#include <boost/cxx_dual/impl/shared_mutex.hpp>
#include <boost/cxx_dual/impl/shared_ptr.hpp>
#include <boost/cxx_dual/impl/system_error.hpp>
#include <boost/cxx_dual/impl/thread.hpp>
#include <boost/cxx_dual/impl/tuple.hpp>
#include <boost/cxx_dual/impl/type_index.hpp>
#include <boost/cxx_dual/impl/type_traits.hpp>
#include <boost/cxx_dual/impl/unordered_map.hpp>
#include <boost/cxx_dual/impl/unordered_multimap.hpp>
#include <boost/cxx_dual/impl/unordered_multiset.hpp>
#include <boost/cxx_dual/impl/unordered_set.hpp>
#include <boost/cxx_dual/impl/weak_ptr.hpp>

/*

  CXXD_DOXYGEN is only defined when building the docs for doxygen
  so that doxygen will document macros which are not defined
  in the library.
  
  It should never be defined by an end-user of CXXD.

*/

#if defined(CXXD_DOXYGEN)
    #define CXXD_NO_CONFIG
    #define CXXD_USE_STD
    #define CXXD_USE_BOOST
#endif // defined(CXXD_DOXYGEN)

#endif // !defined(CXX_MODS_IMPL_HPP)
