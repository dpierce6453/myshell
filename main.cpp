#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "mystring.h"
#include "historybuffer.h"
#include "processors/processorfactory.h"


static void readhistoryfile(void);
static std::vector<std::string> getcmd();

int main() {
    std::cout << "Welcome to my shell" << std::endl;

    readhistoryfile();

    historybuffer& hbuf = historybuffer::instance();
    processorfactory pf;

    while (true)
    {
        std::cout << "# ";
        auto cmd = getcmd();
        auto cp = pf.Makeproccessor(cmd);
        if (cp != nullptr)
        {
            if(cp->process() && cp->Iscommandsaved())
                hbuf.get().push_back(cmd);  //store the cmd in the history buffer
        }
        else
        {
            std::cout << "Command is not recognized" << std::endl;
        }
    }
}

std::vector<std::string> getcmd() {
    historybuffer& hbuf = historybuffer::instance();
    mystring strCmd;
    std::vector<std::string> cmd;

    auto it = hbuf.getreplay();
    if (it != hbuf.get().end()) {
        cmd = *it;
    } else {
        std::getline(std::cin, strCmd);
        cmd = strCmd.removeextraspaces().tokenize();
    }
    return cmd;
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


