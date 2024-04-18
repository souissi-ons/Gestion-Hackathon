#include <string>
#include <iostream>
#include "Equipe.h"
#include "Gagnant.h"
#include "ProjetEmbarque.h"
#include "ProjetWeb.h"
#include <limits>

using namespace std;


Gagnant::Gagnant() {};

Gagnant::Gagnant(int rang, string recompense, float score)
{
    this->rang = rang;
    this->recompense = recompense;
    this->score = score;
};

Gagnant::Gagnant(const Gagnant& g)
{
    this->rang = g.rang;
    this->recompense = g.recompense;
    this->score = g.score;
    this->projet = g.projet;
};

int Gagnant::getRang()
{
    return this->rang;
};

void Gagnant::setRang(int rang)
{
    this->rang = rang;
};

void Gagnant::setProjet(Projet* projet)
{
    this->projet = projet;
};

Projet* Gagnant::getProjet()
{
    return this->projet;
};

string Gagnant::getRecompense()
{
    return this->recompense;
};

void Gagnant::setRecompense(string recompense)
{
    this->recompense = recompense;
};

float Gagnant::getScore()
{
    return this->score;
};

void Gagnant::setScore(float description)
{
    this->score = score;
};

ostream& operator<<(ostream& out, Gagnant& g)
{
    out << "Rang du gagnant: " << g.getRang() << ", Recompense du gagnant: " << g.getRecompense() << ", Score du gagnant: " << g.getScore() <<endl;
    out << "Projet du gagnant: " << endl ;

    // Vérifier le type du projet
    Projet* projet = g.getProjet();
    if (typeid(*projet) == typeid(ProjetWeb))
    {
        out << *dynamic_cast<ProjetWeb*>(projet);
    }
    else if (typeid(*projet) == typeid(ProjetEmbarque))
    {
        out << *dynamic_cast<ProjetEmbarque*>(projet);
    }

    return out;
}


// Operator >> for Gagnant
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
        in >> projetWeb; // Utilisation de l'opérateur >> de ProjetWeb pour saisir les détails
        g.projet = &projetWeb;
    }
    else if (choix == 2)
    {
        ProjetEmbarque projetEmbarque;
        in >> projetEmbarque; // Utilisation de l'opérateur >> de ProjetEmbarque pour saisir les détails
        g.projet = &projetEmbarque;
    };
    g.score = g.projet->getEvaluation()->calculerMoyenne();
    return in;
};

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


