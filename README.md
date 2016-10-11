# Cxx_dual library

The Cxx Dual library, or CXXD for short, is a C++ macro header-only library which chooses between using a Boost library or its C++ standard equivalent library for a number of different C++ implementations, while allowing the end-user to use the same code to program either choice. An implementation is a Boost library which has a C++ standard library equivalent whose public interfaces are nearly the same in both cases. An 'implementation' is called a 'mod' for short and each of the possible Boost or C++ standard implementations for that mod are called a 'dual library'.

The Cxx Dual library does this by automatically choosing either the Boost library or the C++ standard library for a particular mod, including the correct header file(s) needed for the dual library chosen, and creating a namespace alias for the namespace of the dual library chosen. CXXD also provides a macro-based solution for distinguishing between the Boost version and the C++ standard version of a dual library so that specific code for a particular dual library choice may be written in those cases where the public interfaces diverge.

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

The tests can be run by executing `b2` in the test subdirectory. To test the CXXD mods you can execute `b2 mods` .

## Feedback

Feedback as comments, suggestions, or bug reports is welcome in the Boost Library Incubator at http://blincubator.com, on the Boost developer mailing list, or as Github issues.
