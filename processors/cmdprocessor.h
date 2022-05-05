//
// Created by Dan on 4/22/2022.
//

#ifndef MYSHELL_CMDPROCESSOR_H
#define MYSHELL_CMDPROCESSOR_H


#include <string>
#include <vector>
#include <iostream>

class cmdprocessor {
public:
    cmdprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream = std::cout);

    virtual ~cmdprocessor();
    bool process();
    cmdprocessor(const cmdprocessor& cp);
    cmdprocessor(const cmdprocessor&& cp);
    virtual bool Iscommandsaved() {return true;};
protected:
    std::vector<std::string> cmd;
    std::ostream &os;
private:
    virtual bool checkparms() = 0;
    virtual void docommand() = 0;
    cmdprocessor() = delete;
};


#endif //MYSHELL_CMDPROCESSOR_H
