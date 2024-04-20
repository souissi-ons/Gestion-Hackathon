#include <string>;
#include <iostream>;
#include <list>
#include "Personne.h";
using namespace std;

Personne::~Personne() {};

Personne::Personne() {};

Personne::Personne(int nci, string nom, string email)
{
    this->nci = nci;
    this->nom = nom;
    this->email = email;
};

Personne::Personne(const Personne& p)
{
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;
     for (list<string>::const_iterator it = p.numerosTelephone.begin(); it != p.numerosTelephone.end(); ++it) {
        this->numerosTelephone.push_back(*it);
    }
    for (list<string>::const_iterator it = p.adresses.begin(); it != p.adresses.end(); ++it) {
        this->adresses.push_back(*it);
    }
};

int Personne::getNci()
{
    return this->nci;
};

void Personne::setNci(int nci)
{
    this->nci = nci;
};

string Personne::getNom()
{
    return this->nom;
};

void Personne::setNom(string nom)
{
    this->nom = nom;
};

string Personne::getEmail()
{
    return this->email;
};

void Personne::setEmail(string email)
{
    this->email = email;
};

list<string> Personne::getNumerosTelephone()
{
    return this->numerosTelephone;
};

void Personne::setNumerosTelephone(list<string> numerosTelephone)
{
    this->numerosTelephone = numerosTelephone;
};

list<string> Personne::getAdresses()
{
    return this->adresses;
};

void Personne::setAdresses( list<string> adresses)
{
    this->adresses = adresses;
};

void Personne::ajouterNumeroTelephone(string numero) {
    numerosTelephone.push_back(numero);
};

void Personne::ajouterAdresse(string adresse){
    this->adresses.push_back(adresse);
}

void Personne::afficherDetails()
{
    cout << "NCI : " << nci << endl;
    cout << "Nom : " << nom << endl;
    cout << "Email : " << email << endl;
    cout << "Numéros de téléphone: "<< endl;
    int i=0;
    for (list<string>::const_iterator it = this->numerosTelephone.begin(); it != this->numerosTelephone.end(); ++it) {
        i++;
        cout << "Numéro de téléphone "<< i << ": " << *it;
    }
    i =0;
    for (list<string>::const_iterator it = this->adresses.begin(); it != this->adresses.end(); ++it) {
        i++;
        cout << "Adresse "<< i << ": " << *it;
    }
};

