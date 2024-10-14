#include "User.h"

int main() 
{
    cout << "Content-Type: text/html\n\n";

    // Lire les données du formulaire
    string query_string;
    getline(cin, query_string);

    // Création d'un objet User
    User user = User();

    // Analyser la chaîne de requête pour extraire les données
    user.parseQueryString(query_string);

    bool usernameInUse = user.usernameInUse();

    bool ctrl =user.control();

    cout << "<html><body>\n";

    if (ctrl)
    {
        if (usernameInUse) 
        {
            user.errorPage("Nom d'utilisateur existe d&eacuteja");
            return 1;
        }

        else
        {
            //Ajouter l'utilisateur à la base de données
            user.insertUser();

            // Afficher les informations de l'utilisateur
            user.displayUserInfo();
        }

    }
    else 
    {
        user.errorPage("Entr&eacute;e invalide");
        return 1;
    }
    
    
    cout << "</body></html>\n";

    return 0;
}
