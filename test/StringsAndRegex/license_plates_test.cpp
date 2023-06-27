#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/StringsAndRegex/license_plates.h"

TEST(StringsAndRegex_LicensePlates, validate_license_plate_number_test_Valid)
{
    // arrange
    std::string license_plate_number1 = "ABC-DE 1234";
    std::string license_plate_number2 = "ABC-DE 123";

    // act
    bool result1 = license_plates::validate_license_plate_number(license_plate_number1);
    bool result2 = license_plates::validate_license_plate_number(license_plate_number2);

    // assert
    ASSERT_TRUE(result1);
    ASSERT_TRUE(result2);
}

TEST(StringsAndRegex_LicensePlates, validate_license_plate_number_test_Invalid)
{
    // arrange
    std::vector<std::string> license_plate_numbers;
    license_plate_numbers.push_back("ABC-De 1234");
    license_plate_numbers.push_back("ABC-De 123");
    license_plate_numbers.push_back("ABC-DE 12");
    license_plate_numbers.push_back("ABC-DE 12345");

    // act/assert
    for (std::string license_plate_number : license_plate_numbers)
    {
        bool result = license_plates::validate_license_plate_number(license_plate_number);
        ASSERT_FALSE(result);
    }
}