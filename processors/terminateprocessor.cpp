//
// Created by harldanp on 5/8/2022.
//

#include "terminateprocessor.h"
#include "../pidvector.h"

void terminateprocessor::docommand() {
    auto &pvec = pidvector::instance();

    int whichcmd;
    try {
        whichcmd = stoi(cmd[1]);
        // I need to figure out if the process is stil running.  If it is not
        // then I should do nothing other than remove the PID from the vector.
        // If it is running then I should kill it.
        // need to figure out how to find and remove the value.
        os << "Terminating Process " << whichcmd << std::endl;
    }
    catch (std::invalid_argument& e)
    {
        os << badarg_str << std::endl;
    }

}

bool terminateprocessor::checkparms() {
    //all that is required is to have more than one argument.
    bool ret = false;
    if (cmd.size() > 1) {
        ret = true;
    }
    return ret;
}

// I need to figure out if the process is stil running.  If it is not
// then I should do nothing other than remove the PID from the vector.
// If it is running then I should kill it.