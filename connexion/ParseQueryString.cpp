#include "User.h"

// Définition de la méthode parseQueryString
void User::parseQueryString(string& query_string) 
{
    string key, value;
    stringstream ss(query_string);
    while (getline(ss, key, '=') && getline(ss, value, '&')) 
    {
        if (key == "username") 
        {
            username = value;
            int usernameLen = username.size();
            for (int i=0; i<usernameLen ; i++)
            {
                if (username[i]== '+')
                    username[i] = ' ';
            }
        }
        else if (key == "password") 
        {
            password = value;
        }
    }
}
