#include "Specialisation.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Specialisation::Specialisation() {};

// Constructeur avec paramètres
Specialisation::Specialisation(string nom, string description){
    this->nom = nom;
    this->description = description;
};

// Destructeur
Specialisation::~Specialisation() {};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nom
string Specialisation::getNom() {
    return this->nom;
};

// Méthode pour modifier le nom
void Specialisation::setNom(string nom) {
    this->nom = nom;
};

// Méthode pour obtenir la description
string Specialisation::getDescription() {
    return this->description;
};

// Méthode pour modifier la description
void Specialisation::setDescription(string description) {
    this->description = description;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations de specialisation
ostream& operator<<(ostream& out, Specialisation& specialisation) {
    out << "Nom: " << specialisation.nom << ", Description: " << specialisation.description;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du specialisation
istream& operator>>(istream& in, Specialisation& specialisation) {
    cout << "Entrez le nom de la spécialisation : ";
    getline(in, specialisation.nom);
    cout << "Entrez la description de la spécialisation : ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations de specialisation*
ostream& operator<<(ostream& out, Specialisation* specialisation) {
    out << "Nom: " << specialisation->getNom() << ", Description: " << specialisation->getDescription();
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations du specialisation*
istream& operator>>(istream& in, Specialisation* specialisation) {
    string nom;
    string description;
    cout << "Entrez le nom de la spécialisation : ";
    getline(in, nom);
    specialisation->setNom(nom);
    in.ignore();
    cout << "Entrez la description de la spécialisation : ";
    getline(in, description);
    specialisation->setDescription(description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}
