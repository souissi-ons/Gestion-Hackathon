#include <string>;
#include <iostream>;
#include "Materiel.h"
#include <limits>
using namespace std;

Materiel::Materiel() {};

Materiel::Materiel(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

string Materiel::getNom()
{
    return this->nom;
};

void Materiel::setNom(string)
{
    this->nom = nom;
};

string Materiel::getDescription()
{
    return this->description;
};

void Materiel::setDescription(string)
{
    this->description = description;
};

ostream& operator<<(ostream& out, Materiel& mat) {
    out << "Nom du materiel: " << mat.nom << ", Description du materiel: " << mat.description << endl;
    return out;
};

istream& operator>>(istream& in, Materiel& mat) {
    cout << "Entrez le nom du matériel : ";
    getline(in, mat.nom);
    in.ignore();
    cout << "Entrez la description du matériel : ";
    getline(in, mat.description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

ostream& operator<<(ostream& out, Materiel* mat) {
    out << "Nom du materiel: " << mat->nom << ", Description du materiel: " << mat->description << endl;
    return out;
};

istream& operator>>(istream& in, Materiel* mat) {
    cout << "Entrez le nom du matériel : ";
    getline(in, mat->nom);
    in.ignore();
    cout << "Entrez la description du matériel : ";
    getline(in, mat->description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

