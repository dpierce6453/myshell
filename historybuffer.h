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
    using historyvector_it = std::vector<std::vector<std::string>>::iterator;
    static historybuffer& instance() {
        static historybuffer inst;
        return inst;
    }
    historyvector &get() {return buffer;};
    std::vector<std::string>& untokenize();
    void clear();
    bool setreplay(size_t _whichcmd);
    historyvector_it getreplay( void );
private:
    historyvector buffer;
    std::vector<std::string> cmds;   //untokenized commands
    size_t whichcmd;
    bool isreplay = false;
    // constructor and destructor private.  copying not allowed.
    historybuffer() = default;
    ~historybuffer() = default;
    historybuffer(const historybuffer&) = delete;
    historybuffer& operator=(const historybuffer&) = delete;
};


#endif //MYSHELL_HISTORYBUFFER_H
