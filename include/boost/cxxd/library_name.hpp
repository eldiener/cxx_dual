//  (C) Copyright Edward Diener 2015-2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_LIBRARY_NAME_HPP)
#define CXXD_LIBRARY_NAME_HPP

#include <boost/preprocessor/config/config.hpp>

/** @file library_name.hpp

    Contains CXXD_LIBRARY_NAME macro.
*/

/** @def CXXD_LIBRARY_NAME(...)
    @brief Automatically names a non-header only library.
    
    The function-like macro expands to the name of a non-header only library.
    It is useful for non-header only libraries in which different library
    variants are generated depending on the dual library choices for 
    the CXXD-mods being used in the built portion of the library. The macro
    by default will expand to a unique library name depending on the dual
    library choices. The macro works based on the CXXD-mods included before
    the macro is invoked.
    
    The required first variadic parameter is the base library name.
    The generated library name will be the base library name and
    possibly other mnemonics appended to it. The base library name
    should be the library name as it would be called if no CXXD-mods
    were being used in the built portion of the library.
    
    Each optional variadic parameter is a Boost PP tuple with one to three
    elements. The Boost PP tuple designates:
    
    - The name of a CXXD-mod. The CXXD-mod name is 'CXXD_' followed by the name of a CXXD-mod in uppercase.
      The CXXD-mod names are specified in a separate list below.
    - A mnemonic to be appended to the base library name if the CXXD-mod is using its C++ standard implementation.
    - A mnemonic to be appended to the base library name if the CXXD-mod is using its Boost implementation.
    
    The first tuple element is required.
    The second tuple element may be empty or left out.
    The third tuple element may be empty or left out.
    
    A tuple element that is left out is considered 'empty'.
    An empty element is valid and means that nothing will
    be appended to the base name if the case is met.
    
    When a tuple is specified it is important that the mnemonic to be appended
    be different whether the CXXD-mod is using its C++ standard implementation
    or its Boost implementation, else there is no guarantee that a unique library
    name will be generated depending on the CXXD-mods being included.
    However lack of a difference in the mnemonics, if it occurs, is not flagged 
    as an error in the processing of the macro.
    
    If an optional parameter for a particular CXXD-mod which is included is not specified,
    a default value is appended as a mnemonic for the particular CXXD-mod if the CXXD-mod
    is using its C++ standard implementation. Otherwise if the CXXD-mod is using its Boost
    C++ standard implementation no value is appended by default.
    
    The CXXD-mod names and their default values for the C++ standard implementation are:
    
    - CXXD_ARRAY,_ar
    - CXXD_ATOMIC,_at
    - CXXD_BIND,_bd
    - CXXD_CHRONO,_ch
    - CXXD_CONDITION_VARIABLE,_cv
    - CXXD_FUNCTION,_fn
    - CXXD_HASH,_ha
    - CXXD_MEM_FN,_mf
    - CXXD_MUTEX,_mx
    - CXXD_RANDOM,_rd
    - CXXD_RATIO,_ra
    - CXXD_REF,_rf
    - CXXD_REGEX,_rx
    - CXXD_SHARED_MUTEX,_sm
    - CXXD_SHARED_PTR,_sp
    - CXXD_SYSTEM,_sy
    - CXXD_THREAD,_th
    - CXXD_TUPLE,_tu
    - CXXD_TYPE_INDEX,_ti
    - CXXD_TYPE_TRAITS,_tt
    - CXXD_UNORDERED_MAP,_um
    - CXXD_UNORDERED_MULTIMAP,_up
    - CXXD_UNORDERED_MULTISET,_ut
    - CXXD_UNORDERED_SET,_us
    - CXXD_MODS_ALL,_std
    
    The CXXD_MODS_ALL name refers to what happens if all the included CXXD-mods
    use either the C++ standard implementation or the Boost implementation.
    In this case, instead of each individual CXXD-mod having its mnemonic
    appended to the base name, a single mnemonic is appended to the base name.
    In the default case for CXXD_MODS_ALL the mnemonic '_std' is appended to
    the base name if all the included CXXD-mods use the C++ standard implementation
    and nothing is appended to the base name if all the included CXXD-mods use the
    Boost implementation.
    
    The use of the optional parameters is the way to override the default
    processing for any particular CXXD-mod.
    
*/

#if BOOST_PP_VARIADICS

#define CXXD_LIBRARY_NAME(...)

#endif

#endif // !defined(CXXD_LIBRARY_NAME_HPP)
