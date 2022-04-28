//
// Created by harldanp on 4/15/2022.


#include <sstream>
#include <cctype>
#include "mystring.h"

mystring &mystring::removeextraspaces() {
    std::string ret;
    auto it = begin();

    //skip any leading spaces
    it = skipSpaces(it);

    while(it < end())
    {
        ret.push_back(*it);
        if(std::isspace(*it++))
        {
            //found a space.  skip the next spaces.
            it = skipSpaces(it);
            if(it == end())
            {
                ret.pop_back();  // last char pushed was a trailing space - pop it off.
                break;
            }
        }
    }
    swap(ret);  //exchange *this with local string.
    return *this;
}

std::string::iterator & mystring::skipSpaces(std::string::iterator &it) {
    while(it != end() && isspace(*it))
    {
        it++;
    }
    return it;
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

