#include "User.h"

// Ajoute d'un utilisateur à la base de données
void User::insertUser()
{
    // Ouvre le fichier en mode append pour ajouter à la fin
    ofstream file("/var/www/html/CGI/data.csv", ios::app);
    
    if (file.is_open()) 
    {
        // Ajoute les nouvelles informations à la fin du fichier
        file << username << ";" << email << ";" << password << ";" << address << ";" << birthdate << endl;
        file.close();
    }

    else 
    {
        // Gestion des erreurs
        cerr << "Erreur d'ouverture du fichier." << endl;
    }
}