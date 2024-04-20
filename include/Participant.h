#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <map>;
#include "Personne.h";
#include "Competence.h";
using namespace std;


class Participant : public Personne
{
private:
    static int nombreParticipants;
    map<string, string> competences;
public:
    Participant();
    Participant(const Participant&);
    ~Participant();
    map<string, string> getCompetences();
    void setCompetences(const map<string, string>&);
    static int getNombreParticipants();
    static void setNombreParticipants(int);
    void ajouterCompetence(Competence&);
    int rechercherCompetence(const string&);
    void supprimerCompetence(const string&);
    friend ostream& operator<<(ostream&, Participant&);
    friend istream& operator>>(istream&, Participant&);
    Participant& operator=(Participant&);
    void afficherDetails();
    bool operator<(Participant& autreParticipant);
    bool operator>(Participant& autreParticipant);
    bool operator<=(Participant& autreParticipant);
    bool operator>=(Participant& autreParticipant);
};

#endif


