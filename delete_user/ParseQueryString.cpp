#include "Delete.h"
#include <sstream>

void Delete::parseQueryString(string& query_string)
{
    // Utiliser stringstream pour extraire le username
    stringstream ss(query_string);
    string key_value;

    while (getline(ss, key_value, '&')) 
    {
        stringstream key_value_stream(key_value);
        string key, value;

        if (getline(key_value_stream, key, '=') && getline(key_value_stream, value)) 
        {
            if (key == "username") 
            {
                // Extraire le username à supprimer
                username_to_delete = value; 
                break;
            }
        }
    }
}