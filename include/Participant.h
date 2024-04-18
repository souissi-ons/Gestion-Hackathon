#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <vector>;
#include "Personne.h";
#include "Competence.h";
using namespace std;


class Participant : public Personne
{
private:
    vector <Competence *> competences;
public:
    Participant();
    Participant(const Participant&);
    ~Participant();
    vector <Competence *> getCompetences();
    void setCompetences(vector <Competence *>);
    void ajouterCompetence(const Competence&);
    int rechercherCompetence(string);
    void supprimerCompetence(string);
    friend ostream& operator<<(ostream&, Participant&);
    friend istream& operator>> (istream&, Participant&);
    Participant& operator = (const Participant&);
    void afficherDetails();

};

#endif


