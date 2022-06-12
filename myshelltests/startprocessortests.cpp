//
// Created by harldanp on 6/12/2022.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <testclasses/startprocessor_test.h>


struct startprocessor_testsuite : public ::testing::Test {

    static void SetUpTestSuite() {

    }

    static void TearDownTestSuite() {
    }
    void SetUp() override
    {
    }
    void TearDown()
    {
    }
    std::ostringstream oss;

};


TEST_F(startprocessor_testsuite, startprocessor_create)
{
    std::vector<std::string> testcmd = {"start", "chromium-browser"};
    startprocessor_test sut(testcmd);
    ASSERT_TRUE(sut.process());
}

TEST_F(startprocessor_testsuite, starprocessor_forkfail)
{
    std::string str = startprocessor::forkfail_str + '\n';
    std::vector<std::string> testcmd = {"start", "chromium-browser"};
    startprocessor_test sut(testcmd, oss);
    sut.setMyforkret(-1);

    ASSERT_TRUE(sut.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
}

TEST_F(startprocessor_testsuite, starprocessor_forksucceedparentproc)
{
    std::string str = startprocessor::waitchildproc_str + "0" + '\n';
    std::vector<std::string> testcmd = {"start", "chromium-browser"};
    startprocessor_test sut(testcmd, oss);
    sut.setMyforkret(1);

    ASSERT_TRUE(sut.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
}
TEST_F(startprocessor_testsuite, starprocessor_forksucceedchileproc)
{
    std::string cmd = "chromium-browser";
    std::string arg1 = "arg1";
    std::string arg2 = "arg2";
    std::string arg3 = "arg3";

    std::string str1("myexec was called");
    std::string str = str1 + '\n' + "path = " + cmd + '\n';
    str += "arg 1=" + arg1 + '\n';
    str += "arg 2=" + arg2 + '\n';
    str += "arg 3=" + arg3 + '\n';

    std::vector<std::string> testcmd = {"start", cmd, arg1, arg2, arg3};
    startprocessor_test sut(testcmd, oss);
    sut.setMyforkret(0);

    ASSERT_TRUE(sut.process());
    ASSERT_THAT(oss.str(), ::testing::StrEq(str));
}