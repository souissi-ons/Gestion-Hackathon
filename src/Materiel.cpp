#include <string>;
#include <iostream>;
#include "Materiel.h"
#include <limits>
using namespace std;

// Constructeurs

// Constructeur par défaut
Materiel::Materiel() {};

// Constructeur avec paramètres
Materiel::Materiel(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nom
string Materiel::getNom()
{
    return this->nom;
};

// Méthode pour modifier le nom
void Materiel::setNom(string)
{
    this->nom = nom;
};

// Méthode pour obtenir la description
string Materiel::getDescription()
{
    return this->description;
};

// Méthode pour modifier la description
void Materiel::setDescription(string)
{
    this->description = description;
};

// Surcharge des opérateurs pour l'entrée/sortie
// Surcharge de l'opérateur << pour afficher les informations du materiel
ostream& operator<<(ostream& out, Materiel& mat) {
    out << "Nom du materiel: " << mat.nom << ", Description du materiel: " << mat.description << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du materiel
istream& operator>>(istream& in, Materiel& mat) {
    cout << "Entrez le nom du matériel : ";
    getline(in, mat.nom);
    in.ignore();
    cout << "Entrez la description du matériel : ";
    getline(in, mat.description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations du materiel*
ostream& operator<<(ostream& out, Materiel* mat) {
    out << "Nom du materiel: " << mat->nom << ", Description du materiel: " << mat->description << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du materiel*
istream& operator>>(istream& in, Materiel* mat) {
    cout << "Entrez le nom du matériel : ";
    getline(in, mat->nom);
    in.ignore();
    cout << "Entrez la description du matériel : ";
    getline(in, mat->description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

