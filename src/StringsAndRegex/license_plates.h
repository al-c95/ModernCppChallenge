#include <string>
#include <vector>

namespace license_plates
{
    bool validate_license_plate_number(std::string license_plate_number);
    std::vector<std::string> get_license_plate_numbers(const std::string text);
}