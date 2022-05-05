//
// Created by harldanp on 5/5/2022.
//

#ifndef MYSHELL_BACKGROUNDPROCESSOR_TEST_H
#define MYSHELL_BACKGROUNDPROCESSOR_TEST_H


#include <processors/backgroundprocessor.h>

class backgroundprocessor_test : public backgroundprocessor {
public:
    backgroundprocessor_test(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout)
        : backgroundprocessor(enteredcmd, outstream) {};
private:
    virtual pid_t myfork() final;
    virtual int myexec(const char* path, char* const arg[]) final;
};


#endif //MYSHELL_BACKGROUNDPROCESSOR_TEST_H
