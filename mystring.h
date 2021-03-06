//
// Created by harldanp on 4/15/2022.
//

#ifndef MYSHELL_MYSTRING_H
#define MYSHELL_MYSTRING_H

#include <string>
#include <vector>

class mystring : public std::string {
public:
    mystring(const char *string);
    mystring() = default;

    mystring& removeextraspaces(void);
    std::vector<std::string> tokenize();
private:
    iterator &skipSpaces(iterator &it);
};


#endif //MYSHELL_MYSTRING_H
