//
// Created by Dan on 4/12/2022.
//

#include "gtest/gtest.h"

#include "../mystring.h"

TEST(StringutilsTest, TestRemoveSpaces4) {
    mystring test = "AB  CD      EF";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces2) {
    mystring test = "  AB  CD      EF";
    test.removeextraspaces();
    ASSERT_STREQ(test.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces3) {
    mystring test = "AB  CD      EF   ";
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