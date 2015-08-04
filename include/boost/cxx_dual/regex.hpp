//  (C) Copyright Edward Diener 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Multiple inclusion must be allowed */

#if !defined(CXXD_REGEX_ERROR)
	#if defined(CXXD_HAS_STD_REGEX)
		#if CXXD_HAS_STD_REGEX && (defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST))
			#define CXXD_REGEX_ERROR
			#error CXXD: Previous use of C++ standard regex erroneously overridden
		#elif !CXXD_HAS_STD_REGEX && (defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD))
			#define CXXD_REGEX_ERROR
			#error CXXD: Previous use of Boost regex erroneously overridden
		#endif
	#elif (defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST)) && (defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD))
		#define CXXD_REGEX_ERROR
		#error CXXD: Using C++ standard and using Boost are both defined for regex
	#else
		#include <boost/config.hpp>
		#if defined(BOOST_NO_CXX11_HDR_REGEX) || defined(CXXD_REGEX_USE_BOOST) || defined(CXXD_USE_BOOST)
			#if defined(CXXD_REGEX_USE_STD) || defined(CXXD_USE_STD)
				#define CXXD_REGEX_ERROR
				#error CXXD: C++ standard regex is not available
			#else
				#define CXXD_HAS_STD_REGEX 0
				#define CXXD_REGEX_NS boost
				#define CXXD_REGEX_HEADER <boost/regex.hpp>
			#endif
		#else
			#define CXXD_HAS_STD_REGEX 1
			#define CXXD_REGEX_NS std
			#define CXXD_REGEX_HEADER <regex>
		#endif
	#endif
#endif
