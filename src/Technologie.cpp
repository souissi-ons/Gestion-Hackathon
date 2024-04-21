#include <string>;
#include <iostream>;
#include "Technologie.h"
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par d�faut
Technologie::Technologie() {};

// Constructeur avec param�tres
Technologie::Technologie(string nom)
{
    this->nom = nom;
};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nom
string Technologie::getNom()
{
    return this->nom;
};

// M�thode pour modifier le nom
void Technologie::setNom(string)
{
    this->nom = nom;
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations de technologie
ostream& operator<<(ostream& out, Technologie& tech) {
    out << "Nom de la technologie: " << tech.nom << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du technologie
istream& operator>>(istream& in, Technologie& tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech.nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations de technologie*
ostream& operator<<(ostream& out, Technologie* tech) {
    out << "Nom de la technologie: " << tech->nom << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du technologie*
istream& operator>>(istream& in, Technologie* tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech->nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}
