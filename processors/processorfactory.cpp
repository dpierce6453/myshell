//
// Created by harldanp on 4/29/2022.
//

#include "processorfactory.h"
#include "historyprocessor.h"
#include "byebyeprocessor.h"
#include "startprocessor.h"
#include "replayprocessor.h"
#include "backgroundprocessor.h"

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
                break;
            case START:
                cp = std::unique_ptr<cmdprocessor>( new startprocessor(cmd));
                break;
            case REPLAY:
                cp = std::unique_ptr<cmdprocessor>( new replayprocessor(cmd));
                break;
            case BACKGROUND:
                cp = std::unique_ptr<cmdprocessor>(new backgroundprocessor( cmd) );
                break;
        }
    }
    return cp;
}
