//
// Created by harldanp on 4/29/2022.
//

#ifndef MYSHELL_PROCESSORFACTORY_H
#define MYSHELL_PROCESSORFACTORY_H

#include <map>
#include <string>
#include <memory>

#include "cmdprocessor.h"

class processorfactory {
private:
    enum PROCESSORS {HISTORY, BYEBYE, START};
    const std::map<std::string, PROCESSORS> tableofprocessors = {{"history", HISTORY},
                                                                 {"byebye", BYEBYE},
                                                                 {"start", START}};

public:
    std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd);
};


#endif //MYSHELL_PROCESSORFACTORY_H
