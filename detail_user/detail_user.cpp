#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void accueil()
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
            string usernameData, emailData, passwordData, addressData, birthdateData;
            // Lire le username jusqu'au premier ';'
            getline(ss, usernameData, ';');
            // Lire le email jusqu'au second ';'
            getline(ss, emailData, ';');
            // Lire le password jusqu'au toisième ';'
            getline(ss, passwordData, ';');
            getline(ss, addressData, ';');
            getline(ss, birthdateData, ';');
            
            // Afficher les résultats dans un tableau HTML
            cout << "<tr>\n";
            cout << "<td>" << usernameData << "</td>\n";
            cout << "<td>" << emailData << "</td>\n";
            cout << "<td>";

            cout << "<form method='POST' action='/cgi-bin/modify_user.cgi'>\n";
            cout << "<input type='hidden' name='username' value='" << usernameData << "'>";
            cout << "<button>Modify</button>";
            cout << "</form>";

            cout << "<form method='POST' action='/cgi-bin/detail_user.cgi'>\n";
            cout << "<input type='hidden' name='username' value='" << usernameData << "'>";
            cout << "<button type='submit'>Details</button>";
            cout << "</form>";

            cout << "<form method='POST' action='/cgi-bin/delete_user.cgi'>\n";
            cout << "<input type='hidden' name='username' value='" << usernameData << "'>";
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

int main()
{
    cout << "Content-type: text/html\n\n";

    // Lire les données POST
    string query_string;
    getline(cin, query_string);

    // Utiliser stringstream pour extraire le username
    stringstream ss(query_string);

    string key_value;

    string username_to_search;

    while (getline(ss, key_value, '&')) 
    {
        stringstream key_value_stream(key_value);
        string key, value;

        if (getline(key_value_stream, key, '=') && getline(key_value_stream, value)) 
        {
            if (key == "username") 
            {
                // Extraire le username à rechercher
                username_to_search = value; 
                break;
            }
        }
    }

    cout << "<h1>Informations de l'utilisateur: " << username_to_search << "</h1>";

    // Lire le fichier et afficher les informations dans un tableau
    ifstream file("/var/www/html/CGI/data.csv");
    string line;
    bool found = false;

    if (file.is_open())
    {
        while (getline(file, line)) 
        {
            stringstream ss(line);
            string username, email, password, address, birthdate;

            getline(ss, username, ';'); // Lire le username
            getline(ss, email, ';'); // Lire l'email
            getline(ss, password, ';'); // Lire le password
            getline(ss, address, ';'); // Lire l'adresse
            getline(ss, birthdate, ';');//Lire la date de naissance

            if (username == username_to_search) 
            {
                found = true;
                // Afficher les informations de l'utilisateur dans une ligne du tableau
                cout << "<div>\n";
                cout << "<div>Nom d'utilisateur : " << username << "</div>\n";
                cout << "<div>Email : " << email << "</div>\n";
                cout << "<div>Mot de passe : " << password << "</div>\n";
                cout << "<div>Addresse : " << address << "</div>\n";
                cout << "<div>Date de naissance : " << birthdate << "</div>\n";
                cout << "</div>\n";
                break; 
            }
        }
        file.close();
        accueil();

        if (!found) 
        {
            cout << "<tr><td colspan='5'>Aucun utilisateur trouv&eacute avec le username: " << username_to_search << "</td></tr>\n";
        }

        cout << "</table>\n";
    }
    else 
    {
        cout << "<h1>Erreur</h1>";
        cout << "<p>Erreur: Impossible d'ouvrir le fichier pour lecture.</p>";
        return 1;
    }

    return 0;
}
