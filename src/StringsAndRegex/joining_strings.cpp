#include <string>
#include <vector>

/**
 * @brief Ch3 p26
*/
namespace joining_strings
{
    /**
     * @brief Joins a list of strings by concatenating the strings with a delimeter.
     * 
     * @param strings list of strings
     * @param delimiter delimiter to concatenate the strings with
     * @return concatenated string
    */
    std::string join_strings_with_delimiter(const std::vector<std::string>& strings, const std::string& delimiter)
    {
        std::string result;
        for (size_t index = 0; index < strings.size(); ++index)
        {
            result += strings[index];
            if (index != strings.size()-1)
            {
                result += delimiter;
            }
        }

        return result;
    }
}