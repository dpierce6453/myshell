//
// Created by Dan on 4/24/2022.
//

#include "gtest/gtest.h"

#include "processors/historyprocessor.h"
#include "historybuffer.h"
#include "mystring.h"
#include "mystring.h"
#include "processors/byebyeprocessor.h"
#include "byebyeprocessor_test.h"


void fillhistorybuffer(historybuffer &hbuf);

static std::vector<mystring> historybufferstrings =
        {"start program parm1 parm2",
         "start chromium browser",
         "history",
         "history -c",
         "background program parm1 parm2",
         "start /usr/bin/xterm -bg green",
         "replay 3",
         "terminate 1234"};

TEST(processortests, historyprocessor_checkparms_with_clear_parm)
{
    std::vector<std::string> testcmd = {"history", "-c"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.process());
}

TEST(processortests, historyprocessor_checkparms_with_no_parms)
{
    std::vector<std::string> testcmd = {"history"};
    auto hp = historyprocessor(testcmd);
    ASSERT_TRUE(hp.process());
}
TEST(processortests, byebyeprocessor_check)
{
    historybuffer& hbuf = historybuffer::instance();
    hbuf.clear();
    fillhistorybuffer(hbuf);

    std::ostringstream oss1;
    for(auto str : historybufferstrings)
        oss1 << str << std::endl;

    std::vector<std::string> testcmd = {"byebye"};
    auto _ostream = std::make_shared<std::ostringstream>();
    auto hp = byebyeprocessor_test(testcmd, _ostream);
    ASSERT_TRUE(hp.process());
    ASSERT_TRUE(oss1.str() == _ostream->str());
}

TEST(processortests, historyprocessor_checkparms_with_bad_parm)
{

    std::ostringstream oss;
    std::vector<std::string> testcmd = {"history", "goobledy"};
    auto hp = historyprocessor(testcmd, oss);
    ASSERT_FALSE(hp.process());
}


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
    ASSERT_TRUE(hp.process());
    ASSERT_TRUE(oss1.str() == oss2.str());
}

TEST(processortests, historyprocessor_process_clear_history_cmd)
{
    historybuffer& hbuf = historybuffer::instance();
    fillhistorybuffer(hbuf);

    std::ostringstream oss3;

    std::vector<std::string> testcmd = {"history", "-c"};
    auto hp1 = historyprocessor(testcmd);
    ASSERT_TRUE(hp1.process());
    ASSERT_TRUE(hbuf.get().size() == 0);

    // now the history buffer should be empty.  Try to print it.
    testcmd = {"history"};
    auto hp2 = historyprocessor(testcmd, oss3);
    ASSERT_TRUE(hp2.process());
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