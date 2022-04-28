//
// Created by Dan on 4/12/2022.
//

#include "gtest/gtest.h"

#include "mystring.h"

TEST(StringutilsTest, TestRemoveSpaces) {
    mystring test = "AB  CD      EF";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces_allspaces)
{
    mystring test = "        ";
    test.removeextraspaces();
    ASSERT_TRUE(test.empty());
}

TEST(StringutilsTest, TestCopyandMove)
{
    //just making sure all of this compiles for my derived string class.
    mystring test1 = "Dan is AWESOME!";
    mystring test2 = test1;
    ASSERT_STREQ(test2.c_str(), test1.c_str());
    mystring test3 = mystring(test2);
    ASSERT_STREQ(test3.c_str(), test2.c_str());
    mystring test4 = std::move(test3);
    ASSERT_STREQ(test4.c_str(), test2.c_str());
    ASSERT_STRNE(test4.c_str(), test3.c_str());
}

TEST(StringutilsTest, TestRemoveSpaces_with_leading_spaces) {
    mystring test = "  AB  CD      EF";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces_with_trailing_spaces) {
    mystring test = "AB  CD      EF   ";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}
TEST(StringutilsTest, TestRemoveSpaces_with_one_trailing_space) {
    mystring test = "AB  CD      EF ";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}
TEST(StringUtilsTest, TestTokenize) {
    mystring test ="start -v1 -v2 --dowhatever";
    auto ret = test.tokenize();
    ASSERT_STREQ(ret[0].c_str(),"start");
    ASSERT_STREQ(ret[1].c_str(),"-v1");
    ASSERT_STREQ(ret[2].c_str(),"-v2");
    ASSERT_STREQ(ret[3].c_str(),"--dowhatever");
}

