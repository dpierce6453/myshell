//
// Created by harldanp on 4/29/2022.
//

#include "processorfactory.h"
#include "historyprocessor.h"
#include "byebyeprocessor.h"

std::unique_ptr<cmdprocessor> processorfactory::Makeproccessor(std::vector<std::string> &cmd) {
    std::unique_ptr<cmdprocessor> cp = nullptr;

    auto proc = tableofprocessors.find(cmd[0]);
    if(proc != tableofprocessors.end())
    {
        switch (proc->second) {
            case HISTORY:
                cp = std::unique_ptr<cmdprocessor>(new historyprocessor(cmd));
                break;
            case BYEBYE:
                cp = std::unique_ptr<cmdprocessor>(new byebyeprocessor(cmd, "mysh.his"));
        }
    }
    return cp;
}