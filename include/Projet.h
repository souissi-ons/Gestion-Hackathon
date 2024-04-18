#ifndef PROJET_H
#define PROJET_H

#include <string>
#include "Projet.h"
#include "Evaluation.h"
#include "Equipe.h"
using namespace std;

class Projet
{
protected:
    string titre;
    string description;
    Evaluation *evaluation;
    Equipe *equipe;
public:
    Projet();
    Projet(string, string);
    Projet(const Projet&);
    virtual ~Projet();
    /*friend ostream& operator << (ostream&, Projet&);
    friend istream& operator >> (istream&, Projet&);*/
    string getTitre();
    void setTitre(string);
    string getDescription();
    void setDescription(string);
    void setEvaluation(Evaluation*);
    void setEquipe(Equipe*);
    Equipe* getEquipe();
    Evaluation* getEvaluation();
    //Projet& operator=(const Projet&);
    virtual void afficherDetails() = 0;
};

#endif
