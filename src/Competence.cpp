#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Competence.h";
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par d�faut
Competence::Competence() {};

// Constructeur avec param�tres
Competence::Competence(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nom
string Competence::getNom()
{
    return this->nom;
};

// M�thode pour modifier le nom
void Competence::setNom(string nom)
{
    this->nom = nom;
};

// M�thode pour obtenir la description
string Competence::getDescription()
{
    return this->description;
};

// M�thode pour modifier la description
void Competence::setDescription(string description)
{
    this->description = description;
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur >> pour saisir les informations de la competence
istream& operator>>(istream& in, Competence& c)
{
    cout << "Entrez le nom de la competence : ";
    getline(in >> ws, c.nom);
    cout << "Entrez la description de la competence : ";
    getline(in >> ws, c.description);
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations de la competence
ostream& operator << (ostream& out, Competence& c)
{
    out << "Nom de la competence: " << c.nom << ", Description de la competence: " << c.description << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations de la competence*
istream& operator >> (istream& in, Competence* c)
{
   cout << "Entrez le nom de la competence : ";
    getline(in >> ws, c->nom);
    cout << "Entrez la description de la competence : ";
    getline(in >> ws, c->description);
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations de la competence*
ostream& operator << (ostream& out, Competence* c)
{
    out << "Nom de la competence: " << c->nom << ", Description de la competence: " << c->description << endl;
    return out;
};


