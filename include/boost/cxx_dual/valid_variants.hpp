//  (C) Copyright Edward Diener 2016.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CXXD_VALID_VARIANTS_HPP)
#define CXXD_VALID_VARIANTS_HPP

/** @file valid_variants.hpp

    Contains CXXD_VALID_VARIANTS macro.
*/

/** @def CXXD_VALID_VARIANTS(...)
    @brief Tests for valid dual library variants.
    
    The function-like macro tests for valid dual library variants.
    A variant consists of a series of CXXD-mod choices encoded as
    a variadic parameter. A CXXD-mod choice refers to whether the
    CXXD-mod chooses the C++ standard implementation or the Boost implementation.
    
    If the CXXD-mod choices based on the CXXD-mod headers being included 
    before the macro is invoked match any one of the variants, the macro expands to 1, 
    otherwise the macro expands to 0.
    
    The macro provides a single invocation where the creator of a library
    or executable can test whether or not combinations of CXXD-mod choices
    match what the programmer wants to allow. In cases of header-only libraries or
    executables it should never be necessary to limit the combinations in any way,
    but in the case of a non-header only library the library implementor may well
    want to limit the acceptable combinations because supporting all possible
    variants, each with their own name and need to be built, might well prove onerous.
    
    A variant is encoded by a series, known as a VMD sequence, of two-element Boost PP tuples.
    The first element is a particular CXXD-mod identifier, given in a following list, and the second
    element is 1 if the desired choice is the C++ standard implementation of that CXXD-mod or 0
    if the desired choice is the Boost implementation of that CXXD-mod.
    
    The VMD sequence of each choice makes up a combination of dual library choices
    which denote a valid variant which the macro invoker says that his library will allow.
    
    The list of CXXD-mod identifiers and their CXXD-mod is:
    
    - CXXD_ARRAY,array
    - CXXD_ATOMIC,atomic
    - CXXD_BIND,bind
    - CXXD_CHRONO,chrono
    - CXXD_CONDITION_VARIABLE,condition_variable
    - CXXD_FUNCTION,function
    - CXXD_HASH,hash
    - CXXD_MEM_FN,mem_fn
    - CXXD_MUTEX,mutex
    - CXXD_RANDOM,random
    - CXXD_RATIO,ratio
    - CXXD_REF,ref
    - CXXD_REGEX,regex
    - CXXD_SHARED_MUTEX,shared_mutex
    - CXXD_SHARED_PTR,shared_ptr
    - CXXD_SYSTEM,system
    - CXXD_THREAD,thread
    - CXXD_TUPLE,tuple
    - CXXD_TYPE_INDEX,type_index
    - CXXD_TYPE_TRAITS,type_traits
    - CXXD_UNORDERED_MAP,unordered_map
    - CXXD_UNORDERED_MULTIMAP,unordered_multimap
    - CXXD_UNORDERED_MULTISET,unordered_multiset
    - CXXD_UNORDERED_SET,unorderd_set
    - CXXD_MODS_ALL,all mods
    
    As can be seen each CXXD-mod identifier is 'CXXD_' followed
    by the uppercase name of the CXXD-mod.
    
    The CXXD_MODS_ALL identifier refers to all of the include CXXD-mod headers
    choosing either the C++ standard implementation or the Boost implementation.
    Therefore if this identifier is used its Boost PP tuple should be the only
    one in the VMD sequence for that variant.
    
    The macro invoker must pass at least one variant as a variadic parameter
    otherwise there is not point in using this macro, but may specify any number of 
    further variants as variadic parameters.
    
    A protoypical variant will look like:
    
        (CXXD_XXX,1 or 0)(CXXD_YYY,1 or 0)(CXXD_ZZZ,1 or 0)...
        
    where CCXD_XXX, CXXD_YYY, and CXXD_ZZZ are one of the CXXD-mod
    identifiers listed above and the '1 or 0' denotes either the 
    C++ standard implementation or Boost implementation as a choice
    for that CXXD-mod. There can be one or more Boost PP tuples
    in the VMD sequence which denote the variant. A variant is an 'AND'
    proposition where each Boost PP tuple in the VMD sequence must be
    true for the variant to match. Each variant as a variadic parameter
    is an 'OR' proposition where any variant must match for the macro to
    return 1. Otherwise the macro returns 0 if none of the variants match.
    
*/

#include <boost/preprocessor/config/config.hpp>

#if BOOST_PP_VARIADICS

#include <boost/cxx_dual/detail/valid_variants.hpp>

#define CXXD_VALID_VARIANTS(...) CXXD_DETAIL_VALID_VARIANTS(__VA_ARGS__)

#endif

#endif // !defined(CXXD_VALID_VARIANTS_HPP)
