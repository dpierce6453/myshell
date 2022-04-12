//
// Created by Dan on 4/12/2022.
//

#include <vector>
#include <sstream>
#include "stringutils.h"


std::string stringutils::removeextraspaces(std::string &str) {
    std::string ret;

    //strip any leading spaces
    auto it = str.begin();
    while(std::isspace(*it)) it++;

    for(; it < str.end(); )
    {
        ret.push_back(*it);
        if(std::isspace(*it++))
        {
            //found a space.  see if the next char is a space.  If so remember it
            while(std::isspace(*it))
            {
                it++;
                if(it == str.end())
                {
                    ret.pop_back();
                    return ret;
                }
            }
        }
    }
    return ret;
}

std::vector<std::string> stringutils::tokenizestring(std::string &str) {
    std::istringstream line(str);
    std::vector<std::string> ret;
    std::string temp;
    while(std::getline(line, temp, ' '))
    {
        ret.push_back(temp);
        temp.clear();
    }
    return ret;
}
