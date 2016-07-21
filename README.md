# Cxx_dual library

The Cxx dual library, or CXXD for short, is a C++ macro header-only library which chooses between using a Boost library or its C++ standard equivalent library for a number of different C++ implementations, while using the same code to program either choice. An 'implementation' is a Boost library which has a C++ standard library equivalent whose public interfaces are nearly the same in both cases. An 'implementation' is called a 'dual library' in this documentation, or 'CXXD-mod' for short.

The library does this by defining object-like macros for including the appropriate header file(s) and namespace for using either the Boost library version or the C++ standard library version of a particular dual library. Alternatively, for those who prefer not to use macros, the library provides an implementation header file for including the appropriate header file(s) and for setting a namespace alias for using either the Boost library version or the C++ standard library version of a particular dual library. CXXD currently supports twenty eight different dual libraries, where the Boost version and the C++ standard version is nearly interchangeable. CXXD also provides a macro-based solution for distinguishing between the Boost version and the C++ standard version of a dual library so that specific code for a particular dual library choice may be written in those cases where the public interfaces diverge.

## Who the library is for

The CXXD library is for:

* Programmers writing code not using C++11 on up syntax who still want to target some C++11 on up libraries if the code is compiled in C++11 on up mode.
* Programmers writing code using C++11 on up syntax who still want the option of targeting some Boost libraries if the equivalent C++11 library does not exist for a given implementation.

## Boost

The CXXD library is **not** a Boost library.

The library does depend on the Boost.Config, Boost.VMD, and Boost.Preprocessor libraries. In tests the library depends on Boost libraries supported by implementations as well as the Boost lightweight_test implementation.

## Setup

Clone the repository beneath a Boost implementation's 'libs' directory as 'cxx_dual'. Run `b2 headers` from the top-level Boost directory.

## Documentation

The URL http://eldiener.github.io/cxx_dual gives the online documentation. The PDF documentation is in the top-level directory as cxx_dual.pdf. You can generate local documentation, if you have the right tools installed to do so, by running `b2` in the doc sub-directory.

## Tests

The tests can be run by executing `b2` in the test subdirectory. To test the CXXD mods you can execute `b2 mods`.

## Feedback

Feedback as comments, suggestions, or bug reports is welcome in the Boost Library Incubator at http://blincubator.com, on the Boost developer mailing list, or as Github issues.
