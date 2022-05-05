//
// Created by harldanp on 5/4/2022.
//

#include "../historybuffer.h"
#include "replayprocessor.h"

void replayprocessor::docommand() {
    historybuffer& hbuf = historybuffer::instance();

    int whichcmd;
    try {
        whichcmd = stoi(cmd[1]);
    }
    catch (std::invalid_argument& e)
    {
        os << badarg_str << std::endl;
        return;
    }
    if(hbuf.get().size() < whichcmd)
    {
        os << noreplay_str << std::endl;
    } else
    {
        hbuf.setreplay(whichcmd);
    }
}

bool replayprocessor::checkparms() {
    //all that is required is to have more than one argument.
    bool ret = false;
    if (cmd.size() > 1) {
        ret = true;
    }
    return ret;
}
