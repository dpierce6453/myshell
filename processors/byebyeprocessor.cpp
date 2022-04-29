//
// Created by harldanp on 4/29/2022.
//
#include <memory>
#include <fstream>

#include "byebyeprocessor.h"
#include "../historybuffer.h"


void byebyeprocessor::docommand() {
    //store the history buffer if it exists. It is assumed that the stream is empty.
    ofs->seekp(0, std::ios_base::beg);
    historybuffer& hbuf = historybuffer::instance();
    auto cmds = hbuf.untokenize();
    for(auto str: cmds)
    {
        ofs->write(str.c_str(), str.size());
        *ofs << std::endl;
    }
    //exit the program.
    progexit();
}

bool byebyeprocessor::checkparms() {
    return true;
}

void byebyeprocessor::progexit() {
    std::exit(0);
}

byebyeprocessor::byebyeprocessor(std::vector<std::string> &enteredcmd, std::shared_ptr<std::ostream> _ostream) : cmdprocessor(enteredcmd), ofs(_ostream) {
}

byebyeprocessor::byebyeprocessor(std::vector<std::string> &enteredcmd, const std::string filename) : cmdprocessor(enteredcmd) {
    std::remove(filename.c_str());
    ofs = std::make_shared<std::ofstream>(filename);
}
