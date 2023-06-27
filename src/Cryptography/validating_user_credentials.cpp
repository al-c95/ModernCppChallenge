#include <iostream>
#include <map>
#include <unordered_map>
#include "picosha2.h"

/**
 * @brief Ch11 p91
 * 
 */
namespace login_system
{
    namespace
    {
        std::map<std::string, std::string> users = {
                                                        {"John Smith", "2bb80d537b1da3e38bd30361aa855686bde0eacd7162fef6a25fe97bf527a25b"},
                                                        {"Jane Doe", "92ae1b419aa7e7aaecfc506833878608f58f243c42f9adaa27372016e2fe3dba"}
                                                    };
    }

    bool login(const std::string user_name, const std::string password)
    {
        // check if this username exists
        if (users.count(user_name) == 0)
        {
            return false;
        }
        else
        {
             // this username exists
             // authenticate
             std::string password_hash = picosha2::hash256_hex_string(password);
             if (users[user_name] == password_hash)
             {
                 return true;
             }
             else
             {
                 return false;
             }
        }
    }//login
}