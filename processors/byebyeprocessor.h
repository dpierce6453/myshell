//
// Created by harldanp on 4/29/2022.
//

#ifndef MYSHELL_BYEBYEPROCESSOR_H
#define MYSHELL_BYEBYEPROCESSOR_H


#include <string>
#include <vector>
#include <memory>

#include "cmdprocessor.h"

class byebyeprocessor : public cmdprocessor {
public:
    byebyeprocessor(std::vector<std::string> &enteredcmd, std::shared_ptr<std::ostream> _ostream);
    byebyeprocessor(std::vector<std::string> &enteredcmd, const std::string filename);
private:
    void docommand()  override final;
    bool checkparms() override final;
    byebyeprocessor() = delete;
    virtual void progexit();
    std::shared_ptr<std::ostream> ofs;
};


#endif //MYSHELL_BYEBYEPROCESSOR_H
