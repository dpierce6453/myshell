//
// Created by Dan on 4/22/2022.
//

#ifndef MYSHELL_CMDPROCESSOR_H
#define MYSHELL_CMDPROCESSOR_H


#include <string>
#include <vector>

class cmdprocessor {
public:
    cmdprocessor(std::vector<std::string> &enteredcmd);

    virtual ~cmdprocessor();
    virtual bool checkparms() = 0;
    virtual void docommand() = 0;

protected:
    std::vector<std::string> cmd;
private:
    cmdprocessor() = delete;
};


#endif //MYSHELL_CMDPROCESSOR_H
