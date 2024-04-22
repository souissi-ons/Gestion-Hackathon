#include <string>;
#include <list>;
#include <iostream>;
#include "ProjetEmbarque.h";
#include "Materiel.h";
#include "Projet.h"

using namespace std;

// Constructeurs

// Constructeur par défaut
ProjetEmbarque::ProjetEmbarque()
{
    Projet::nombreProjets ++;
};

// Constructeur par recopie
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

// Destructeur
ProjetEmbarque::~ProjetEmbarque()
{
   for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        delete *it;
    }
    this->materiels.clear();
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir la liste des materiels
list <Materiel *> ProjetEmbarque::getMateriels()
{
    return this->materiels;
};

// Méthode pour modifier la liste des materiels
void ProjetEmbarque::setMateriels(list <Materiel *>materiels)
{
    this->materiels = materiels;
};

// Méthode pour ajouter un materiel dans la liste des materiels
void ProjetEmbarque::ajouterMateriel(Materiel* materiel)
{
    this->materiels.push_back(materiel);
};

// Méthode pour rechercher un materiel dans la liste des materiels par son nom
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
};

// Méthode pour supprimer un materiel dans la liste des materiels par son nom
void ProjetEmbarque::supprimerMateriel(string nomMateriel)
{
    Materiel* materiel = rechercherMateriel(nomMateriel);
    if (materiel!= nullptr)
    {
        this->materiels.remove(materiel);
        delete materiel;
    }
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations d'un projet embarqué
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
};

// Surcharge de l'opérateur >> pour saisir les informations d'un projet embarqué
istream& operator>>(istream& in, ProjetEmbarque& p)
{
    cout << "Entrez le titre du projet : ";
    getline(in >> ws, p.titre);
    cout << "Entrez la description du projet : ";
    getline(in >> ws, p.description);
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
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    return in;
};

// Méthode pour affecter un projet embarqué à un autre (opérateur d'affectation)
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

// Surcharge des opérateurs de comparaison

// Surcharge de l'opérateur >
bool ProjetEmbarque::operator>(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() > autreProjet.materiels.size();
};

// Surcharge de l'opérateur <
bool ProjetEmbarque::operator<(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() < autreProjet.materiels.size();
};

// Surcharge de l'opérateur >=
bool ProjetEmbarque::operator>=(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() >= autreProjet.materiels.size();
};

// Surcharge de l'opérateur <=
bool ProjetEmbarque::operator<=(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() <= autreProjet.materiels.size();
};

// Méthode pour afficher les details d'un projet embarqué
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

