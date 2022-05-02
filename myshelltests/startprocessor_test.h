//
// Created by harldanp on 5/1/2022.
//

#ifndef MYSHELL_STARTPROCESSOR_TEST_H
#define MYSHELL_STARTPROCESSOR_TEST_H


#include <processors/startprocessor.h>

class startprocessor_test : public startprocessor {
public:
    startprocessor_test(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout);
private:
    virtual pid_t myfork() final;
    virtual int myexec(const char* path, char* const arg[]) final;

};


#endif //MYSHELL_STARTPROCESSOR_TEST_H
