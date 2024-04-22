#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>;
#include <list>;

using namespace std;

class Personne
{
protected:
    int nci;
    string nom;
    string email;
    list<string> numerosTelephone;
    list<string> adresses;
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
    list<string> getNumerosTelephone();
    void setNumerosTelephone(list<string>);
    list<string> getAdresses();
    void setAdresses(list<string>);
    void ajouterNumeroTelephone(string);
    void ajouterAdresse(string);
    virtual void afficherDetails()=0;
};

#endif
