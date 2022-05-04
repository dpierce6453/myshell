//
// Created by harldanp on 5/4/2022.
//

#ifndef MYSHELL_REPLAYPROCESSOR_H
#define MYSHELL_REPLAYPROCESSOR_H


#include "cmdprocessor.h"

class replayprocessor : public cmdprocessor {
public:
    inline static const std::string noreplay_str = "The History Buffer is not that large - could not perform command";
    inline static const std::string badarg_str = "The argument was not a number!";
    replayprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout) : cmdprocessor(enteredcmd, outstream) {}

private:
    void docommand() final;
    bool checkparms() final;

};


#endif //MYSHELL_REPLAYPROCESSOR_H
