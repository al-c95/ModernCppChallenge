#include <string>
#include <gtest/gtest.h>
#include "../../src/Cryptography/validating_user_credentials.h"

TEST(Cryptography_validatingUserCredentials, login_success)
{
    // arrange
    std::string user_name = "John Smith";
    std::string password = "secret";

    // act
    bool result = login_system::login(user_name, password);

    // assert
    ASSERT_TRUE(result);
}

TEST(Cryptography_validatingUserCredentials, login_fail)
{
    // arrange
    std::string user_name = "John Smith";
    std::string password = "test";

    // act
    bool result = login_system::login(user_name, password);

    // assert
    ASSERT_FALSE(result);
}

TEST(Cryptography_validatingUserCredentials, user_does_not_exist)
{
    // arrange
    std::string user_name = "Korky Buchek";
    std::string password = "secret";

    // act
    bool result = login_system::login(user_name, password);

    // assert
    ASSERT_FALSE(result);
}