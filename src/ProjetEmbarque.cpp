#include <string>;
#include <list>;
#include <iostream>;
#include "ProjetEmbarque.h";
#include "Materiel.h";
#include "Projet.h"
using namespace std;

ProjetEmbarque::ProjetEmbarque() {};

ProjetEmbarque::ProjetEmbarque(const ProjetEmbarque& pe)
{
    this->titre = pe.titre;
    this->description = pe.description;

    Materiel *m;
    for (list<Materiel*>::const_iterator it = pe.materiels.begin(); it != pe.materiels.end(); ++it)
    {
        this->materiels.push_back(*it);
    }
};

ProjetEmbarque::~ProjetEmbarque()
{
    for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        delete *it;
    }
};

list <Materiel *> ProjetEmbarque::getMateriels()
{
    return this->materiels;
};

void ProjetEmbarque::setMateriels(list <Materiel *>materiels)
{
    this->materiels = materiels;
};

void ProjetEmbarque::ajouterMateriel(Materiel* materiel)
{
    this->materiels.push_back(materiel);
};

Materiel* ProjetEmbarque::rechercherMateriel(string nomMateriel)
{
    for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        if ((*it)->getNom() == nomMateriel)
        {
            return *it;
        }
    }
    return nullptr;
}


void ProjetEmbarque::supprimerMateriel(string nomMateriel)
{
    Materiel* materiel = rechercherMateriel(nomMateriel);
    if (materiel!= nullptr)
    {
         this->materiels.remove(materiel);
        delete materiel;
    }
};

ostream& operator<<(ostream& out, ProjetEmbarque& p)
{
    out << "Projet embarqué : Titre du projet: " << p.titre << ", Description du projet: " << p.description << "\n" << "Evaluation du projet : " << p.evaluation << "Equipe du projet: " <<  p.equipe;
    out << "Materiels du projet: " << endl;
    int i=0;
     for (list<Materiel*>::const_iterator it = p.materiels.begin(); it != p.materiels.end(); ++it)
    {
        i++;
        out << "Materiel " << i << ": " << *it ;
    }
    return out;
}

istream& operator>>(istream& in, ProjetEmbarque& p)
{
    cout << "Entrez le titre du projet : ";
    getline(in, p.titre);
    in.ignore();
    cout << "Entrez la description du projet : ";
    getline(in, p.description);
    in.ignore();in.ignore(numeric_limits<streamsize>::max(), '\n');
    in >> p.evaluation;
    in >> p.equipe;
    int continuer;
    do
    {
        Materiel* materiel = new Materiel();
        in >> *materiel;
        p.materiels.push_back(materiel);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre materiel sinon 0 : ";
            in >> continuer;
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    return in;
};

ProjetEmbarque& ProjetEmbarque::operator=(const ProjetEmbarque& autreProjet)
{
    this->titre = autreProjet.titre;
    this->description = autreProjet.description;
    this->evaluation = autreProjet.evaluation;
    this->equipe = autreProjet.equipe;

    for (Materiel* m : this->materiels)
    {
        delete m;
    }
    materiels.clear();

    for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        this->ajouterMateriel(*it);
    }
    return *this;
};

void ProjetEmbarque::afficherDetails()
{
    cout << "Détails du projet embarqué" << endl;
    Projet::afficherDetails();
    int i=0;
    for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        i++;
        cout << "Materiel " << i << ": " << *it ;
    }
};

