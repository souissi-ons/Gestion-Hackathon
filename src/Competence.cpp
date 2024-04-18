#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Competence.h";
#include <limits>
using namespace std;

Competence::Competence() {};

Competence::Competence(string nom, string description)
{
    this->nom = nom;
    this->description = description;
};

string Competence::getNom()
{
    return this->nom;
};

void Competence::setNom(string nom)
{
    this->nom = nom;
};

string Competence::getDescription()
{
    return this->description;
};

void Competence::setDescription(string description)
{
    this->description = description;
};

istream& operator>>(istream& in, Competence& c)
{
    cout << "Entrez le nom de la competence : ";
    getline(in, c.nom);
    in.ignore();
    cout << "Entrez la description de la competence : ";
    getline(in, c.description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator << (ostream& out, Competence& c)
{
    out << "Nom de la competence: " << c.nom << ", Description de la competence: " << c.description << endl;
    return out;
};

istream& operator >> (istream& in, Competence* c)
{
   cout << "Entrez le nom de la competence : ";
    getline(in, c->nom);
    in.ignore();
    cout << "Entrez la description de la competence : ";
    getline(in, c->description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

ostream& operator << (ostream& out, Competence* c)
{
    out << "Nom de la competence: " << c->nom << ", Description de la competence: " << c->description << endl;
    return out;
};


