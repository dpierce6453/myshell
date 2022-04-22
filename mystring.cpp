//
// Created by harldanp on 4/15/2022.


#include <sstream>
#include <cctype>
#include "mystring.h"

mystring &mystring::removeextraspaces() {
    std::string ret;

    //strip any leading spaces
    auto it = begin();
    while(std::isspace(*it)) it++;

    for(; it < end(); )
    {
        ret.push_back(*it);
        if(std::isspace(*it++))
        {
            //found a space.  see if the next char is a space.  If so remember it
            while(std::isspace(*it))
            {
                it++;
                if(it == end())
                {
                    ret.pop_back();
                    swap(ret);
                    return *this;
                }
            }
        }
    }
    swap(ret);
    return *this;
}

mystring::mystring(const char *string) : std::string(string) {}

std::vector<std::string> mystring::tokenize() {
    std::istringstream line(*this);
    std::vector<std::string> ret;
    std::string temp;
    while(std::getline(line, temp, ' '))
    {
        ret.push_back(temp);
        temp.clear();
    }
    return ret;
}

