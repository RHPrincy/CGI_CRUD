#include "Delete.h"
#include <vector>
#include <sstream>

void Delete::storeData()
{
    // Lire le fichier et stocker les lignes qui ne correspondent pas au username à supprimer
    ifstream file("/var/www/html/CGI/data.csv");

    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            stringstream ss(line);
            string username;
            getline(ss, username, ';');

            if (username != username_to_delete) 
            {
                // Conserver toutes les lignes sauf celle à supprimer
                lines.push_back(line); 
            }
        }
        file.close();
    } 
    else 
    {
        cout << "<h1>Erreur</h1>";
        cout << "<p>Erreur: Impossible d'ouvrir le fichier pour lecture.</p>";
    }
}