#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "mystring.h"
#include "historybuffer.h"
#include "processors/cmdprocessor.h"
#include "processors/processorfactory.h"

std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd);

int main() {
    std::cout << "Welcome to my shell" << std::endl;

    mystring strCmd;
    historybuffer& hbuf = historybuffer::instance();
    processorfactory pf;

    while (true)
    {
        std::cout << "# ";
        std::getline(std::cin, strCmd);
        auto cmd = strCmd.removeextraspaces().tokenize();
        auto cp = pf.Makeproccessor(cmd);
        if (cp != nullptr)
        {
            if(cp->process())
                hbuf.get().push_back(cmd);  //store the cmd in the history buffer
        }
        else
        {
            std::cout << "Command is not recognized" << std::endl;
        }
    }
}


