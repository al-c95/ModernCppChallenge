#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/StringsAndRegex/joining_strings.h"

TEST(StringsAndRegex_JoiningStrings, validate_strings_joined_correctly)
{
    // arrange
    std::vector<std::string> input_strings = {"this", "is", "an", "example"};
    std::string delimiter = " ";
    std::string expected_result = "this is an example";

    // act
    std::string actual_result = joining_strings::join_strings_with_delimiter(input_strings, delimiter);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_JoiningStrings, validate_empty_strings_joined_correctly)
{
    // arrange
    std::vector<std::string> input_strings = {"", "", "", ""};
    std::string delimiter = ";";
    std::string expected_result = ";;;";

    // act
    std::string actual_result = joining_strings::join_strings_with_delimiter(input_strings, delimiter);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_JoiningStrings, validate_empty_input_returns_empty_output)
{
    // arrange
    std::vector<std::string> input_strings = {};
    std::string delimiter = " ";
    std::string expected_result = "";

    // act
    std::string actual_result = joining_strings::join_strings_with_delimiter(input_strings, delimiter);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}