
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iterator>
#include <string>
#include <boost/detail/lightweight_test.hpp>

#include <boost/cxx_dual/regex.hpp>

int main()
    {
  
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    cxxd_regex_ns::regex self_regex("REGULAR EXPRESSIONS",
            cxxd_regex_ns::regex_constants::ECMAScript | cxxd_regex_ns::regex_constants::icase);
            
    BOOST_TEST((cxxd_regex_ns::regex_search(s, self_regex)));
 
    cxxd_regex_ns::regex word_regex("(\\S+)");
    cxxd_regex_ns::sregex_iterator words_begin = 
        cxxd_regex_ns::sregex_iterator(s.begin(), s.end(), word_regex);
    cxxd_regex_ns::sregex_iterator words_end = cxxd_regex_ns::sregex_iterator();
    
    BOOST_TEST_EQ((std::distance(words_begin, words_end)),19);
 
    const int N = 6;
    int w6lng(0);
    for (cxxd_regex_ns::sregex_iterator i = words_begin; i != words_end; ++i) {
        cxxd_regex_ns::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            ++w6lng;
        }
    }
    
    BOOST_TEST_EQ(w6lng,6);
 
    cxxd_regex_ns::regex long_word_regex("(\\w{7,})");
    std::string new_s = cxxd_regex_ns::regex_replace(s, long_word_regex, "[$&]");
    std::string exp_s = "Some people, when [confronted] with a [problem], think "
        "\"I know, I'll use [regular] [expressions].\" "
        "Now they have two [problems].";
    
    BOOST_TEST_EQ(new_s,exp_s);
    
    return boost::report_errors();
    }
