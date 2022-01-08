#define BOOST_TEST_MODULE license_plates
#include <boost/test/included/unit_test.hpp>
#include "StringsAndRegex/license_plates.h"
#include "Cryptography/validating_user_credentials.h"
#include "Cryptography/caesar_cipher.h"

#include <algorithm>

BOOST_AUTO_TEST_CASE(validate_license_plate_number_valid)
{
   // arrange
   std::string plate_number1 = "ABC-DE 123";
   std::string plate_number2 = "ABC-DE 1234";

   // act/assert
    BOOST_TEST(license_plates::validate_license_plate_number(plate_number1) == true);
    BOOST_TEST(license_plates::validate_license_plate_number(plate_number2) == true);
}

BOOST_AUTO_TEST_CASE(validate_license_plate_number_invalid)
{
   // arrange
   std::string plate_number1 = "ABC-DE 12";
   std::string plate_number2 = "ABC-DE 12345";
   std::string plate_number3 = "ABC-De 1234";

   // act/assert
    BOOST_TEST(license_plates::validate_license_plate_number(plate_number1) == false);
    BOOST_TEST(license_plates::validate_license_plate_number(plate_number2) == false);
    BOOST_TEST(license_plates::validate_license_plate_number(plate_number3) == false);
}

BOOST_AUTO_TEST_CASE(get_license_plate_numbers)
{
    // arrange
    std::string test_text = "ABC-DE 123 abc AB ABC-DE 1234 AB ABC-12 ABC-DE 456";

    // act
    std::vector<std::string> results = license_plates::get_license_plate_numbers(test_text);

    // assert
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 123") != results.end())==true);
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 1234") != results.end())==true);
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 456") != results.end())==true);
}

BOOST_AUTO_TEST_CASE(login_success)
{
    // arrange
    std::string user_name = "John Smith";
    std::string password = "secret";

    // act
    bool actual_result = login_system::login(user_name, password);

    // assert
    BOOST_TEST(actual_result==true);
}

BOOST_AUTO_TEST_CASE(login_fail)
{
    // arrange
    std::string user_name = "John Smith";
    std::string password = "test";

    // act
    bool actual_result = login_system::login(user_name, password);

    // assert
    BOOST_TEST(actual_result==false);
}

BOOST_AUTO_TEST_CASE(login_user_not_exists)
{
    // arrange
    std::string user_name = "Korky Buchek";
    std::string password = "secret";

    // act
    bool actual_result = login_system::login(user_name, password);

    // assert
    BOOST_TEST(actual_result==false);
}

BOOST_AUTO_TEST_CASE(caesar_cipher_encrypt)
{
    // arrange
    std::string input = "AbCDEFZ";
    std::string expected_output = "CbEFGHB";

    // act
    std::string actual_output = caesar_cipher::encrypt(input, 2);

    // assert
    BOOST_TEST(actual_output==expected_output);
}