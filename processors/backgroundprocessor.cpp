//
// Created by harldanp on 5/5/2022.
//

#include "../pidvector.h"
#include "backgroundprocessor.h"

void backgroundprocessor::towaitornot_thatisthequestion(pid_t child_pid) {
    auto &pvec = pidvector::instance();
    pvec.get().push_back(child_pid);
}

void backgroundprocessor::myexec(const char *path,  char * const arg[]) {
    execvp(path, arg);
    exit(0);
}
