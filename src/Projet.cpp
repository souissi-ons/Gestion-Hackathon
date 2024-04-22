#include <string>;
#include <iostream>;
#include "Projet.h";
#include <limits>
#include "Evaluation.h";

using namespace std;

// Initialisation du nombre de projets
int Projet::nombreProjets = 0;

// Constructeurs

// Constructeur par d�faut
Projet::Projet()
{};

// Constructeur avec param�tres
Projet::Projet(string titre, string description)
{
    this->titre = titre;
    this->description = description;
};

// Constructeur par recopie
Projet::Projet(const Projet& p)
{
    this->titre = p.titre;
    this->description = p.description;
    this->evaluation = p.evaluation;
    this->equipe = p.equipe;
};

// Desctructeur
Projet::~Projet()
{};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le titre
string Projet::getTitre()
{
    return this->titre;
};

// M�thode pour modifier le titre
void Projet::setTitre(string titre)
{
    this->titre = titre;
};

// M�thode pour obtenir la description
string Projet::getDescription()
{
    return this->description;
};

// M�thode pour modifier la description
void Projet::setDescription(string description)
{
    this->description = description;
};

// M�thode pour modifier l'�valuation
void Projet::setEvaluation(Evaluation evaluation)
{
    this->evaluation = evaluation;
};

// M�thode pour obtenir l'�valuation
Evaluation Projet::getEvaluation()
{
    return this->evaluation;
};

// M�thode pour modifier l'�quipe
void Projet::setEquipe(Equipe equipe)
{
    this->equipe = equipe;
};

// M�thode pour obtenir l'�quipe
Equipe Projet::getEquipe()
{
    return this->equipe;
};

// M�thode pour obtenir le nombre de projets
int Projet::getNombreProjets()
{
    return Projet::nombreProjets;
};

// M�thode pour modifier le nombre de projets
void Projet::setNombreProjets(int nb)
{
    Projet::nombreProjets = nb;
};

// M�thode pour afficher les details d'un projet
void Projet::afficherDetails()
{
    cout << "Titre: " << this->titre << endl;
    cout << "Description : " << this->description << endl;
    cout<< "Evaluation : " << this->evaluation;
    cout << "Equipe : " <<  this->equipe;
};

