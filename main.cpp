#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "mystring.h"
#include "historybuffer.h"
#include "cmdprocessor.h"
#include "historyprocessor.h"

std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd);

int main() {
    std::cout << "Welcome to my shell" << std::endl;

    mystring strCmd;
    historybuffer& hbuf = historybuffer::instance();

    while (strCmd != "byebye")
    {
        std::cout << "# ";
        std::getline(std::cin, strCmd);
        auto cmd = strCmd.removeextraspaces().tokenize();
        auto cp = Makeproccessor(cmd);
        if (cp != nullptr)
        {
            if(cp->process())
                hbuf.get().push_back(cmd);  //store the cmd in the history buffer
        }

    }
    return 0;
}

enum PROCESSORS {HISTORY};
std::map<std::string, PROCESSORS> tableofprocessors = {{"history", HISTORY}};
std::unique_ptr<cmdprocessor> Makeproccessor(std::vector<std::string> &cmd) {
    std::unique_ptr<cmdprocessor> cp = nullptr;

    auto proc = tableofprocessors.find(cmd[0]);
    if(proc != tableofprocessors.end())
    {
        switch (proc->second) {
            case HISTORY:
                cp = std::unique_ptr<cmdprocessor>(new historyprocessor(cmd));
                break;
        }
    }
    return cp;
}