//
// Created by harldanp on 5/1/2022.
//

#ifndef MYSHELL_STARTPROCESSOR_H
#define MYSHELL_STARTPROCESSOR_H

#include <unistd.h>

#include "cmdprocessor.h"

class startprocessor : public cmdprocessor {
public:
    inline static const std::string forkfail_str = "Fork failed for some reason";
    inline static const std::string waitchildproc_str = "Child exited with status = ";
    startprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout): cmdprocessor(enteredcmd, outstream) {};

private:
    void docommand() final;
    bool checkparms() final;
    virtual pid_t myfork();
    virtual void myexec(const char* path,  char* const arg[]);
    virtual void towaitornot_thatisthequestion(pid_t child_pid);

};


#endif //MYSHELL_STARTPROCESSOR_H
