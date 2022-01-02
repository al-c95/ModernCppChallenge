#include <string>
#include <vector>

namespace LicensePlates
{
    bool validate_license_plate_number(std::string license_plate_number);
    std::vector<std::string> get_license_plate_numbers(const std::string text);
}