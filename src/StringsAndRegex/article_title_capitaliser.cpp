#include <string>

/***
 * @brief Ch3 p25
*/
namespace article_title_capitaliser
{
    /**
     * @brief Capitalises the first letter of each word in the given article title.
     * 
     * @param title article title
     * @return capitalised article title
    */
    std::string capitalise(const std::string& title)
    {
        std::string result;
        int current_index = 0;
        for (auto c : title)
        {
            if (current_index==0)
            {
                result += std::toupper(c);
            }
            else
            {
                if (std::isspace(title[current_index-1]))
                {
                    result += std::toupper(c);
                }
                else
                {
                    result += c;
                }
            }

            current_index++;
        }

        return result;
    }
}