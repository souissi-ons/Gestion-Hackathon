#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Organisateur.h";
#include <limits>
using namespace std;

Organisateur::Organisateur() {};

Organisateur::Organisateur(int nci, string nom, string email, string role): Personne(nci, nom, email)
{
    this->role = role;
};

Organisateur::~Organisateur(){}

string Organisateur::getRole()
{
    return this->role;
};

void Organisateur::setRole(string role)
{
    this->role = role;
};

ostream& operator<<(ostream& out, Organisateur& o) {
    out << "Cin de l'organisateur: " << o.nci <<  ", Nom de l'organisateur: " << o.nom << ", Email de l'organisateur: " << o.email << ", Role de l'organisateur: " << o.role << endl;
    return out;
};

istream& operator>>(istream& in, Organisateur& o) {
    cout << "Entrez le NCI de l'organisateur : ";
    in >> o.nci;
    cout << "Entrez le nom de l'organisateur : ";
    getline(in, o.nom);
    in.ignore();
    cout << "Entrez l'email de l'organisateur : ";
    getline(in, o.email);
    in.ignore();
    cout << "Entrez le role de l'organisateur :" ;
    getline(in, o.role);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

void Organisateur::afficherDetails() {
    cout << "Détails de l'organisateur :" << endl;
    Personne::afficherDetails();
    cout << "Role : " << this->role << endl;
};

