//
// Created by Dan on 4/24/2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "processors/startprocessor.h"
#include "processors/replayprocessor.h"
#include "processors/historyprocessor.h"
#include "processors/byebyeprocessor.h"
#include "processors/terminateprocessor.h"

#include "historybuffer.h"
#include "pidvector.h"
#include "mystring.h"

#include "byebyeprocessor_test.h"
#include "startprocessor_test.h"
#include "backgroundprocessor_test.h"
#include "terminateprocessor_test.h"


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

TEST(processortests, replayprocessor_checkbadaregument)
{
    historybuffer& hbuf = historybuffer::instance();
    std::ostringstream oss;
    std::string str = replayprocessor::badarg_str + '\n';
    std::vector<std::string> testcmd = {"replay", "gooble"};
    replayprocessor rp(testcmd, oss);
    ASSERT_TRUE(rp.process());
    ASSERT_TRUE(oss.str() == str);
    ASSERT_TRUE(hbuf.getreplay() == hbuf.get().end());
}

TEST(processortests, replayprocessor_checkbadreplay)
{
    historybuffer& hbuf = historybuffer::instance();
    fillhistorybuffer(hbuf);

    std::ostringstream oss;
    std::string str = replayprocessor::noreplay_str + '\n';
    std::vector<std::string> testcmd = {"replay", "25"};
    replayprocessor rp(testcmd, oss);
    ASSERT_TRUE(rp.process());
    ASSERT_TRUE(oss.str() == str);
    ASSERT_TRUE(hbuf.getreplay() == hbuf.get().end());
}
TEST(processortests, replayprocessor_checkgoodreplay)
{
    auto &hbuf = historybuffer::instance();
    fillhistorybuffer(hbuf);

    std::ostringstream oss;
    std::vector<std::string> testcmd = {"replay", "3"};
    replayprocessor rp(testcmd);
    ASSERT_TRUE(rp.process());
    ASSERT_TRUE(hbuf.getreplay() == hbuf.get().begin()+3);
    ASSERT_TRUE(hbuf.getreplay() == hbuf.get().end());

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
TEST(processortests, startprocessor_create)
{
    std::vector<std::string> testcmd = {"start", "chromium-browser"};
    startprocessor_test sp(testcmd);
    ASSERT_TRUE(sp.process());
}

TEST(processortests, backgroundprocessor_create)
{
    auto &pvec = pidvector::instance().get();
    pvec.clear();
    std::vector<std::string> testcmd = {"background", "chromium-browser"};
    backgroundprocessor_test bp(testcmd);
    ASSERT_TRUE(bp.process());
    ASSERT_TRUE(pvec.size() == 1);
    ASSERT_TRUE(pvec.begin()[0] == 1);
}

TEST(processortests, terminatorprocessor_badpid)
{
    auto &pvec = pidvector::instance().get();
    std::ostringstream oss;
    pvec.clear();
    pid_t pid = 123;
    pvec.push_back(pid);
    std::string str = terminateprocessor::badpid_str + '\n';
    std::vector<std::string> testcmd = {"terminate", "321"};

    terminateprocessor tp(testcmd, oss);
    ASSERT_THAT(tp.process(), true);
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
}
TEST(processortests, terminateprocessor_notapid)
{
    auto &pvec = pidvector::instance().get();
    std::ostringstream oss;
    pvec.clear();
    pid_t pid = 123;
    pvec.push_back(pid);
    std::string str = terminateprocessor::badarg_str + '\n';
    std::vector<std::string> testcmd = {"terminate", "gooble"};

    terminateprocessor tp(testcmd, oss);
    ASSERT_TRUE(tp.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
}
TEST(processortests, terminateprocessor_goodpidbutprocessnotrunning)
{
    auto &pvec = pidvector::instance().get();
    std::ostringstream oss;
    pvec.clear();
    pid_t pid = 123;
    pvec.push_back(pid);
    std::string str = terminateprocessor::noprocess_str + std::to_string(pid) + '\n';
    std::vector<std::string> testcmd = {"terminate", std::to_string(pid)};

    terminateprocessor tp(testcmd, oss);
    ASSERT_TRUE(tp.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
    auto item = std::find(pvec.begin(), pvec.end(), pid);
    ASSERT_THAT(item, testing::Eq(pvec.end()));
}

TEST(processortests, terminateprocessor_goodpid)
{
    auto &pvec = pidvector::instance().get();
    std::ostringstream oss;
    pvec.clear();
    pid_t pid = 123;
    pvec.push_back(pid);
    std::string str = terminateprocessor::goodpid_str + std::to_string(pid) + '\n';
    std::vector<std::string> testcmd = {"terminate", std::to_string(pid)};

    terminateprocessor_test tp(testcmd, oss);
    ASSERT_TRUE(tp.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
    auto item = std::find(pvec.begin(), pvec.end(), pid);
    ASSERT_THAT(item, testing::Eq(pvec.end()));
}
