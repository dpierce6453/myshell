//
// Created by harldanp on 4/16/2022.
//

#include "historybuffer.h"

void historybuffer::savecmd(std::vector<std::string> v) {
    buffer.push_back(v);
}

size_t historybuffer::length() {
    return buffer.size();
}

std::vector<std::string>& historybuffer::untokenize() {
    cmds.clear();
    for(auto v : buffer)
    {
        std::string str;
        str.clear();
        for(auto innner : v)
        {
             str += innner;
             str += ' ';
        }
        str.pop_back();
        cmds.push_back(str);
    }

    return cmds;
}
