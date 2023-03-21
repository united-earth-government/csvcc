/**
 * @file gtest_parse.cpp
 * @author united-earth-government
 * @brief
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright ueg (c) 2023
 *
 */

#include <gtest/gtest.h>
#include <iostream>

#include "parse.hpp"

static inline void verify_tokens(const std::vector<std::string>& data)
{
    EXPECT_EQ(data[0], "this");
    EXPECT_EQ(data[1], "is");
    EXPECT_EQ(data[2], "a");
    EXPECT_EQ(data[3], "test");
}

TEST(SplitString, NotUsingDefaultArgument)
{
    const std::string        input  = "this,is,a,test";
    std::vector<std::string> tokens = csvcc::parse::split_str(input, ',');
    verify_tokens(tokens);
}

TEST(SplitString, UsingDefaultArgument)
{
    const std::string        input  = "this,is,a,test";
    std::vector<std::string> tokens = csvcc::parse::split_str(input);
    verify_tokens(tokens);
}

TEST(SplitString, CustomDelimiter)
{
    const std::string        input  = "this-is-a-test";
    std::vector<std::string> tokens = csvcc::parse::split_str(input, '-');
    verify_tokens(tokens);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
