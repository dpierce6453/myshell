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
        cmd = strCmd.removeextraspaces().tokenize();
        //store the cmd in the history buffer

        for(auto & str: cmd) std::cout << str << std::endl;
    }
    return 0;
}

