#include <string>
#include <gtest/gtest.h>
#include "../../src/Cryptography/caesar_cipher.h"

TEST(Cryptography_CaesarCipher, encrypt_test)
{
    // arrange
    std::string input = "AbCDEFZ";
    std::string expected_output = "CbEFGHB";

    // act
    std::string actual_output = caesar_cipher::encrypt(input, 2);

    // assert
    EXPECT_EQ(actual_output, expected_output);
}