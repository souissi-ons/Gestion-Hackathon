#include <string>
#include <iostream>
#include "Equipe.h"
#include "Gagnant.h"
#include "ProjetEmbarque.h"
#include "ProjetWeb.h"
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Gagnant::Gagnant() {};

// Constructeur avec paramètres
Gagnant::Gagnant(int rang, string recompense, float score)
{
    this->rang = rang;
    this->recompense = recompense;
    this->score = score;
};

// Constructeur par recopie
Gagnant::Gagnant(const Gagnant& g)
{
    this->rang = g.rang;
    this->recompense = g.recompense;
    this->score = g.score;
    this->projet = g.projet;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le rang
int Gagnant::getRang()
{
    return this->rang;
};

// Méthode pour modifier le rang
void Gagnant::setRang(int rang)
{
    this->rang = rang;
};

// Méthode pour modifier le projet
void Gagnant::setProjet(Projet* projet)
{
    this->projet = projet;
};

// Méthode pour obtenir le projet
Projet* Gagnant::getProjet()
{
    return this->projet;
};

// Méthode pour obtenir la récompense
string Gagnant::getRecompense()
{
    return this->recompense;
};

// Méthode pour modifier la récompense
void Gagnant::setRecompense(string recompense)
{
    this->recompense = recompense;
};

// Méthode pour obtenir le score
float Gagnant::getScore()
{
    return this->score;
};

// Méthode pour modifier le score
void Gagnant::setScore(float description)
{
    this->score = score;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations d'un gaganant
ostream& operator<<(ostream& out, Gagnant& g)
{
    out << "Rang du gagnant: " << g.getRang() << ", Recompense du gagnant: " << g.getRecompense() << ", Score du gagnant: " << g.getScore() <<endl;
    out << "Projet du gagnant: " << endl ;

    // Vérifier le type du projet
    Projet* projet = g.getProjet();
    if (typeid(*projet) == typeid(ProjetWeb)) // Si le projet est de type ProjetWeb
    {
        out << *dynamic_cast<ProjetWeb*>(projet); // Utiliser dynamic_cast pour convertir le projet en ProjetWeb et l'afficher
    }
    else if (typeid(*projet) == typeid(ProjetEmbarque)) // Si le projet est de type ProjetEmbarque
    {
        out << *dynamic_cast<ProjetEmbarque*>(projet); // Utiliser dynamic_cast pour convertir le projet en ProjetEmbarque et l'afficher
    }

    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations d'un gagnant
istream& operator>>(istream& in, Gagnant& g)
{
    cout << "Entrez le rang du gagnant : ";
    in >> g.rang;
    cout << "Entrez la recompense du gagnant : ";
    getline(in, g.recompense);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    int choix;
    do
    {
        cout << "Choisissez le type de projet à ajouter (1 pour Projet Web, 2 pour Projet Embarque) : ";
        in >> choix;
    }
    while (choix !=1 && choix!=2);
    if (choix == 1)
    {
        ProjetWeb projetWeb;
        in >> projetWeb;
        g.projet = &projetWeb;
    }
    else if (choix == 2)
    {
        ProjetEmbarque projetEmbarque;
        in >> projetEmbarque;
        g.projet = &projetEmbarque;
    };
    g.score = g.projet->getEvaluation()->calculerMoyenne();
    return in;
};

// Méthode pour affecter un gagnant à un autre (opérateur d'affectation)
Gagnant& Gagnant::operator=(const Gagnant& autreGagnant)
{
    rang = autreGagnant.rang;
    recompense = autreGagnant.recompense;
    score = autreGagnant.score;

    if (typeid(*projet) == typeid(ProjetEmbarque))
    {
        *dynamic_cast<ProjetEmbarque*>(projet) = *(dynamic_cast<const ProjetEmbarque*>(autreGagnant.projet));
    }
    else if (typeid(*projet) == typeid(ProjetWeb))
    {
        *dynamic_cast<ProjetWeb*>(projet) = *(dynamic_cast<const ProjetWeb*>(autreGagnant.projet));
    }

    return *this;
};


