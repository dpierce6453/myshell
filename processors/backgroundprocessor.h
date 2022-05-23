//
// Created by harldanp on 5/5/2022.
//

#ifndef MYSHELL_BACKGROUNDPROCESSOR_H
#define MYSHELL_BACKGROUNDPROCESSOR_H


#include "startprocessor.h"

class backgroundprocessor : public startprocessor {
public:
    backgroundprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout) : startprocessor(enteredcmd, outstream) {}
private:
    virtual void towaitornot_thatisthequestion(pid_t child_pid);
    virtual void myexec(const char* path,  char* const arg[]);


};


#endif //MYSHELL_BACKGROUNDPROCESSOR_H
