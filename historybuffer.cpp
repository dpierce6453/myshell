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

