#include <iostream>
#include <string>
#include <vector>

#include "mystring.h"


int main() {
    std::cout << "Welcome to my shell" << std::endl;

    mystring strCmd;
    std::vector<std::string> cmd;

    while (strCmd != "byebye")
    {
        std::cout << "# ";
        std::getline(std::cin, strCmd);
        std::cout << strCmd << std::endl;
        strCmd.removeextraspaces();
        std::cout << strCmd << std::endl;
        cmd = strCmd.tokenize();
        for(auto & str: cmd) std::cout << str << std::endl;
    }
    return 0;
}

