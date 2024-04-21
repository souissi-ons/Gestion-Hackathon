#include "Specialisation.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par d�faut
Specialisation::Specialisation() {};

// Constructeur avec param�tres
Specialisation::Specialisation(string nom, string description){
    this->nom = nom;
    this->description = description;
};

// Destructeur
Specialisation::~Specialisation() {};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nom
string Specialisation::getNom() {
    return this->nom;
};

// M�thode pour modifier le nom
void Specialisation::setNom(string nom) {
    this->nom = nom;
};

// M�thode pour obtenir la description
string Specialisation::getDescription() {
    return this->description;
};

// M�thode pour modifier la description
void Specialisation::setDescription(string description) {
    this->description = description;
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations de specialisation
ostream& operator<<(ostream& out, Specialisation& specialisation) {
    out << "Nom: " << specialisation.nom << ", Description: " << specialisation.description;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du specialisation
istream& operator>>(istream& in, Specialisation& specialisation) {
    cout << "Entrez le nom de la sp�cialisation : ";
    getline(in, specialisation.nom);
    cout << "Entrez la description de la sp�cialisation : ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations de specialisation*
ostream& operator<<(ostream& out, Specialisation* specialisation) {
    out << "Nom: " << specialisation->getNom() << ", Description: " << specialisation->getDescription();
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations du specialisation*
istream& operator>>(istream& in, Specialisation* specialisation) {
    string nom;
    string description;
    cout << "Entrez le nom de la sp�cialisation : ";
    getline(in, nom);
    specialisation->setNom(nom);
    in.ignore();
    cout << "Entrez la description de la sp�cialisation : ";
    getline(in, description);
    specialisation->setDescription(description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}
