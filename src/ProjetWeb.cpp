#include <string>;
#include <list>;
#include <iostream>;
#include "ProjetWeb.h";
#include "Projet.h";
#include "Technologie.h"

using namespace std;

// Constructeurs

// Constructeur par défaut
ProjetWeb::ProjetWeb() {
    Projet::nombreProjets ++;
};

// Constructeur par recopie
ProjetWeb::ProjetWeb(const ProjetWeb& pw)
{
    Projet::nombreProjets ++;
    this->titre = pw.titre;
    this->description = pw.description;

    Technologie *t;
    for (list<Technologie*>::const_iterator it = pw.technologies.begin(); it != pw.technologies.end(); ++it)
    {
        this->technologies.push_back(*it);
    }
};

// Desctructeur
ProjetWeb::~ProjetWeb()
{
    for (list<Technologie*>::const_iterator it = this->technologies.begin(); it != this->technologies.end(); ++it)
    {
        delete (*it);
    }
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir la liste des technologies
list <Technologie *> ProjetWeb::getTechnologies()
{
    return this->technologies;
};

// Méthode pour modifier la liste des technologies
void ProjetWeb::setTechnologies(list <Technologie *> technologies)
{
    this->technologies = technologies;
};

void ProjetWeb::ajouterTechnologie(Technologie* technologie)
{
    this->technologies.push_back(technologie);
};

// Méthode pour rechercher une technologie dans la liste des technologies par son nom
Technologie* ProjetWeb::rechercherTechnologie(string nomTechnologie)
{
    for (list<Technologie*>::const_iterator it = this->technologies.begin(); it != this->technologies.end(); ++it)
    {
        if ((*it)->getNom() ==nomTechnologie)
        {
            return *it;
        }
    }
    return nullptr;
};

// Méthode pour supprimer une technologie dans la liste des technologies par son nom
void ProjetWeb::supprimerTechnologie(string nomTechnologie)
{
    Technologie* technologie = rechercherTechnologie(nomTechnologie);
    if (technologie!= nullptr)
    {
        this->technologies.remove(technologie);
        delete technologie;
    }
};
// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur >> pour saisir les informations d'un projet web
istream& operator>>(istream& in, ProjetWeb& p)
{
    cout << "Entrez le titre du projet : ";
    getline(in, p.titre);
    in.ignore();
    cout << "Entrez la description du projet : ";
    getline(in, p.description);
    in.ignore();
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    in >> p.evaluation;
    in >> p.equipe;
    int continuer;
    string nomTechnologie;
    do
    {
        Technologie* technologie = new Technologie();
        in >> *technologie;
        p.technologies.push_back(technologie);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre technologie sinon 0 : ";
            in >> continuer;
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    return in;
}

// Surcharge de l'opérateur << pour afficher les informations d'un projet web
ostream& operator<<(ostream& out, ProjetWeb& p)
{
    out << "Projet web : Titre du projet: " << p.titre << ", Description du projet: " << p.description << "\n" << "Evaluation du projet : " << p.evaluation << "Equipe du projet: " <<  p.equipe;
    out << "Technologies du projet: " << endl;
    int i=0;
    for (list<Technologie*>::const_iterator it = p.technologies.begin(); it != p.technologies.end(); ++it)
    {
        i++;
        out << "Technologie " << i<< ": " << *it;
    }
    return out;
};

// Méthode pour affecter un projet web à un autre (opérateur d'affectation)
ProjetWeb& ProjetWeb::operator=(const ProjetWeb& autreProjet)
{
    this->titre = autreProjet.titre;
    this->description = autreProjet.description;
    this->evaluation = autreProjet.evaluation;
    this->equipe = autreProjet.equipe;

    for (Technologie* tech : this->technologies)
    {
        delete tech;
    }
    technologies.clear();

    for (list<Technologie*>::const_iterator it = this->technologies.begin(); it != this->technologies.end(); ++it)

    {
        this->ajouterTechnologie(*it);
    }
    return *this;
};

// Surcharge des opérateurs de comparaison

// Surcharge de l'opérateur >
bool ProjetWeb::operator>(ProjetWeb& autreProjet)
{
    return this->technologies.size() > autreProjet.technologies.size();
};

// Surcharge de l'opérateur <
bool ProjetWeb::operator<(ProjetWeb& autreProjet)
{
    return this->technologies.size() < autreProjet.technologies.size();
};

// Surcharge de l'opérateur >=
bool ProjetWeb::operator>=(ProjetWeb& autreProjet)
{
    return this->technologies.size() >= autreProjet.technologies.size();
};

// Surcharge de l'opérateur <=
bool ProjetWeb::operator<=(ProjetWeb& autreProjet)
{
    return this->technologies.size() <= autreProjet.technologies.size();
};

// Méthode pour afficher les details d'un projet web
void ProjetWeb::afficherDetails()
{
    cout << "Détails du projet web" << endl;
    Projet::afficherDetails();
    int i=0;
    for (list<Technologie*>::const_iterator it = this->technologies.begin(); it != this->technologies.end(); ++it)
    {
        i++;
        cout << "Materiel " << i << ": " << *it ;
    }
};

