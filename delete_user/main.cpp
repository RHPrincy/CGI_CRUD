#include "Delete.h"

int main() 
{
    cout << "Content-Type: text/html\n\n";

    // Lire les données du formulaire
    string query_string;

    getline(cin, query_string);

    // Création d'un objet User
    Delete user = Delete();

    user.parseQueryString(query_string);
    
    user.storeData();

    bool sessionFound = user.session();

    cout << "<html><body>\n";

    if (sessionFound)
    {
        user.writeNewData();
        user.accueil();
    }
    else 
    {
        cout << "Page introuvable \n" ;
        cout << "Veuillez vous connecter d'abord" ;
    }
    cout << "</body></html>\n";
    return 0;
}
