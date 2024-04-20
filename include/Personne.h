#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>;
using namespace std;

class Personne
{

protected:
    int nci;
    string nom;
    string email;
public:
    Personne();
    Personne(int, string, string);
    Personne(const Personne&);
    virtual ~Personne();
    int getNci();
    void setNci(int);
    string getNom();
    void setNom(string);
    string getEmail();
    void setEmail(string);
    virtual void afficherDetails()=0;

};

#endif
