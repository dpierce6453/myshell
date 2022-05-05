//
// Created by harldanp on 5/5/2022.
//

#include <pidvector.h>
#include "backgroundprocessor.h"

void backgroundprocessor::towaitornot_thatisthequestion(pid_t child_pid) {
    auto &pvec = pidvector::instance();
    pvec.get().push_back(child_pid);
}
