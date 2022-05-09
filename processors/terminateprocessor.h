//
// Created by harldanp on 5/8/2022.
//

#ifndef MYSHELL_TERMINATEPROCESSOR_H
#define MYSHELL_TERMINATEPROCESSOR_H


#include "cmdprocessor.h"

class terminateprocessor : public cmdprocessor {
public:
    inline static const std::string badarg_str = "The argument was not a number!";
    terminateprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout) : cmdprocessor(enteredcmd, outstream) {}
private:
    void docommand() final;
    bool checkparms() final;

};


#endif //MYSHELL_TERMINATEPROCESSOR_H
