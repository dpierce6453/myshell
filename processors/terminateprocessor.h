//
// Created by harldanp on 5/8/2022.
//

#ifndef MYSHELL_TERMINATEPROCESSOR_H
#define MYSHELL_TERMINATEPROCESSOR_H


#include "cmdprocessor.h"

class terminateprocessor : public cmdprocessor {
public:
    inline static const std::string badarg_str = "The argument was not a number!";
    inline static const std::string badpid_str = "The argument was not a PID in the list";
    inline static const std::string goodpid_str = "Terminating Process: ";
    inline static const std::string noprocess_str = "There is no process running with that PID: ";
    terminateprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout) : cmdprocessor(enteredcmd, outstream) {}
private:
    void docommand() final;
    bool checkparms() final;
    virtual int dokill(pid_t pid);
    virtual int geterrno( void );

};


#endif //MYSHELL_TERMINATEPROCESSOR_H
