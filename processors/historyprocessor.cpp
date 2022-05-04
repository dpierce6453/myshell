//
// Created by Dan on 4/24/2022.
//

#include "historyprocessor.h"
#include "../historybuffer.h"
#include "cmdprocessor.h"

historyprocessor::historyprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream) : cmdprocessor(enteredcmd, outstream) {}

void historyprocessor::docommand() {
    int cmdnum = 0;
    historybuffer& hbuf = historybuffer::instance();
    switch (whatcmd)
    {
        case PRINT:
            for(auto str : hbuf.untokenize())
                os << cmdnum++ << ": " << str << std::endl;
            break;
        case CLEAR:
            hbuf.clear();
            break;
    }
}

bool historyprocessor::checkparms() {
    // Either no parameters or '-c' is allowed. nothing else
    bool ret = true;
    if(cmd.size() == 1)
        whatcmd = PRINT;
    else if(cmd[1] == "-c")
        whatcmd = CLEAR;
    else
        ret = false;
    return ret;
}

