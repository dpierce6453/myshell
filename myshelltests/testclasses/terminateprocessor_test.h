//
// Created by harldanp on 6/8/2022.
//

#ifndef MYSHELL_TERMINATEPROCESSOR_TEST_H
#define MYSHELL_TERMINATEPROCESSOR_TEST_H


#include <processors/terminateprocessor.h>

class terminateprocessor_test : public terminateprocessor {
public:
    terminateprocessor_test(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout)
        : terminateprocessor(enteredcmd, outstream) {}

private:
    int dokill(pid_t pid) override final;
    int geterrno( void ) override final;
    int killretvalue = 0;
public:
    void setKillretvalue(int killretvalue);

};


#endif //MYSHELL_TERMINATEPROCESSOR_TEST_H
