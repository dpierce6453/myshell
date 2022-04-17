//
// Created by harldanp on 4/16/2022.
//

#ifndef MYSHELL_HISTORYBUFFER_H
#define MYSHELL_HISTORYBUFFER_H


#include <string>
#include <vector>

class historybuffer {

public:
    using historyvector = std::vector<std::vector<std::string>>;
    void savecmd(std::vector<std::string> v);
    size_t length();
    historyvector &get() {return buffer;};
    std::vector<std::string>& untokenize();


private:
    historyvector buffer;
    std::vector<std::string> cmds;   //untokenized commands

};


#endif //MYSHELL_HISTORYBUFFER_H
