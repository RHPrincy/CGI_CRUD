#include "Delete.h"
#include <sstream>

void Delete::accueil()
{

    ifstream file("/var/www/html/CGI/data.csv");

    if (file.is_open()) 
    {
        string line;
        cout << "<h1>Liste des Utilisateurs</h1>\n";
        cout << "<table border='1'>\n";
        cout << "<tr><th>Username</th><th>Email</th><th>Action</th></tr>";

        while (getline(file, line)) 
        {
            stringstream ss(line);
            string username, email, password, address, birthdate;
            // Lire le username jusqu'au premier ';'
            getline(ss, username, ';');
            // Lire le email jusqu'au second ';'
            getline(ss, email, ';');
            // Lire le password jusqu'au toisième ';'
            getline(ss, password, ';');
            getline(ss, address, ';');
            getline(ss, birthdate, ';');

            
            // Afficher les résultats dans un tableau HTML
            cout << "<tr>\n";
            cout << "<td>" << username << "</td>\n";
            cout << "<td>" << email << "</td>\n";
            cout << "<td>";

            cout << "<form method='POST' action='#'>\n";
            cout << "<input type='hidden' name='username' value='" << username << "'>";
            cout << "<button>Modify</button>";
            cout << "</form>";

            cout << "<form method='POST' action='/cgi-bin/detail_user.cgi'>\n";
            cout << "<input type='hidden' name='username' value='" << username << "'>";
            cout << "<button type='submit'>Details</button>";
            cout << "</form>";

            cout << "<form method='POST' action='/cgi-bin/delete_user.cgi'>\n";
            cout << "<input type='hidden' name='username' value='" << username << "'>";
            cout << "<button type='submit'>Delete</button>";
            cout << "</form>";

            cout << "</td>\n";
            cout << "</tr>\n";
        }
        cout << "</table>\n";
        cout << "<p><a href='/index.html'>Se deconnecter</a></p>\n";
        
        file.close();
    } 
    else 
    {
        cout << "<h1>Erreur</h1>";
        cout << "<p>Erreur: Impossible d'ouvrir le fichier pour lecture.</p>";
    }
}