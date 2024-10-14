#include "User.h"

bool User::control()
{
    //Verifier le nom d'utilisateur
    int usernameLenght = username.size();
    
    if (usernameLenght<=1)
    {
        return false;
    }

    for (int i=0; i < usernameLenght; i++)
    {   
        //Si invalide
        if(!isalnum(username[i]))        
        {
        return false;
        } 
    }

    //Verification de l'email

    //Verification de l'adresse

    //Verification date de naissance 

    return true;
}