//
// Created by Dan on 4/12/2022.
//

#include "gtest/gtest.h"

#include "../stringutils.h"

TEST(StringutilsTest, TestRemoveSpaces) {
    std::string test = "AB  CD      EF";
    auto result = stringutils::removeextraspaces(test);
    ASSERT_STREQ(result.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces2) {
    std::string test = "  AB  CD      EF";
    auto result = stringutils::removeextraspaces(test);
    ASSERT_STREQ(result.c_str(), "AB CD EF");
}

TEST(StringutilsTest, TestRemoveSpaces3) {
    std::string test = "AB  CD      EF   ";
    auto result = stringutils::removeextraspaces(test);
    ASSERT_STREQ(result.c_str(), "AB CD EF");
}