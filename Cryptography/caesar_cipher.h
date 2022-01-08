#include <string>

/**
 * @brief ch11 p88
 * 
 */
namespace caesar_cipher
{
    std::string encrypt(std::string text, const int right_shift);
    std::string decrypt(std::string text, const int right_shift);
}