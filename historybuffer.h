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
    static historybuffer& instance() {
        static historybuffer inst;
        return inst;
    }
    historyvector &get() {return buffer;};
    std::vector<std::string>& untokenize();


private:
    historyvector buffer;
    std::vector<std::string> cmds;   //untokenized commands

    historybuffer() = default;
    historybuffer(const historybuffer&) = delete;
    historybuffer& operator=(const historybuffer&) = delete;
    ~historybuffer();

};


#endif //MYSHELL_HISTORYBUFFER_H
