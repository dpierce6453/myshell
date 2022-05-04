//
// Created by harldanp on 5/1/2022.
//

#include <sys/wait.h>
#include "startprocessor.h"
#include "../mystring.h"

startprocessor::startprocessor(std::vector<std::string> &enteredcmd, std::ostream &outstream) : cmdprocessor(enteredcmd,
                                                                                                             outstream) {}

void startprocessor::docommand() {
    pid_t child_pid = myfork();
    if(child_pid == -1)
    {
        os << "Fork failed for some reason" << std::endl;
    }
    else if (child_pid > 0)
    {
        //This is the parent process.  Need to wait here until child exits
        int status;
        waitpid(child_pid, &status, 0);
        os << "Child exited with status = " << status << std::endl;
    }
    else if (child_pid == 0)
    {
        // This is the child process.
        char* argsv[cmd.size()+1];
        int index = 0;
        for(auto &str: cmd)
        {
            argsv[index++] = str.data();
        }
        argsv[index] = NULL;
        myexec(cmd[1].c_str(), &argsv[1]);
    }
}

bool startprocessor::checkparms() {
    //all that is required is to have more than one argument.
    bool ret = false;
    if (cmd.size() > 1) {
        ret = true;
    }
    return ret;
}
pid_t startprocessor::myfork() {
    return fork();
}

int startprocessor::myexec(const char *path,  char * const arg[]) {
    return execvp(path, arg);
}
