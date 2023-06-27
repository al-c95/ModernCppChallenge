#include <iostream>
#include <string>
#include <cctype>

/**
 * @brief ch11 p88
 * 
 */
namespace caesar_cipher
{
    std::string encrypt(std::string text, const int right_shift)
    {
        std::string result;

        for (const auto c : text)
        {
            // only consider uppercase letters
            // anything else gets left alone
            if (std::isalpha(c) && std::isupper(c))
            {
                int char_number = c;
                int shifted_char_number = char_number + right_shift;
                if (shifted_char_number > 90)
                {
                    shifted_char_number = 64 + right_shift;
                }
                result += (char)shifted_char_number;
            }
            else
            {
                result += c;
            }
        }

        return result;
    }
}