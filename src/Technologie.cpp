#include <string>;
#include <iostream>;
#include "Technologie.h"
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Technologie::Technologie() {};

// Constructeur avec paramètres
Technologie::Technologie(string nom)
{
    this->nom = nom;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nom
string Technologie::getNom()
{
    return this->nom;
};

// Méthode pour modifier le nom
void Technologie::setNom(string)
{
    this->nom = nom;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations de technologie
ostream& operator<<(ostream& out, Technologie& tech) {
    out << "Nom de la technologie: " << tech.nom << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du technologie
istream& operator>>(istream& in, Technologie& tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech.nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations de technologie*
ostream& operator<<(ostream& out, Technologie* tech) {
    out << "Nom de la technologie: " << tech->nom << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du technologie*
istream& operator>>(istream& in, Technologie* tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech->nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}
