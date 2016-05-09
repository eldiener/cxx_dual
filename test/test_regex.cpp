
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <iterator>
#include <string>
#include <boost/cxx_dual/regex.hpp>
#include <boost/detail/lightweight_test.hpp>

#include CXXD_REGEX_HEADER

int main()
    {
  
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    CXXD_REGEX_NS::regex self_regex("REGULAR EXPRESSIONS",
            CXXD_REGEX_NS::regex_constants::ECMAScript | CXXD_REGEX_NS::regex_constants::icase);
    if (CXXD_REGEX_NS::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }
 
    CXXD_REGEX_NS::regex word_regex("(\\S+)");
    CXXD_REGEX_NS::sregex_iterator words_begin = 
        CXXD_REGEX_NS::sregex_iterator(s.begin(), s.end(), word_regex);
    CXXD_REGEX_NS::sregex_iterator words_end = CXXD_REGEX_NS::sregex_iterator();
    
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";
 
    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (CXXD_REGEX_NS::sregex_iterator i = words_begin; i != words_end; ++i) {
        CXXD_REGEX_NS::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }
 
    CXXD_REGEX_NS::regex long_word_regex("(\\w{7,})");
    std::string new_s = CXXD_REGEX_NS::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';  
  
    return boost::report_errors();
    }
