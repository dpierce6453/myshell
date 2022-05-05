//
// Created by harldanp on 5/5/2022.
//

#ifndef MYSHELL_PIDVECTOR_H
#define MYSHELL_PIDVECTOR_H

#include <vector>
#include <unistd.h>

class pidvector {
public:
    static pidvector& instance() { static pidvector inst; return inst; }
    std::vector<pid_t> &get() {return pids;};
private:
    std::vector<pid_t> pids;
    pidvector() = default;
    ~pidvector() = default;
    pidvector(const pidvector&) = delete;
    pidvector& operator=(const pidvector&) = delete;
};


#endif //MYSHELL_PIDVECTOR_H
