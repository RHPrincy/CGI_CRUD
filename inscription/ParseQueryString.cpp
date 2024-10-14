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
                if (username[i]=='+')
                    username[i]=' ';
            }
            
        } 
        else if (key == "email") 
        {
            email = value;
            size_t pos = 0;
            while ((pos = email.find("%40", pos)) != string::npos)
            {
                email.replace(pos, 3, "@");
                pos += 1;
            }

        } 
        else if (key == "password") 
        {
            password = value;
        } 
        else if (key == "address") 
        {
            address = value;
            int addressLen = address.size();
            for (int i=0; i < addressLen ; i++)
            {
                if (address[i]=='+')
                    address[i]=' ';
            }
        }
        else if (key== "birthdate")
        {
            birthdate = value;
        }
    }
}
