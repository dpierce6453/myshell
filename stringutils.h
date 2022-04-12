//
// Created by Dan on 4/12/2022.
//

#ifndef MYSHELL_STRINGUTILS_H
#define MYSHELL_STRINGUTILS_H

#include <string>

class stringutils {
public:
    static std::string removeextraspaces(std::string &str);
    static std::vector<std::string> tokenizestring(std::string &str);
};


#endif //MYSHELL_STRINGUTILS_H
