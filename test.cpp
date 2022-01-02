#define BOOST_TEST_MODULE LicensePlates
#include <boost/test/included/unit_test.hpp>
#include "StringsAndRegex/LicensePlates.h"

#include <algorithm>

BOOST_AUTO_TEST_CASE(validate_license_plate_number_valid)
{
   // arrange
   std::string plate_number1 = "ABC-DE 123";
   std::string plate_number2 = "ABC-DE 1234";

   // act/assert
    BOOST_TEST(LicensePlates::validate_license_plate_number(plate_number1) == true);
    BOOST_TEST(LicensePlates::validate_license_plate_number(plate_number2) == true);
}

BOOST_AUTO_TEST_CASE(validate_license_plate_number_invalid)
{
   // arrange
   std::string plate_number1 = "ABC-DE 12";
   std::string plate_number2 = "ABC-DE 12345";
   std::string plate_number3 = "ABC-De 1234";

   // act/assert
    BOOST_TEST(LicensePlates::validate_license_plate_number(plate_number1) == false);
    BOOST_TEST(LicensePlates::validate_license_plate_number(plate_number2) == false);
    BOOST_TEST(LicensePlates::validate_license_plate_number(plate_number3) == false);
}

BOOST_AUTO_TEST_CASE(get_license_plate_numbers)
{
    // arrange
    std::string test_text = "ABC-DE 123 abc AB ABC-DE 1234 AB ABC-12 ABC-DE 456";

    // act
    std::vector<std::string> results = LicensePlates::get_license_plate_numbers(test_text);

    // assert
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 123") != results.end())==true);
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 1234") != results.end())==true);
    BOOST_TEST((std::find(results.begin(), results.end(), "ABC-DE 456") != results.end())==true);
}