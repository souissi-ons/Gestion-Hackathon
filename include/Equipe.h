#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>;
#include <vector>;
#include "Equipe.h";
#include "Participant.h";
#include "Date.h";
using namespace std;

class Equipe{
private:
    string nom;
    Date dateCreation;
    vector <Participant *> participants;
public:
    Equipe();
    Equipe(const Equipe&);
    ~Equipe();
    string getNom();
    void setNom(string);
    Date getDateCreation();
    void setDateCreation(Date);
    vector<Participant*> getParticipants();
    void setParticipants(vector<Participant*>);
    void ajouterParticipant(Participant*);
    int rechercherParticipant(int);
    void supprimerParticipant(int);
    friend ostream& operator << (ostream&, Equipe&);
    friend istream& operator >> (istream&, Equipe&);
    friend ostream& operator << (ostream&, Equipe*);
    friend istream& operator >> (istream&, Equipe*);
    Equipe& operator=(const Equipe&);

};

#endif
