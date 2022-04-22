#include <iostream>
#include <string>
#include <vector>

#include "mystring.h"
#include "historybuffer.h"


int main() {
    std::cout << "Welcome to my shell" << std::endl;

    mystring strCmd;
    historybuffer& hbuf = historybuffer::instance();

    while (strCmd != "byebye")
    {
        std::cout << "# ";
        std::getline(std::cin, strCmd);
        auto cmd = strCmd.removeextraspaces().tokenize();
        //store the cmd in the history buffer
        hbuf.get().push_back(cmd);

        for(auto & str: cmd) std::cout << str << std::endl;
    }
    return 0;
}

