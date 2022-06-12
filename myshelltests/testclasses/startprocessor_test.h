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
    virtual pid_t myfork() override final;
    virtual void myexec(const char* path, char* const arg[]) override final;
    virtual void towaitornot_thatisthequestion(pid_t child_pid) override final;

    pid_t myforkret = 0;
public:
    void setMyforkret(pid_t myforkret);

};


#endif //MYSHELL_STARTPROCESSOR_TEST_H
