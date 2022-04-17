//
// Created by harldanp on 4/16/2022.
//

#include "gtest/gtest.h"

#include "../historybuffer.h"
#include "mystring.h"

TEST(buffertests, savecmd)
{
    historybuffer buf;

    mystring test = "start program parm1 parm2";
    auto cmd = test.removeextraspaces().tokenize();
    ASSERT_TRUE(buf.get().size() == 0);
    buf.get().push_back(cmd);
    ASSERT_TRUE(buf.get().size() == 1);
}

TEST(buffertests, untokenize)
{
    historybuffer buf;
    std::vector<mystring> strvec;
    strvec.push_back("start program parm1 parm2");
    strvec.push_back("start chromium-browser");
    buf.get().push_back(strvec[0].removeextraspaces().tokenize());
    buf.get().push_back(strvec[1].removeextraspaces().tokenize());
    std::vector<std::string> cmdhistory = buf.untokenize();
    for(auto v : cmdhistory)
    {
        ASSERT_STREQ(v.c_str(), strvec.front().c_str());
        strvec.erase(strvec.begin());
    }
}