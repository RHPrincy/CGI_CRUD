#include "User.h"
#include <fstream>
#include <sstream>

bool User::usernameInUse()
{
    ifstream file("/var/www/html/CGI/data.csv");
    string line;
    string username;

    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            stringstream ss(line);
            getline(ss, username, ';');
            if (username == this->username) 
            {
                return true;
            }
        }
        file.close();
    } 
    
    else 
    {
        cerr << "Erreur: Impossible d'ouvrir le fichier pour lecture." << endl;
    }

    return false;
}