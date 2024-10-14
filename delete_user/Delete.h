#ifndef DELETE_H
#define DELETE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Delete 
{
    private:
        string username_to_delete;

        // Vecteur pour stocker les lignes à conserver
        vector<string> lines; 
        string line;

    public:
        //Constructeur
        Delete();
        bool session();
        void parseQueryString(string& query_string);
        void storeData();
        void writeNewData();
        void accueil();
        //Destructeur
        ~Delete();
};

#endif
