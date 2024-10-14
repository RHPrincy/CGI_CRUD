#include "User.h"

void User::errorPage(string message)
{
    cout << "<h1>CONNEXION</h1>\n";
    cout << "<form action=\"/cgi-bin/connexion.cgi\" method=\"post\">\n";
    cout << "<label for=\"username\">Nom d'utilisateur:</label>\n";
    cout << "<input type=\"text\" id=\"username\" name=\"username\" value=\"" << username << "\" required><br><br>\n";
    cout << "<label for=\"password\">Mot de passe:</label>\n";
    cout << "<input type=\"password\" id=\"password\" name=\"password\" value=\"" << password << "\" required>\n";
    cout << "<p>" << message << "</p>\n";
    cout << "<input type=\"submit\" value=\"Envoyer\">\n";
    cout << "</form>\n";
    cout << "<p>Pas de compte ? <a href=\"/inscription.html\">Inscrivez-vous</a></p>";
}