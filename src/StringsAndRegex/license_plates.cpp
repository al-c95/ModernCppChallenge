#include <iostream>
#include <string>
#include <regex>
#include <vector>

/**
 * @brief Ch3 p29
 * 
 */
namespace license_plates
{
    namespace // anonymous namespace
    {
        const std::regex LICENSE_PLATE_PATTERN("([A-Z]{3}-[A-Z]{2} \\d{3,4})");
        const std::regex LICENSE_PLATE_PATTERN_ZERO_WIDTH("^([A-Z]{3}-[A-Z]{2} \\d{3,4})$");
    }

    /**
     * @brief Checks if a string is a valid license plate number. Must be in the format LLL-LL DDDD or LLL-LL DDD, where L is an uppercase letter and D a digit 0-9.
     * 
     * @param license_plate_number given license plate number
     * @return true if license plate number is valid
     * @return false if license plate number is invalid
     */
    bool validate_license_plate_number(std::string license_plate_number)
    {
        return std::regex_match(license_plate_number, LICENSE_PLATE_PATTERN_ZERO_WIDTH);
    }

    /**
     * @brief Extracts all valid license plate numbers from a string.
     * 
     * @param text given string
     * @return std::vector<std::string> valid license plate numbers
     * /
     * 
     * /
     */
    std::vector<std::string> get_license_plate_numbers(const std::string text)
    {
        std::vector<std::string> license_plate_numbers;
        for (auto i = std::sregex_iterator(text.begin(), text.end(), LICENSE_PLATE_PATTERN); i != std::sregex_iterator(); i++)
        {
            license_plate_numbers.push_back(i->str());
        }

        return license_plate_numbers;
    }//get_license_plate_numbers
}