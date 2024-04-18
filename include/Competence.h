#ifndef COMPETENCE_H
#define COMPETENCE_H

#include <string>;
using namespace std;

class Competence{
private:
    string nom;
    string description;
public:
    Competence();
    Competence(string, string);
    string getNom();
    void setNom(string);
    string getDescription();
    void setDescription(string);
    void afficher();
    friend ostream& operator << (ostream&, Competence&);
    friend istream& operator >> (istream&, Competence&);
    friend ostream& operator << (ostream&, Competence*);
    friend istream& operator >> (istream&, Competence*);
};

#endif
