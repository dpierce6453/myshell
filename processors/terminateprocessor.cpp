//
// Created by harldanp on 5/8/2022.
//

#include <algorithm>
#include <signal.h>
#include <errno.h>

#include "terminateprocessor.h"
#include "../pidvector.h"

void terminateprocessor::docommand() {

    auto &pvec = pidvector::instance().get();
    pid_t whichpid;

    try {
        whichpid = stoi(cmd[1]);
        // I need to figure out if the process is stil running.  If it is not
        // then I should do nothing other than remove the PID from the vector.
        // If it is running then I should kill it.
        // need to figure out how to find and remove the value.
        auto item = std::find(pvec.begin(), pvec.end(), whichpid);
        if(item == pvec.end())
        {
            os << badpid_str << std::endl;
        }
        else
        {
            int ret = dokill(whichpid);
            if (ret == -1)
            {
                switch (geterrno())
                {
                    case ESRCH:
                        os << noprocess_str << whichpid << std::endl;
                        break;
                    default:
                        os << "Something really strange happened" << std::endl;
                        break;
                }
            }
            else
            {
                os << goodpid_str << whichpid << std::endl;
            }
            pvec.erase(item);
        }

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

int terminateprocessor::dokill(pid_t pid) {
    return kill(pid, SIGKILL);
}

int terminateprocessor::geterrno(void) {
    return errno;
}


// I need to figure out if the process is stil running.  If it is not
// then I should do nothing other than remove the PID from the vector.
// If it is running then I should kill it.