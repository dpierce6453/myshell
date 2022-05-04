//
// Created by harldanp on 4/16/2022.
//

#include "gtest/gtest.h"

#include "../historybuffer.h"
#include "mystring.h"

void setuphistorybuffer(std::vector<mystring> &strvec);

TEST(buffertests, savecmd)
{
    auto hvec = historybuffer::instance().get();
    hvec.clear();
    mystring test = "start program parm1 parm2";
    auto cmd = test.removeextraspaces().tokenize();
    ASSERT_TRUE(hvec.empty());
    hvec.push_back(cmd);
    ASSERT_TRUE(hvec.size() == 1);
}

TEST(buffertests, untokenize)
{
    historybuffer& hbuf = historybuffer::instance();
    std::vector<mystring> strvec;
    setuphistorybuffer(strvec);
    std::vector<std::string> cmdhistory = hbuf.untokenize();
    for(auto const &v : cmdhistory)
    {
        ASSERT_STREQ(v.c_str(), strvec.front().c_str());
        strvec.erase(strvec.begin());
    }
}

TEST(buffertests, replay)
{
    historybuffer& hbuf = historybuffer::instance();
    std::vector<mystring> strvec;
    setuphistorybuffer(strvec);
    historybuffer::historyvector_it hbuf_it = hbuf.getreplay();
    ASSERT_TRUE(hbuf_it == hbuf.get().end());
    ASSERT_FALSE(hbuf.setreplay(2));
    ASSERT_TRUE(hbuf.setreplay(1));
    ASSERT_TRUE(hbuf.getreplay() == hbuf.get().begin()+1);

}

void setuphistorybuffer(std::vector<mystring> &strvec)
{
    historybuffer& hbuf = historybuffer::instance();
    hbuf.get().clear();
    strvec.emplace_back("start program parm1 parm2");
    strvec.emplace_back("start chromium-browser");
    hbuf.get().push_back(strvec[0].removeextraspaces().tokenize());
    hbuf.get().push_back(strvec[1].removeextraspaces().tokenize());

}