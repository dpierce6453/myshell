//
// Created by harldanp on 4/29/2022.
//

#ifndef MYSHELL_PROCESSORFACTORY_H
#define MYSHELL_PROCESSORFACTORY_H

#include <map>
#include <string>

#include "cmdprocessor.h"

class processorfactory {
private:
    const enum PROCESSORS {HISTORY, BYEBYE};
    const std::map<std::string, PROCESSORS> tableofprocessors = {{"history", HISTORY}, {"byebye", BYEBYE}};

public:
    std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd);
};


#endif //MYSHELL_PROCESSORFACTORY_H
