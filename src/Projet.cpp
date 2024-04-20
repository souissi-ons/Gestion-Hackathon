#include <string>;
#include <iostream>;
#include "Projet.h";
#include <limits>
#include "Evaluation.h";
using namespace std;

int Projet::nombreProjets = 0;

Projet::Projet() {
    Projet::nombreProjets++;
};

Projet::Projet(string titre, string description)
{
    Projet::nombreProjets;
    this->titre = titre;
    this->description = description;
};

Projet::~Projet() {
    delete this->equipe;
    delete this->evaluation;
};

Projet::Projet(const Projet& p)
{
    Projet::nombreProjets;
    this->titre = p.titre;
    this->description = p.description;
    this->evaluation = p.evaluation;
    this->equipe = p.equipe;
};

string Projet::getTitre()
{
    return this->titre;
};

void Projet::setTitre(string titre)
{
    this->titre = titre;
};

string Projet::getDescription()
{
    return this->description;
};

void Projet::setDescription(string description)
{
    this->description = description;
};

void Projet::setEvaluation(Evaluation* evaluation)
{
    this->evaluation = evaluation;
};

Evaluation* Projet::getEvaluation()
{
    return this->evaluation;
};

void Projet::setEquipe(Equipe* equipe)
{
    this->equipe = equipe;
};

Equipe* Projet::getEquipe()
{
    return this->equipe;
};

int Projet::getNombreProjets()
{
    return Projet::nombreProjets;
};

void Projet::setNombreProjets(int nb)
{
    Projet::nombreProjets = nb;
};

void Projet::afficherDetails(){
    cout << "Titre: " << this->titre << endl;
    cout << "Description : " << this->description << endl;
    cout<< "Evaluation : " << this->evaluation;
    cout << "Equipe : " <<  this->equipe;
};

