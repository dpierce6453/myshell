#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "mystring.h"
#include "historybuffer.h"
#include "processors/cmdprocessor.h"
#include "processors/processorfactory.h"

std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd);

void readhistoryfile(void);

int main() {
    std::cout << "Welcome to my shell" << std::endl;

    readhistoryfile();

    mystring strCmd;
    historybuffer& hbuf = historybuffer::instance();
    processorfactory pf;

    while (true)
    {
        std::cout << "# ";
        std::vector<std::string> cmd;
        // get the next command
        auto it = hbuf.getreplay();
        if(it != hbuf.get().end())
        {
            cmd = *it;
        } else
        {
            std::getline(std::cin, strCmd);
            cmd = strCmd.removeextraspaces().tokenize();
        }
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

void readhistoryfile(void) {
    historybuffer& hbuf = historybuffer::instance();
    auto inFile = std::make_unique<std::ifstream>("mysh.his");
    if(inFile->is_open())
    {
        mystring str1;
        while (!inFile->eof())
        {
            std::getline(*inFile, str1);
            if(!str1.empty())
                hbuf.get().push_back(str1.tokenize());
        }
    }
}


