
//  (C) Copyright Edward Diener 2016
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/cxx_dual/cxx_mods.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[])
    {
  
    std::map<std::string,int> sm;
    
    sm[std::string("array")] = CXXD_HAS_STD_ARRAY;
    sm[std::string("atomic")] = CXXD_HAS_STD_ATOMIC;
    sm[std::string("bind")] = CXXD_HAS_STD_BIND;
    sm[std::string("chrono")] = CXXD_HAS_STD_CHRONO;
    sm[std::string("condition_variable")] = CXXD_HAS_STD_CONDITION_VARIABLE;
    sm[std::string("enable_shared_from_this")] = CXXD_HAS_STD_ENABLE_SHARED_FROM_THIS;
    sm[std::string("function")] = CXXD_HAS_STD_FUNCTION;
    sm[std::string("hash")] = CXXD_HAS_STD_HASH;
    sm[std::string("make_shared")] = CXXD_HAS_STD_MAKE_SHARED;
    sm[std::string("mem_fn")] = CXXD_HAS_STD_MEM_FN;
    sm[std::string("move")] = CXXD_HAS_STD_MOVE;
    sm[std::string("mutex")] = CXXD_HAS_STD_MUTEX;
    sm[std::string("random")] = CXXD_HAS_STD_RANDOM;
    sm[std::string("ratio")] = CXXD_HAS_STD_RATIO;
    sm[std::string("ref")] = CXXD_HAS_STD_REF;
    sm[std::string("regex")] = CXXD_HAS_STD_REGEX;
    sm[std::string("shared_mutex")] = CXXD_HAS_STD_SHARED_MUTEX;
    sm[std::string("shared_ptr")] = CXXD_HAS_STD_SHARED_PTR;
    sm[std::string("system_error")] = CXXD_HAS_STD_SYSTEM_ERROR;
    sm[std::string("thread")] = CXXD_HAS_STD_THREAD;
    sm[std::string("tuple")] = CXXD_HAS_STD_TUPLE;
    sm[std::string("type_index")] = CXXD_HAS_STD_TYPE_INDEX;
    sm[std::string("type_traits")] = CXXD_HAS_STD_TYPE_TRAITS;
    sm[std::string("unordered_map")] = CXXD_HAS_STD_UNORDERED_MAP;
    sm[std::string("unordered_multimap")] = CXXD_HAS_STD_UNORDERED_MULTIMAP;
    sm[std::string("unordered_multiset")] = CXXD_HAS_STD_UNORDERED_MULTISET;
    sm[std::string("unordered_set")] = CXXD_HAS_STD_UNORDERED_SET;
    sm[std::string("weak_ptr")] = CXXD_HAS_STD_WEAK_PTR;
    
    int ret = 0;
    bool debug = false;
    
    for (int i = 1; i < argc; ++i)
        {
        
        std::string s(argv[i]);
        
        if ((i == 1) && (s == "-d" || s == "--debug"))
            {
            debug = true;
            continue;
            }
        if (debug)
            {
            std::cout << "Processing \'" << s << "\'.\n";
            }
        
        std::vector<std::string> vec;
        
        boost::algorithm::split(vec,s,boost::algorithm::is_any_of("="));
        if (vec.size() == 2 && vec[1].size() == 1 && (vec[1][0] == '0' || vec[1][0] == '1'))
            {
            
            int num = boost::lexical_cast<int>(vec[1]);
            std::map<std::string,int>::iterator mit = sm.find(vec[0]);
            
            if ((mit == sm.end()) || (num != mit -> second))
                {
                ++ret;
                if (debug)
                    {
                    std::cout << "Parameter \'" << s << "\' fails.\n";
                    }
                }
            else if (debug)
                {
                std::cout << "Parameter \'" << s << "\' is succeeds.\n";
                }
            }
        else
            {
            ++ret;
            if (debug)
                {
                std::cout << "Parameter \'" << s << "\' is an invalid format.\n";
                }
            }
        }
        
    if (argc == 1)
        {
        
        typedef std::map<std::string,int>::value_type vt;
        
        BOOST_FOREACH(vt const & elem,sm)
            {
            std::cout << elem.first << " = " << elem.second << "\n";
            }
        }
        
    return ret;
    }
