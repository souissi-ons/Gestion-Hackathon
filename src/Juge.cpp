#include <string>;
#include <iostream>;
#include "Juge.h";
#include <limits>
using namespace std;

Juge::Juge(){};

Juge::Juge(int nci, string nom, string email, string expertise): Personne(nci, nom, email){
    this->expertise = expertise;
};

Juge::~Juge(){};

string Juge::getExpertise(){
    return this->expertise;
};

void Juge::setExpertise(string expertise){
    this->expertise = expertise;
};

ostream& operator<<(ostream& out, Juge& j) {
    out << "Cin du membre jury: " << j.nci <<  ", Nom du membre jury: " << j.nom << ", Email du membre jury: " << j.email << ", Expertise du membre jury: " << j.expertise <<  endl;
    return out;
};

istream& operator>>(istream& in, Juge& j) {
     cout << "Entrez le NCI du membre jury : ";
    in >> j.nci;
    cout << "Entrez le nom du membre jury : ";
    getline(in, j.nom);
    in.ignore();
    cout << "Entrez l'email du membre jury : ";
    getline(in, j.email);
    in.ignore();
    cout << "Entrez l'expertise du membre jury :" ;
    getline(in, j.expertise) ;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

void Juge::afficherDetails() {
    cout << "Détails du juge :" << endl;
    Personne::afficherDetails();
    cout << "Expertise : " << this->expertise << endl;
}
