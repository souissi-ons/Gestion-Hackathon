#include "Specialisation.h"
#include <iostream>
#include <limits>


using namespace std;

Specialisation::Specialisation() {};

Specialisation::Specialisation(string nom, string description){
    this->nom = nom;
    this->description = description;
};

Specialisation::~Specialisation() {};

string Specialisation::getNom() {
    return this->nom;
};

void Specialisation::setNom(string nom) {
    this->nom = nom;
};

string Specialisation::getDescription() {
    return this->description;
};

void Specialisation::setDescription(string description) {
    this->description = description;
};

ostream& operator<<(ostream& out, Specialisation& specialisation) {
    out << "Nom: " << specialisation.nom << ", Description: " << specialisation.description;
    return out;
}

istream& operator>>(istream& in, Specialisation& specialisation) {
    cout << "Entrez le nom de la spécialisation : ";
    getline(in, specialisation.nom);
    cout << "Entrez la description de la spécialisation : ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, Specialisation* specialisation) {
    out << "Nom: " << specialisation->getNom() << ", Description: " << specialisation->getDescription();
    return out;
}

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
