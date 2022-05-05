//
// Created by harldanp on 5/5/2022.
//

#include "backgroundprocessor_test.h"

pid_t backgroundprocessor_test::myfork() {
    return 1;
}

int backgroundprocessor_test::myexec(const char *path, char* const arg[]) {
    os << "myexec was called" << std::endl;
    os << "path = " << path << std::endl;
    int index=0;
    while( arg[index] != NULL)
    {
        os << "arg " << index << " " << arg[index] << std::endl;
        index++;
    }
    return 0;
}