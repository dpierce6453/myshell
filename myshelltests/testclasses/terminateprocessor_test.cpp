//
// Created by harldanp on 6/8/2022.
//

#include "terminateprocessor_test.h"

int terminateprocessor_test::dokill(pid_t pid) {
    return killretvalue;
}

int terminateprocessor_test::geterrno(void) {
    return ESRCH;
}

void terminateprocessor_test::setKillretvalue(int killretvalue) {
    terminateprocessor_test::killretvalue = killretvalue;
}
