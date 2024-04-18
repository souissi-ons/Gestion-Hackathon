
#include <string>;
#include <iostream>;
#include "Technologie.h"
#include <limits>
using namespace std;

Technologie::Technologie() {};

Technologie::Technologie(string nom)
{
    this->nom = nom;
};

string Technologie::getNom()
{
    return this->nom;
};

void Technologie::setNom(string)
{
    this->nom = nom;
};

ostream& operator<<(ostream& out, Technologie& tech) {
    out << "Nom de la technologie: " << tech.nom << endl;
    return out;
}

istream& operator>>(istream& in, Technologie& tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech.nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, Technologie* tech) {
    out << "Nom de la technologie: " << tech->nom << endl;
    return out;
}

istream& operator>>(istream& in, Technologie* tech) {
    cout << "Donner le nom de la technologie: ";
    getline(in, tech->nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}
