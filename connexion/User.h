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
        User();
        void parseQueryString(string& query_string);
        bool session();
        bool verification();
        void accueil();
        void errorPage(string message);
        ~User();
};

#endif