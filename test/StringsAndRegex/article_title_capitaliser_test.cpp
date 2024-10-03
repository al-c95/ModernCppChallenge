#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/StringsAndRegex/article_title_capitaliser.h"

TEST(StringsAndRegex_ArticleCapitaliser, validate_simple_title_capitalised)
{
    // arrange
    std::string title = "the modern c++ challenge";
    std::string expected_result = "The Modern C++ Challenge";

    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_title_with_leading_space_capitalised)
{
    // arrange
    std::string title = " the modern c++ challenge";
    std::string expected_result = " The Modern C++ Challenge";

    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_title_with_trailing_space_capitalised)
{
    // arrange
    std::string title = "the modern c++ challenge ";
    std::string expected_result = "The Modern C++ Challenge ";

    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_title_with_punctuation_capitalised)
{
    // arrange
    std::string title = "hello, world!";
    std::string expected_result = "Hello, World!";

    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_mixed_case_title_capitalised)
{
    // arrange
    std::string title = "hElLo WoRlD";
    std::string expected_result = "HElLo WoRlD";

    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);

    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_title_with_multiple_spaces)
{
    // arrange
    std::string title = "the  modern  c++  challenge";
    std::string expected_result = "The  Modern  C++  Challenge";
    
    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);
    
    // assert
    ASSERT_EQ(expected_result, actual_result);
}

TEST(StringsAndRegex_ArticleCapitaliser, validate_title_with_special_characters)
{
    // arrange
    std::string title = "hello@world.com";
    std::string expected_result = "Hello@world.com";
    
    // act
    std::string actual_result = article_title_capitaliser::capitalise(title);
    
    // assert
    ASSERT_EQ(expected_result, actual_result);
}