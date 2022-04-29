//
// Created by Dan on 4/22/2022.
//

#include <iostream>
#include "cmdprocessor.h"


bool cmdprocessor::process() {
    if(!checkparms())
    {
        os << "Command was not formatted properly" << std::endl;
        return false;
    }
    docommand();
    return true;
}

cmdprocessor::cmdprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream) : cmd(enteredcmd), os(outstream) {

}

cmdprocessor::~cmdprocessor() {
    //std::cout << "cmdprocessor destructor" << std::endl;
}

