#ifndef MATERIEL_H
#define MATERIEL_H

#include <string>;
using namespace std;

class Materiel{
private:
    string nom;
    string description;
public:
    Materiel();
    Materiel(string, string);
    string getNom();
    void setNom(string);
    string getDescription();
    void setDescription(string);
    friend ostream& operator << (ostream&, Materiel&);
    friend istream& operator >> (istream&, Materiel&);
    friend ostream& operator << (ostream&, Materiel*);
    friend istream& operator >> (istream&, Materiel*);
};

#endif

