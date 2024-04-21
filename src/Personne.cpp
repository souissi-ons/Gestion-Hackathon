#include <string>;
#include <iostream>;
#include <list>
#include "Personne.h";
using namespace std;

// Constructeurs

// Constructeur par défaut
Personne::Personne() {};

// Constructeur avec paramètres
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

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nci
int Personne::getNci()
{
    return this->nci;
};

// Méthode pour modifier le nci
void Personne::setNci(int nci)
{
    this->nci = nci;
};

// Méthode pour obtenir le nom
string Personne::getNom()
{
    return this->nom;
};

// Méthode pour modifier le nom
void Personne::setNom(string nom)
{
    this->nom = nom;
};

// Méthode pour obtenir l'email
string Personne::getEmail()
{
    return this->email;
};

// Méthode pour modifier l'email
void Personne::setEmail(string email)
{
    this->email = email;
};

// Méthode pour obtenir la liste de numéros de téléphone
list<string> Personne::getNumerosTelephone()
{
    return this->numerosTelephone;
};

// Méthode pour modifier la liste de numéros de téléphone
void Personne::setNumerosTelephone(list<string> numerosTelephone)
{
    this->numerosTelephone = numerosTelephone;
};

// Méthode pour obtenir la liste d'adresses
list<string> Personne::getAdresses()
{
    return this->adresses;
};

// Méthode pour modifier la liste d'adresses
void Personne::setAdresses( list<string> adresses)
{
    this->adresses = adresses;
};

// Méthode pour ajouter un numéro de téléphone dans la liste des numéros de téléphone
void Personne::ajouterNumeroTelephone(string numero) {
    numerosTelephone.push_back(numero);
};

// Méthode pour ajouter une adresse dans la liste des adresses
void Personne::ajouterAdresse(string adresse){
    this->adresses.push_back(adresse);
}

// Méthode pour afficher les details d'une personne
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

