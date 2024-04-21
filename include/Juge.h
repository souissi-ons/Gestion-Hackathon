#ifndef JUGE_H
#define JUGE_H

#include <string>;
#include <vector>;
#include "Personne.h";
#include "Specialisation.h";

using namespace std;

class Juge : public Personne
{
private:
    string expertise;
    vector<Specialisation*> specialisations;
public:
    Juge();
    Juge(int, string, string, string);
    Juge(const Juge&);
    ~Juge();
    string getExpertise();
    void setExpertise(string);
    vector<Specialisation*> getSpecialisations();
    void setSpecialisations(vector<Specialisation*>);
    void ajouterSpecialisation(Specialisation*);
    void afficherSpecialisations();
    Specialisation* rechercherSpecialisationParNom(string);
    void supprimerSpecialisationParNom(string);
    friend ostream& operator << (ostream&, Juge&);
    friend istream& operator >> (istream&, Juge&);
    Juge& operator=(const Juge&);
    void afficherDetails();
};

#endif
