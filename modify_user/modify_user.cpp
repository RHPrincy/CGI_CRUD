#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


int main() 
{
    cout << "Content-type: text/html\n\n";

    // Lire les données POST
    string query_string;
    getline(cin, query_string);

    // Utiliser stringstream pour extraire le username
    stringstream ss(query_string);
    string key_value;
    string username_to_modify;

    while (getline(ss, key_value, '&')) 
    {
        stringstream key_value_stream(key_value);
        string key, value;

        if (getline(key_value_stream, key, '=') && getline(key_value_stream, value)) 
        {
            if (key == "username") 
            {
                // Extraire le username à modifier
                username_to_modify = value; 
                break;
            }
        }
    }

    cout <<"<body><html>\n ";
    cout << "<h1>Modification de l'information de l'utilisateur: " << username_to_modify << "</h1>";

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

            if (username == username_to_modify) 
            {
                found = true;

                cout << "<form action=\"/cgi-bin/inscription.cgi\" method=\"post\">\n";
                    cout << "<label for=\"username\">Nom d'utilisateur:</label>\n";
                    cout << "<input type=\"text\" id=\"username\" name=\"username\" value=\"" << username << "\" required><br><br>\n";
                    cout << "<label for=\"email\">Email:</label>\n";
                    cout << "<input type=\"email\" id=\"email\" name=\"email\" value=\"" << email << "\" required><br><br>\n";
                    cout << "<label for=\"password\">Mot de passe:</label>\n";
                    cout << "<input type=\"password\" id=\"password\" name=\"password\" value=\"" << password << "\" required><br><br>\n";
                    cout << "<label for=\"address\">Adresse:</label>\n";
                    cout << "<input type=\"text\" id=\"address\" name=\"address\" value=\"" << address << "\" required><br><br>\n";
                    cout << "<label for=\"birthdate\">Date de naissance:</label>\n";
                    cout << "<input type=\"date\" id=\"birthdate\" name=\"birthdate\" value=\"" << birthdate << "\" required><br><br>\n";
                    cout << "<input type=\"submit\" value=\"Enregistrer\">\n";
                cout << "</form>\n";
                break; 
            }
        }
        file.close();

        if (!found) 
        {
            cout << "Erreur\n";
        }
    }
    else 
    {
        cout << "<h1>Erreur</h1>";
        cout << "<p>Erreur: Impossible d'ouvrir le fichier pour lecture.</p>";
        return 1;
    }
    cout << "</html></body>";
}