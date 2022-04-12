#include <iostream>
#include <string>
#include <vector>

#include "stringutils.h"


int main() {
    std::cout << "Welcome to my shell" << std::endl;

    std::string strCmd;
    std::vector<std::string> cmd;

    while (strCmd != "byebye")
    {
        std::cout << "# ";
        std::getline(std::cin, strCmd);
        std::cout << strCmd << std::endl;
        strCmd = stringutils::removeextraspaces(strCmd);
        std::cout << strCmd << std::endl;
        cmd = stringutils::tokenizestring(strCmd);
        for(auto & str: cmd) std::cout << str << std::endl;
    }
    return 0;
}

