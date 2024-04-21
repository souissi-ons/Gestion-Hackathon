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
    Specialisation(string, string);
    ~Specialisation();
    string getNom();
    void setNom(string);
    string getDescription();
    void setDescription(string);
    friend ostream& operator<<(ostream&, Specialisation&);
    friend istream& operator>>(istream&, Specialisation&);
    friend ostream& operator<<(ostream&, Specialisation&);
    friend istream& operator>>(istream&, Specialisation&);
};

#endif
