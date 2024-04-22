#include <string>;
#include <list>;
#include <iostream>;
#include "ProjetEmbarque.h";
#include "Materiel.h";
#include "Projet.h"

using namespace std;

// Constructeurs

// Constructeur par d�faut
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

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir la liste des materiels
list <Materiel *> ProjetEmbarque::getMateriels()
{
    return this->materiels;
};

// M�thode pour modifier la liste des materiels
void ProjetEmbarque::setMateriels(list <Materiel *>materiels)
{
    this->materiels = materiels;
};

// M�thode pour ajouter un materiel dans la liste des materiels
void ProjetEmbarque::ajouterMateriel(Materiel* materiel)
{
    this->materiels.push_back(materiel);
};

// M�thode pour rechercher un materiel dans la liste des materiels par son nom
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

// M�thode pour supprimer un materiel dans la liste des materiels par son nom
void ProjetEmbarque::supprimerMateriel(string nomMateriel)
{
    Materiel* materiel = rechercherMateriel(nomMateriel);
    if (materiel!= nullptr)
    {
        this->materiels.remove(materiel);
        delete materiel;
    }
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations d'un projet embarqu�
ostream& operator<<(ostream& out, ProjetEmbarque& p)
{
    out << "Projet embarqu� : Titre du projet: " << p.titre << ", Description du projet: " << p.description << "\n" << "Evaluation du projet : " << p.evaluation << "Equipe du projet: " <<  p.equipe;
    out << "Materiels du projet: " << endl;
    int i=0;
    for (list<Materiel*>::const_iterator it = p.materiels.begin(); it != p.materiels.end(); ++it)
    {
        i++;
        out << "Materiel " << i << ": " << *it ;
    }
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations d'un projet embarqu�
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

// M�thode pour affecter un projet embarqu� � un autre (op�rateur d'affectation)
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

// Surcharge des op�rateurs de comparaison

// Surcharge de l'op�rateur >
bool ProjetEmbarque::operator>(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() > autreProjet.materiels.size();
};

// Surcharge de l'op�rateur <
bool ProjetEmbarque::operator<(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() < autreProjet.materiels.size();
};

// Surcharge de l'op�rateur >=
bool ProjetEmbarque::operator>=(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() >= autreProjet.materiels.size();
};

// Surcharge de l'op�rateur <=
bool ProjetEmbarque::operator<=(ProjetEmbarque& autreProjet)
{
    return this->materiels.size() <= autreProjet.materiels.size();
};

// M�thode pour afficher les details d'un projet embarqu�
void ProjetEmbarque::afficherDetails()
{
    cout << "D�tails du projet embarqu�" << endl;
    Projet::afficherDetails();
    int i=0;
    for (list<Materiel*>::const_iterator it = this->materiels.begin(); it != this->materiels.end(); ++it)
    {
        i++;
        cout << "Materiel " << i << ": " << *it ;
    }
};

