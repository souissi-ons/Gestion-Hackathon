#include <string>;
#include <list>;
#include <iostream>;
#include "ProjetWeb.h";
#include "Projet.h";
#include "Technologie.h"
using namespace std;

ProjetWeb::ProjetWeb() {};

ProjetWeb::ProjetWeb(const ProjetWeb& pw)
{
    this->titre = pw.titre;
    this->description = pw.description;

    Technologie *t;
    for (list<Technologie*>::const_iterator it = pw.technologies.begin(); it != pw.technologies.end(); ++it)
    {
        this->technologies.push_back(*it);
    }
};

ProjetWeb::~ProjetWeb()
{
    for (list<Technologie*>::const_iterator it = this->technologies.begin(); it != this->technologies.end(); ++it)
    {
        delete (*it);
    }
};

list <Technologie *> ProjetWeb::getTechnologies()
{
    return this->technologies;
};

void ProjetWeb::setTechnologies(list <Technologie *> technologies)
{
    this->technologies = technologies;
};

void ProjetWeb::ajouterTechnologie(Technologie* technologie)
{
    this->technologies.push_back(technologie);
};

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

void ProjetWeb::supprimerTechnologie(string nomTechnologie){
    Technologie* technologie = rechercherTechnologie(nomTechnologie);
    if (technologie!= nullptr)
    {
        this->technologies.remove(technologie);
        delete technologie;
    }
};

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

