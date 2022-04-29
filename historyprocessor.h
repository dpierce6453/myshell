//
// Created by Dan on 4/24/2022.
//

#ifndef MYSHELL_HISTORYPROCESSOR_H
#define MYSHELL_HISTORYPROCESSOR_H

#include <iostream>

#include "cmdprocessor.h"

class historyprocessor : public cmdprocessor {
public:
    historyprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout);

private:
    void docommand() final;
    bool checkparms() final;
    enum e_whatcmd {PRINT, CLEAR};
    enum e_whatcmd whatcmd;

};


#endif //MYSHELL_HISTORYPROCESSOR_H
