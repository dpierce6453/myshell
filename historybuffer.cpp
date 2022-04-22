//
// Created by harldanp on 4/16/2022.
//

#include "historybuffer.h"


std::vector<std::string>& historybuffer::untokenize() {
    cmds.clear();
    for(auto const &v : buffer)
    {
        std::string str;
        str.clear();
        for(auto const &innner : v)
        {
             str += innner;
             str += ' ';
        }
        str.pop_back();
        cmds.push_back(str);
    }

    return cmds;
}

historybuffer::~historybuffer() = default;
