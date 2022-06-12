//
// Created by harldanp on 5/1/2022.
//

#include "startprocessor_test.h"

pid_t startprocessor_test::myfork() {
    return myforkret;
}

void startprocessor_test::myexec(const char *path, char* const arg[]) {
    os << "myexec was called" << std::endl;
    os << "path = " << path << std::endl;
    int index=1;
    while( arg[index] != NULL)
    {
        os << "arg " << index << "=" << arg[index] << std::endl;
        index++;
    }
}

startprocessor_test::startprocessor_test(std::vector<std::string> &enteredcmd, std::ostream &outstream) : startprocessor(
        enteredcmd, outstream) {

}

void startprocessor_test::setMyforkret(pid_t myforkret)
{
    startprocessor_test::myforkret = myforkret;
}

void startprocessor_test::towaitornot_thatisthequestion(pid_t child_pid)
{
    int status = 0;
    os << waitchildproc_str << status << std::endl;
}
