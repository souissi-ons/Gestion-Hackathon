#include <string>;
#include <iostream>;
#include "Personne.h";
using namespace std;

Personne::~Personne(){};

Personne::Personne(){};

Personne::Personne(int nci, string nom, string email){
    this->nci = nci;
    this->nom = nom;
    this->email = email;
};

Personne::Personne(const Personne& p){
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;
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

void Personne::afficherDetails()  {
    cout << "NCI : " << nci << endl;
    cout << "Nom : " << nom << endl;
    cout << "Email : " << email << endl;
};

