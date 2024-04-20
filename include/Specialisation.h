#ifndef SPECIALISATION_H
#define SPECIALISATION_H

#include <string>;
using namespace std;

class Specialisation {
private:
    string nom;
    string description;

public:
    Specialisation();
    Specialisation(string nom, string description);
    ~Specialisation();

    string getNom();
    void setNom(string);

    string getDescription();
    void setDescription(string description);

    friend ostream& operator<<(ostream& os, Specialisation& specialisation);
    friend istream& operator>>(istream& is, Specialisation& specialisation);
    friend ostream& operator<<(ostream& os, Specialisation& specialisation);
    friend istream& operator>>(istream& is, Specialisation& specialisation);
};

#endif