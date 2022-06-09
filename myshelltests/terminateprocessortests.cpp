//
// Created by harldanp on 6/9/2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "processors/terminateprocessor.h"
#include "testclasses/terminateprocessor_test.h"
#include "pidvector.h"


struct terminateprocessor_testsuite : public ::testing::Test {

    static void SetUpTestSuite() {

    }

    static void TearDownTestSuite() {
    }
    void SetUp() override
    {
        pvec.clear();
        pid = 123;
        pvec.push_back(pid);
    }
    void TearDown()
    {
    }
    void badpidtest(std::string retstr, std::string testcmdarg);
    void goodpidtest(std::string retstr, int killretvalue);
    static std::vector<pid_t> &pvec;
    pid_t pid;
    std::ostringstream oss;
};

std::vector<pid_t> &terminateprocessor_testsuite::pvec = pidvector::instance().get();

TEST_F(terminateprocessor_testsuite, terminatorprocessor_badpid)
{
    badpidtest(terminateprocessor::badpid_str, "321");
}
TEST_F(terminateprocessor_testsuite, terminateprocessor_notapid)
{
    badpidtest(terminateprocessor::badarg_str, "gooble");
}

TEST_F(terminateprocessor_testsuite, terminateprocessor_goodpidbutprocessnotrunning)
{
    goodpidtest(terminateprocessor::noprocess_str, -1);
}

TEST_F(terminateprocessor_testsuite, terminateprocessor_goodpid)
{
    goodpidtest(terminateprocessor::goodpid_str, 0);
}

void terminateprocessor_testsuite::badpidtest(std::string retstr, std::string testcmdarg)
{
    std::string str = retstr + '\n';
    std::vector<std::string> testcmd = {"terminate", testcmdarg};
    terminateprocessor tp(testcmd, oss);

    ASSERT_TRUE(tp.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
    auto item = std::find(pvec.begin(), pvec.end(), pid);
    ASSERT_THAT(item, testing::Ne(pvec.end()));

}

void terminateprocessor_testsuite::goodpidtest(std::string retstr, int killretvalue)
{
    std::string str = retstr + std::to_string(pid) + '\n';
    std::vector<std::string> testcmd = {"terminate", std::to_string(pid)};

    terminateprocessor_test tp(testcmd, oss);
    tp.setKillretvalue(killretvalue);

    ASSERT_TRUE(tp.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
    auto item = std::find(pvec.begin(), pvec.end(), pid);
    ASSERT_THAT(item, testing::Eq(pvec.end()));
}
