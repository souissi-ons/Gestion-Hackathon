#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Competence.h";
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Competence::Competence() {};

// Constructeur avec paramètres
Competence::Competence(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nom
string Competence::getNom()
{
    return this->nom;
};

// Méthode pour modifier le nom
void Competence::setNom(string nom)
{
    this->nom = nom;
};

// Méthode pour obtenir la description
string Competence::getDescription()
{
    return this->description;
};

// Méthode pour modifier la description
void Competence::setDescription(string description)
{
    this->description = description;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur >> pour saisir les informations de la competence
istream& operator>>(istream& in, Competence& c)
{
    cout << "Entrez le nom de la competence : ";
    getline(in >> ws, c.nom);
    cout << "Entrez la description de la competence : ";
    getline(in >> ws, c.description);
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations de la competence
ostream& operator << (ostream& out, Competence& c)
{
    out << "Nom de la competence: " << c.nom << ", Description de la competence: " << c.description << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations de la competence*
istream& operator >> (istream& in, Competence* c)
{
   cout << "Entrez le nom de la competence : ";
    getline(in >> ws, c->nom);
    cout << "Entrez la description de la competence : ";
    getline(in >> ws, c->description);
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations de la competence*
ostream& operator << (ostream& out, Competence* c)
{
    out << "Nom de la competence: " << c->nom << ", Description de la competence: " << c->description << endl;
    return out;
};


