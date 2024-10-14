#include "Delete.h"

void Delete::writeNewData()
{
    // Ouvrir en mode "truncate"
    ofstream file_out("/var/www/html/CGI/data.csv", ios::trunc); 
    if (file_out.is_open())
    {
        for (size_t i = 0; i < lines.size(); i++) 
        {
            // Réécrire chaque ligne conservée
            file_out << lines[i] << '\n';
        }
        file_out.close();
        cout << "<h3>Utilisateur "<< username_to_delete << " supprim&eacute; avec succes</h3>";
    }
    else
    {
        cout << "<h1>Erreur</h1>";
        cout << "<p>Erreur: Impossible d'ouvrir le fichier pour &eacute;criture.</p>";
    }
}