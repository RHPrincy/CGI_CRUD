#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class User 
{
    private:
        string username;
        string email;
        string password;
        string address;
        string birthdate;

    public:
        //Constructeur
        User();

        //Parse les données
        void parseQueryString(string& query_string);

        //Vérification des entrées
        bool control();

        //Verifie si le nom d'utilisateur est déja utilisé
        bool usernameInUse();

        //Page d'erreur
        void errorPage(string message);

        //Affichage de l'utilisateur
        void displayUserInfo();

        //Inserér l'utilisateur dans le base des données
        void insertUser();

        //Désctructeur
        ~User();
};

#endif
