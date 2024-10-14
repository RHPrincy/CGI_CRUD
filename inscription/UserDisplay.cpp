#include "User.h" 

// displayUserInfo
void User::displayUserInfo()  
{
    cout << "<h3>Inscription reussie</h3>\n";
    cout << "<p><strong>Nom d'utilisateur:</strong> " << username << "</p>\n";
    cout << "<p><strong>E-mail:</strong> " << email << "</p>\n";
    cout << "<p><strong>Mot de passe:</strong> " << password << "</p>\n";
    cout << "<p><strong>Adresse:</strong> " << address << "</p>\n";
    cout << "<p><strong>Date de naissance:</strong> " << birthdate << "</p>\n";
    cout << "<p><a href='/index.html'>Se connecter</a></p>\n";
}
