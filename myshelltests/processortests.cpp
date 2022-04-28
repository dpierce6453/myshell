//
// Created by Dan on 4/24/2022.
//

#include "gtest/gtest.h"

#include "historyprocessor.h"
#include "historybuffer.h"
#include "mystring.h"
#include "mystring.h"


void fillhistorybuffer(historybuffer &hbuf);

TEST(processortests, historyprocessor_checkparms_with_clear_parm)
{
    std::vector<std::string> testcmd = {"history", "-c"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.checkparms());
}

TEST(processortests, historyprocessor_checkparms_with_no_parms)
{
    std::vector<std::string> testcmd = {"history"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.checkparms());
}

TEST(processortests, historyprocessor_checkparms_with_bad_parm)
{
    std::vector<std::string> testcmd = {"history", "goobledy"};
    auto hp = historyprocessor(testcmd);
    ASSERT_FALSE(hp.checkparms());
}

static std::vector<mystring> historybufferstrings =
        {"start program parm1 parm2",
         "start chromium browser",
         "history",
         "history -c",
         "background program parm1 parm2",
         "start /usr/bin/xterm -bg green",
         "replay 3",
         "terminate 1234"};

TEST(processortests, historyprocessor_process_print_history_cmd)
{
    historybuffer& hbuf = historybuffer::instance();
    hbuf.clear();
    fillhistorybuffer(hbuf);

    std::ostringstream oss1, oss2;
    int cmdnum = 0;
    for(auto str : historybufferstrings)
        oss1 << cmdnum++ << ": " << str << std::endl;

    // now have the processor print the buffer
    std::vector<std::string> testcmd = {"history"};
    auto hp = historyprocessor(testcmd, oss2);
    ASSERT_TRUE(hp.checkparms());
    hp.docommand();
    ASSERT_TRUE(oss1.str() == oss2.str());
}

TEST(processortests, historyprocessor_process_clear_history_cmd)
{
    historybuffer& hbuf = historybuffer::instance();
    fillhistorybuffer(hbuf);

    std::ostringstream oss3;

    std::vector<std::string> testcmd = {"history", "-c"};
    auto hp1 = historyprocessor(testcmd);
    ASSERT_TRUE(hp1.checkparms());
    hp1.docommand();
    ASSERT_TRUE(hbuf.get().size() == 0);

    // now the history buffer should be empty.  Try to print it.
    testcmd = {"history"};
    auto hp2 = historyprocessor(testcmd, oss3);
    ASSERT_TRUE(hp2.checkparms());
    hp2.docommand();
    std::cout << oss3.str() << std::endl;
    ASSERT_TRUE(oss3.str().empty());

}

void fillhistorybuffer(historybuffer &hbuf)
{
    hbuf.clear();
    for(auto str: historybufferstrings)
    {
        auto cmd = str.removeextraspaces().tokenize();
        hbuf.get().emplace_back(cmd);
    }
    ASSERT_TRUE(hbuf.get().size() == historybufferstrings.size());

}