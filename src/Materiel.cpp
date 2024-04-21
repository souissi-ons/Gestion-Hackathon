#include <string>;
#include <iostream>;
#include "Materiel.h"
#include <limits>
using namespace std;

// Constructeurs

// Constructeur par d�faut
Materiel::Materiel() {};

// Constructeur avec param�tres
Materiel::Materiel(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nom
string Materiel::getNom()
{
    return this->nom;
};

// M�thode pour modifier le nom
void Materiel::setNom(string)
{
    this->nom = nom;
};

// M�thode pour obtenir la description
string Materiel::getDescription()
{
    return this->description;
};

// M�thode pour modifier la description
void Materiel::setDescription(string)
{
    this->description = description;
};

// Surcharge des op�rateurs pour l'entr�e/sortie
// Surcharge de l'op�rateur << pour afficher les informations du materiel
ostream& operator<<(ostream& out, Materiel& mat) {
    out << "Nom du materiel: " << mat.nom << ", Description du materiel: " << mat.description << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du materiel
istream& operator>>(istream& in, Materiel& mat) {
    cout << "Entrez le nom du mat�riel : ";
    getline(in, mat.nom);
    in.ignore();
    cout << "Entrez la description du mat�riel : ";
    getline(in, mat.description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations du materiel*
ostream& operator<<(ostream& out, Materiel* mat) {
    out << "Nom du materiel: " << mat->nom << ", Description du materiel: " << mat->description << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du materiel*
istream& operator>>(istream& in, Materiel* mat) {
    cout << "Entrez le nom du mat�riel : ";
    getline(in, mat->nom);
    in.ignore();
    cout << "Entrez la description du mat�riel : ";
    getline(in, mat->description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

