#include <iostream>
#include <string>
#include <regex>
#include <vector>

namespace LicensePlates
{
    namespace // anonymous namespace
    {
        const std::regex LICENSE_PLATE_PATTERN("([A-Z]{3}-[A-Z]{2} \\d{3,4})");
        const std::regex LICENSE_PLATE_PATTERN_ZERO_WIDTH("^([A-Z]{3}-[A-Z]{2} \\d{3,4})$");
    }

    bool validate_license_plate_number(std::string license_plate_number)
    {
        return std::regex_match(license_plate_number, LICENSE_PLATE_PATTERN_ZERO_WIDTH);
    }

    std::vector<std::string> get_license_plate_numbers(const std::string text)
    {
        std::vector<std::string> license_plate_numbers;
        for (auto i = std::sregex_iterator(text.begin(), text.end(), LICENSE_PLATE_PATTERN); i != std::sregex_iterator(); i++)
        {
            license_plate_numbers.push_back(i->str());
        }

        return license_plate_numbers;
    }
}