#include <string>;
#include <iostream>;
#include "Projet.h";
#include <limits>
#include "Evaluation.h";

using namespace std;

// Initialisation du nombre de projets
int Projet::nombreProjets = 0;

// Constructeurs

// Constructeur par défaut
Projet::Projet()
{};

// Constructeur avec paramètres
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

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le titre
string Projet::getTitre()
{
    return this->titre;
};

// Méthode pour modifier le titre
void Projet::setTitre(string titre)
{
    this->titre = titre;
};

// Méthode pour obtenir la description
string Projet::getDescription()
{
    return this->description;
};

// Méthode pour modifier la description
void Projet::setDescription(string description)
{
    this->description = description;
};

// Méthode pour modifier l'évaluation
void Projet::setEvaluation(Evaluation evaluation)
{
    this->evaluation = evaluation;
};

// Méthode pour obtenir l'évaluation
Evaluation Projet::getEvaluation()
{
    return this->evaluation;
};

// Méthode pour modifier l'équipe
void Projet::setEquipe(Equipe equipe)
{
    this->equipe = equipe;
};

// Méthode pour obtenir l'équipe
Equipe Projet::getEquipe()
{
    return this->equipe;
};

// Méthode pour obtenir le nombre de projets
int Projet::getNombreProjets()
{
    return Projet::nombreProjets;
};

// Méthode pour modifier le nombre de projets
void Projet::setNombreProjets(int nb)
{
    Projet::nombreProjets = nb;
};

// Méthode pour afficher les details d'un projet
void Projet::afficherDetails()
{
    cout << "Titre: " << this->titre << endl;
    cout << "Description : " << this->description << endl;
    cout<< "Evaluation : " << this->evaluation;
    cout << "Equipe : " <<  this->equipe;
};

