#include "User.h"
int main() 
{
    // Désactiver le cache pour empêcher la navigation avec "Précédent"
    std::cout << "Cache-Control: no-store, no-cache, must-revalidate\r\n";
    std::cout << "Pragma: no-cache\r\n";
    std::cout << "Expires: 0\r\n";
    
    cout << "Content-Type: text/html\n\n";

    // Lire les données du formulaire
    string query_string;
    getline(cin, query_string);

    // Création d'un objet User
    User user = User();

    user.parseQueryString(query_string);

    cout << "<html><body>\n";

    // Vérifier les informations de l'utilisateur
    bool valid = user.verification();

    //Session de l'utilisateur
    bool userSession = user.session();

    if (userSession)
    {
        if (valid) 
        {
            user.accueil();
        }

        else 
        {
            // Afficher une page d'erreur
            user.errorPage("Nom d'utilisateur ou mot de passe incorrect.");
        }
    }
    else 
    {
        // Afficher une page d'erreur
        user.errorPage("Veuillez vous connecter d'abord!");
    }

    
    
    cout << "</body></html>\n";
    return 0;
}
