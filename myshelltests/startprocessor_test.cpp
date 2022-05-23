//
// Created by harldanp on 5/1/2022.
//

#include "startprocessor_test.h"

pid_t startprocessor_test::myfork() {
    return 0;
}

void startprocessor_test::myexec(const char *path, char* const arg[]) {
    os << "myexec was called" << std::endl;
    os << "path = " << path << std::endl;
    int index=0;
    while( arg[index] != NULL)
    {
        os << "arg " << index << " " << arg[index] << std::endl;
        index++;
    }
    //return 0;
}

startprocessor_test::startprocessor_test(std::vector<std::string> &enteredcmd, std::ostream &outstream) : startprocessor(
        enteredcmd, outstream) {

}
