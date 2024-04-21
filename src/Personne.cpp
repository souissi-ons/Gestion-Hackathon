#include <string>;
#include <iostream>;
#include <list>
#include "Personne.h";
using namespace std;

// Constructeurs

// Constructeur par d�faut
Personne::Personne() {};

// Constructeur avec param�tres
Personne::Personne(int nci, string nom, string email)
{
    this->nci = nci;
    this->nom = nom;
    this->email = email;
};

// Constructeur par recopie
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

// Desctructeur
Personne::~Personne() {};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nci
int Personne::getNci()
{
    return this->nci;
};

// M�thode pour modifier le nci
void Personne::setNci(int nci)
{
    this->nci = nci;
};

// M�thode pour obtenir le nom
string Personne::getNom()
{
    return this->nom;
};

// M�thode pour modifier le nom
void Personne::setNom(string nom)
{
    this->nom = nom;
};

// M�thode pour obtenir l'email
string Personne::getEmail()
{
    return this->email;
};

// M�thode pour modifier l'email
void Personne::setEmail(string email)
{
    this->email = email;
};

// M�thode pour obtenir la liste de num�ros de t�l�phone
list<string> Personne::getNumerosTelephone()
{
    return this->numerosTelephone;
};

// M�thode pour modifier la liste de num�ros de t�l�phone
void Personne::setNumerosTelephone(list<string> numerosTelephone)
{
    this->numerosTelephone = numerosTelephone;
};

// M�thode pour obtenir la liste d'adresses
list<string> Personne::getAdresses()
{
    return this->adresses;
};

// M�thode pour modifier la liste d'adresses
void Personne::setAdresses( list<string> adresses)
{
    this->adresses = adresses;
};

// M�thode pour ajouter un num�ro de t�l�phone dans la liste des num�ros de t�l�phone
void Personne::ajouterNumeroTelephone(string numero) {
    numerosTelephone.push_back(numero);
};

// M�thode pour ajouter une adresse dans la liste des adresses
void Personne::ajouterAdresse(string adresse){
    this->adresses.push_back(adresse);
}

// M�thode pour afficher les details d'une personne
void Personne::afficherDetails()
{
    cout << "NCI : " << nci << endl;
    cout << "Nom : " << nom << endl;
    cout << "Email : " << email << endl;
    cout << "Num�ros de t�l�phone: "<< endl;
    int i=0;
    for (list<string>::const_iterator it = this->numerosTelephone.begin(); it != this->numerosTelephone.end(); ++it) {
        i++;
        cout << "Num�ro de t�l�phone "<< i << ": " << *it;
    }
    i =0;
    for (list<string>::const_iterator it = this->adresses.begin(); it != this->adresses.end(); ++it) {
        i++;
        cout << "Adresse "<< i << ": " << *it;
    }
};

