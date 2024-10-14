#include "User.h"

bool User::verification() 
{
    // Ouvrir le fichier
    ifstream file("/var/www/html/CGI/data.csv");
    
    // Vérifier si le fichier s'est bien ouvert
    if (file.is_open()) 
    {
        string line;
        
        // Lire le fichier ligne par ligne
        while (getline(file, line)) 
        {
            stringstream ss(line);
            string username, email, password, address, birthdate;

            // Lire les informations depuis la ligne
            getline(ss, username, ';');
            getline(ss, email, ';');
            getline(ss, password, ';');
            getline(ss, address, ';');
            getline(ss, birthdate, ';');
            
            // Vérifier si l'utilisateur et le mot de passe correspondent
            if (this->username == username && this->password == password) 
            {
                file.close();
                // Utilisateur valide
                return true;  
            }
        }
        
        // Fermer le fichier
        file.close();
    }
    
    // Retourner false si aucune correspondance n'est trouvée ou si le fichier n'est pas ouvert
    return false;
}
