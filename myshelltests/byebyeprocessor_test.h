//
// Created by harldanp on 4/29/2022.
//

#ifndef MYSHELL_BYEBYEPROCESSOR_TEST_H
#define MYSHELL_BYEBYEPROCESSOR_TEST_H

#include "processors/byebyeprocessor.h"

class byebyeprocessor_test : public byebyeprocessor {
public:
        byebyeprocessor_test(std::vector<std::string> &enteredcmd, std::shared_ptr<std::ostream> _ostream) : byebyeprocessor(enteredcmd, _ostream){};

        void progexit() override final;

};


#endif //MYSHELL_BYEBYEPROCESSOR_TEST_H
