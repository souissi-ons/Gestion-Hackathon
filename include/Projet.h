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
    static int nombreProjets;
    string titre;
    string description;
    //Evaluation *evaluation;
    //Equipe *equipe;
    Evaluation evaluation;
    Equipe equipe;
public:
    Projet();
    Projet(string, string);
    Projet(const Projet&);
    virtual ~Projet();
    string getTitre();
    void setTitre(string);
    string getDescription();
    void setDescription(string);
    void setEvaluation(Evaluation);
    void setEquipe(Equipe);
    Equipe getEquipe();
    Evaluation getEvaluation();
    static int getNombreProjets();
    static void setNombreProjets(int);
    virtual void afficherDetails() = 0;
};

#endif
