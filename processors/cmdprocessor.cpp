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
    //std::cout << "cmdprocessor constructor" << std::endl;
}

cmdprocessor::~cmdprocessor() {
    //std::cout << "cmdprocessor destructor" << std::endl;
}

cmdprocessor::cmdprocessor(const cmdprocessor &cp) : os(cp.os) {
    //std::cout << "cmdprocessor copy constructor" << std::endl;

}

cmdprocessor::cmdprocessor(const cmdprocessor &&cp) : os(cp.os){
    //std::cout << "cmdprocessor move constructor" << std::endl;

}

