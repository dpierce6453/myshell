//
// Created by harldanp on 4/16/2022.
//

#include "historybuffer.h"


std::vector<std::string>& historybuffer::untokenize() {
    cmds.clear();
    for(auto const &v : buffer)
    {
        std::string str;
        for(auto const &insidevec : v)
        {
             str += insidevec;
             str += ' ';
        }
        str.pop_back();
        cmds.push_back(str);
    }

    return cmds;
}

void historybuffer::clear() {
    historyvector vec;
    buffer.swap(vec);
}

bool historybuffer::setreplay(size_t _whichcmd) {
    if(buffer.size() > _whichcmd)
    {
        whichcmd = _whichcmd;
        isreplay = true;
    }
    return isreplay;
}

historybuffer::historyvector_it historybuffer::getreplay(void) {
    historyvector_it ret = buffer.end();
    if(isreplay && (whichcmd < buffer.size()))
    {
        isreplay = false;
        ret = buffer.begin()+whichcmd;
    }
    return ret;
}

