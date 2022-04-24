//
// Created by Dan on 4/24/2022.
//

#include "gtest/gtest.h"

#include "historyprocessor.h"
#include "historybuffer.h"
#include "mystring.h"
#include "mystring.h"

TEST(processortests, historyprocessor1)
{
    std::vector<std::string> testcmd = {"history", "-c"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.checkparms());
}

TEST(processortests, historyprocessor2)
{
    std::vector<std::string> testcmd = {"history"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.checkparms());
}

TEST(processortests, historyprocessor3)
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

TEST(processortests, historyprocessor4)
{
    historybuffer& hbuf = historybuffer::instance();
    hbuf.get().clear();
    for(auto str: historybufferstrings)
    {
        auto cmd = str.removeextraspaces().tokenize();
        hbuf.get().emplace_back(cmd);
    }

    std::ostringstream oss1, oss2;
    int cmdnum = 0;
    for(auto str : historybufferstrings)
        oss1 << cmdnum++ << ": " << str << std::endl;

    // now have the processor print the buffer
    std::vector<std::string> testcmd = {"history"};
    auto hp = historyprocessor(testcmd, oss2);
    ASSERT_TRUE(hp.checkparms());
    hp.docommand();
    ASSERT_STREQ(oss1.str().c_str(), oss2.str().c_str());
}