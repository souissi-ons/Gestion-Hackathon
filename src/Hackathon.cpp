#include <string>
#include <vector>
#include <iostream>
#include "Hackathon.h"
#include "Projet.h"
#include "ProjetWeb.h"
#include "ProjetEmbarque.h"
#include "Gagnant.h"
#include "Equipe.h"
#include "Date.h"
#include <algorithm>
#include <fstream>

using namespace std;

// Constructeurs

// Constructeur par défaut
Hackathon::Hackathon() {};

// Constructeur par recopie
Hackathon::Hackathon(const Hackathon& h)
{
    this->titre = h.titre;
    this->description = h.description;
    this->dateDeDebut = h.dateDeDebut;
    this->dateDeFin = h.dateDeFin;
    this->theme = h.theme;
    Juge *j;
    for (list<Juge*>::const_iterator it = h.juges.begin(); it != h.juges.end(); ++it)
    {
        this->juges.push_back(*it);
    }
    this->juges.clear();
    for (list<Organisateur*>::const_iterator it = h.organisateurs.begin(); it != h.organisateurs.end(); ++it)
    {
        this->organisateurs.push_back(*it);
    }
    this->organisateurs.clear();

    for (const auto& projet : h.projets)
    {
        this->projets.push_back(projet);
    }
    Gagnant *g;
    for (int i=0; i<h.gagnants.size(); i++)
    {
        g=new Gagnant(*h.gagnants[i]);
        this->gagnants.push_back(g);
    }
};

// Desctructeur
Hackathon::~Hackathon()
{
    for (int i=0; i<this->projets.size(); i++)
    {
        delete this->projets[i];
    }
    for (int i=0; i<this->gagnants.size(); i++)
    {
        delete this->gagnants[i];
    }
    for (list<Juge*>::const_iterator it = this->juges.begin(); it != this->juges.end(); ++it)
    {
        delete *it;
    }
    for (list<Organisateur*>::const_iterator it = this->organisateurs.begin(); it != this->organisateurs.end(); ++it)
    {
        delete *it;
    }
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le titre
string Hackathon::getTitre()
{
    return (this->titre);
};

// Méthode pour modifier le titre
void Hackathon::setTitre(string titre)
{
    this->titre = titre;
};

// Méthode pour obtenir la description
string Hackathon::getDescription()
{
    return (this->description);
};

// Méthode pour modifier la description
void Hackathon::setDescription(string description)
{
    this->description = description;
};

// Méthode pour obtenir la date de début
Date Hackathon::getDateDeDebut()
{
    return (this->dateDeDebut);
};

// Méthode pour modifier la date de début
void Hackathon::setDateDeDebut(Date dateDeDebut)
{
    this->dateDeDebut = dateDeDebut;
};

// Méthode pour obtenir la date de fin
Date Hackathon::getDateDeFin()
{
    return (this->dateDeFin);
};

// Méthode pour modifier la date de fin
void Hackathon::setDateDeFin(Date dateDeFin)
{
    this->dateDeFin = dateDeFin;
};

// Méthode pour obtenir le thème
string Hackathon::getTheme()
{
    return (this->theme);
};

// Méthode pour modifier le thème
void Hackathon::setTheme(string theme)
{
    this->theme = theme;
};

// Méthode pour obtenir le vector de gagnants
vector <Gagnant*> Hackathon::getGagnants()
{
    return this->gagnants;
};

// Méthode pour obtenir le vector de projets
vector <Projet*> Hackathon::getProjets()
{
    return this->projets;
};

// Méthode pour obtenir la liste de juges
list <Juge*> Hackathon::getJuges()
{
    return this->juges;
};

// Méthode pour obtenir la liste d'organisateurs
list <Organisateur*> Hackathon::getOrganisateurs()
{
    return this->organisateurs;
};

// Méthode pour obtenir le vector de projets embarqué
vector<ProjetEmbarque*> Hackathon::getProjetsEmbarques()
{
    vector<ProjetEmbarque*> projetsEmbarques;
    for (const auto& projet : projets)
    {
        if (typeid(*projet) == typeid(ProjetEmbarque))
        {
            projetsEmbarques.push_back(dynamic_cast<ProjetEmbarque*>(projet));
        }
    }
    return projetsEmbarques;
};

// Méthode pour obtenir le vector de projets web
vector<ProjetWeb*> Hackathon::getProjetsWeb()
{
    vector<ProjetWeb*> projetsWeb;
    for (const auto& projet : projets)
    {
        if (typeid(*projet) == typeid(ProjetWeb))
        {
            projetsWeb.push_back(dynamic_cast<ProjetWeb*>(projet));
        }
    }
    return projetsWeb;
};

// Méthode pour ajouter un organisateur dans la liste des organisateurs
void Hackathon::ajouterOrganisateur(Organisateur* organisateur)
{
    this->organisateurs.push_back(organisateur);
};

// Méthode pour rechercher un organisateur dans la liste des organisateurs par son numéro de carte d'identité nationale (NCI)
Organisateur* Hackathon::rechercherOrganisateur(int nciOrganisateur)
{
    for (list<Organisateur*>::const_iterator it = this->organisateurs.begin(); it != this->organisateurs.end(); ++it)
    {
        if ((*it)->getNci() == nciOrganisateur)
        {
            return *it;
        }
    }
    return nullptr;
};

// Méthode pour supprimer un organisateur dans la liste des organisateurs par son numéro de carte d'identité nationale (NCI)
void Hackathon::supprimerOrganisateur(int nciOrganisateur)
{
    Organisateur* organisateur = rechercherOrganisateur(nciOrganisateur);

    if (organisateur != nullptr)
    {
        this->organisateurs.remove(organisateur);
        delete organisateur;
    }
};

// Méthode pour ajouter un juge dans la liste des juges
void Hackathon::ajouterJuge(Juge* juge)
{
    this->juges.push_back(juge);
};

// Méthode pour rechercher un juge dans la liste des juges par son numéro de carte d'identité nationale (NCI)
Juge* Hackathon::rechercherJuge(int nciJuge)
{
    for (list<Juge*>::const_iterator it = this->juges.begin(); it != this->juges.end(); ++it)
    {
        if ((*it)->getNci() == nciJuge)
        {
            return *it;
        }
    }
    return nullptr;
};

// Méthode pour supprimer un juge dans la liste des juges par son numéro de carte d'identité nationale (NCI)
void Hackathon::supprimerJuge(int nciJuge)
{
    Juge* juge = rechercherJuge(nciJuge);

    if (juge != nullptr)
    {
        this->juges.remove(juge);
        delete juge;
    }
};

// Méthode pour ajouter projet dans le vector des projets
void Hackathon::ajouterProjet(Projet* projet)
{
    this->projets.push_back(projet);
};

// Méthode pour rechercher un projet dans le vector des projets par son titre
int Hackathon::rechercherProjet(string titreProjet)
{
    for (int i=0; i<this->projets.size(); i++)
    {
        if(this->projets[i]->getTitre()== titreProjet)
        {
            return i;
        }
    }
    return -1;
};

// Méthode pour supprimer un projet dans le vector des projets par son titre
void Hackathon::supprimerProjet(string titreProjet)
{
    int p = rechercherProjet(titreProjet);
    if (p!= -1)
    {
        this->projets.erase(projets.begin() + p);
    }
    int nb = (Projet::getNombreProjets())-1;
    Projet::setNombreProjets(nb);
};

// Méthode pour ajouter un gagnant dans le vector des gagnants
void Hackathon::ajouterGagnant(Gagnant* gagnant)
{
    this->gagnants.push_back(gagnant);
};

// Méthode pour rechercher un gagnant dans le vector des gagnants par le nom de l'équipe
int Hackathon::rechercherGagnant(string nomEquipeGagnante)
{
    for (int i=0; i<this->gagnants.size(); i++)
    {
        if(this->gagnants[i]->getProjet()->getEquipe().getNom()== nomEquipeGagnante)
        {
            return i;
        }
    }
    return -1;
};

// Méthode pour remplir la liste des gagnants du hackathon en attribuant des récompenses aux trois meilleurs projets évalués.
void Hackathon::remplirGagnants(string recompense1, string recompense2, string recompense3)
{
    // Vérifier s'il y a des projets inscrits
    if (projets.empty())
    {
        cout << "Aucun projet inscrit au this->" << endl;
        return;
    }
    // Trier les projets par moyenne décroissante
    sort(projets.begin(), projets.end(), [](Projet* a, Projet* b)
    {
        return a->getEvaluation().calculerMoyenne() > b->getEvaluation().calculerMoyenne();
    });
    // Créer les trois premiers gagnants s'il y a au moins trois projets
    for (int i = 0; i < min(3, static_cast<int>(projets.size())); ++i)
    {
        float moyenne = projets[i]->getEvaluation().calculerMoyenne();
        string recompense = "";
        // Déterminer la récompense en fonction du classement
        if (i == 0)
        {
            recompense = recompense1;
        }
        else if (i == 1)
        {
            recompense = recompense2;
        }
        else if (i == 2)
        {
            recompense = recompense3;
        }
        // Trouver le projet actuel
        Projet* projetActuel = projets[i];
        // Créer le gagnant avec le projet actuel
        Gagnant* gagnant = new Gagnant(i + 1, recompense, moyenne);
        gagnant->setProjet(projetActuel);
        gagnants.push_back(gagnant); // Ajouter le gagnant à le vector des gagnants
    }
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations d'un hackathon
ostream& operator<<(ostream& out, Hackathon& h)
{
    out << "Hackathon: " << endl;
    out << endl;
    out << "Titre du hackathon: " << h.titre << ", Description du hackathon: " << h.description <<endl;
    out << "Date de debut du hackathon: " << h.dateDeDebut << ", Date de fin du hackathon: " << h.dateDeFin << ", Theme du hackathon: " << h.theme <<  endl;
    out << endl;
    out << "Organisateurs du hackathon:" << endl;
    int i = 0;
    for (list<Organisateur*>::iterator it = h.organisateurs.begin(); it != h.organisateurs.end(); ++it)
    {
        i++;
        out << "Organisateur " << i << ": " << **it;
    }
    out << endl;
    out << "Jury du hackathon:" << endl;
    out << endl;
    i = 0;
    for (list<Juge*>::iterator it = h.juges.begin(); it != h.juges.end(); ++it)
    {
        i++;
        out << "Membre du jury " << i << ": " << endl;
        out << **it << endl;
    }
    out << endl;

    out << "Projets du hackathon:" << endl;
    out << endl;
    i = 0;
    for (const auto& projet : h.projets)
    {
        i++;
        out << "Projet " << i << ": ";
        out << endl;
        if (typeid(*projet) == typeid(ProjetWeb))
        {
            out << *dynamic_cast<ProjetWeb*>(projet);
        }
        else if (typeid(*projet) == typeid(ProjetEmbarque))
        {
            out << *dynamic_cast<ProjetEmbarque*>(projet);
        }
        out << endl;
    }
    out << endl;
    i=0;
    out << "Gagnants du hackathon:" << endl;
    out << endl;
    for (const auto& gagnant : h.gagnants)
    {
        i++;
        out << "Gagnant" << i << ": " << *gagnant ;
        out << endl;
    }
    out << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations d'un hackathon
istream& operator>>(istream& in, Hackathon& h)
{
    Date d;
    cout << "Entrez le titre du hackathon : ";
    getline(in >> ws, h.titre);
    cout << "Entrez la description du hackathon : ";
    getline(in >> ws, h.description);
    cout << "Entrez la date de debut du hackathon : ";
    in >> h.dateDeDebut;
    do
    {
        cout << "Entrez la date de fin du hackathon : ";
        in >> h.dateDeFin;
    }
    while (h.dateDeFin <= h.dateDeDebut);
    cout << "Entrez le theme du hackathon : ";
    getline(in >> ws, h.theme);
    int continuer;
    do
    {
        Organisateur* organisateur = new Organisateur();
        in >> *organisateur;
        h.organisateurs.push_back(organisateur);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre organisateur sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    do
    {
        Juge* juge = new Juge();
        in >> *juge;
        h.juges.push_back(juge);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre juge sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    int choix;
    do
    {
        do
        {
            cout << "Choisissez le type de projet à ajouter (1 pour Projet Web, 2 pour Projet Embarque) : ";
            in >> choix;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (choix !=1 && choix!=2);

        if (choix == 1)
        {
            ProjetWeb* projetWeb = new ProjetWeb();
            in >> *projetWeb;
            h.projets.push_back(projetWeb);
        }
        else if (choix == 2)
        {
            ProjetEmbarque* projetEmbarque = new ProjetEmbarque();
            in >> *projetEmbarque;
            h.projets.push_back(projetEmbarque);
        }
        else
        {
            cout << "Choix invalide. Le projet sera ignoré." << endl;
        }

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre projet sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer !=0 && continuer!=1);
    }
    while (continuer == 1);
    string premierePlace, deuxiemePlace, troisiemePlace;
    cout << "Entrez la récompense de la première place : ";
    getline(in >> ws, premierePlace);
    cout << "Entrez la récompense de la deuxième place : ";
    getline(in >> ws, deuxiemePlace);
    cout << "Entrez la récompense de la troisième place : ";
    getline(in >> ws, troisiemePlace);
    h.remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

// Surcharge de l'opérateur << pour afficher les informations d'un hackathon*
ostream& operator<<(ostream& out, Hackathon* h)
{
    out << "Hackathon: " << endl;
    out << endl;
    out << "Titre du hackathon: " << h->titre << ", Description du hackathon: " << h->description <<endl;
    out << "Date de debut du hackathon: " << h->dateDeDebut << ", Date de fin du hackathon: " << h->dateDeFin << ", Theme du hackathon: " << h->theme <<  endl;
    out << endl;
    out << "Organisateurs du hackathon:" << endl;
    int i =0;
    for (const auto& organisateur : h->organisateurs)
    {
        i++;
        out << "Organisateur " << i << ": " << *organisateur;
    }
    out << endl;
    out << "Jury du hackathon:" << endl;
    i=0;
    for (const auto& juge : h->juges)
    {
        i++;
        out << "Membre du jury " << i << ": " << *juge ;

    }
    out << endl;
    i=0;
    out << "Projets du hackathon:" << endl;
    out << endl;
    for (const auto& projet : h->projets)
    {
        i++;
        out << "Projet " << i << ": ";
        if (typeid(*projet) == typeid(ProjetWeb))
        {
            out << *dynamic_cast<ProjetWeb*>(projet);
        }
        else if (typeid(*projet) == typeid(ProjetEmbarque))
        {
            out << *dynamic_cast<ProjetEmbarque*>(projet);
        }
        out << endl;
    }
    out << endl;
    i=0;
    out << "Gagnants du hackathon:" << endl;
    out << endl;
    for (const auto& gagnant : h->gagnants)
    {
        i++;
        out << "Gagnant" << i << ": " << *gagnant ;
        out << endl;
    }
    out << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations d'un hackathon*
istream& operator>>(istream& in, Hackathon* h)
{
    cout << "Entrez le titre du hackathon : ";
    getline(in >> ws, h->titre);
    cout << "Entrez la description du hackathon : ";
    getline(in >> ws, h->description);
    cout << "Entrez la date de debut du hackathon : ";
    in >> h->dateDeDebut;
    do
    {
        cout << "Entrez la date de fin du hackathon : ";
        in >> h->dateDeFin;
    }
    while (h->dateDeFin <= h->dateDeDebut);
    cout << "Entrez le theme du hackathon : ";
    getline(in >> ws, h->theme);
    int continuer;
    do
    {
        Organisateur* organisateur = new Organisateur();
        in >> *organisateur;
        h->organisateurs.push_back(organisateur);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre organisateur sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    do
    {
        Juge* juge = new Juge();
        in >> *juge;
        h->juges.push_back(juge);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre juge sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    int choix;
    do
    {
        do
        {
            cout << "Choisissez le type de projet à ajouter (1 pour Projet Web, 2 pour Projet Embarque) : ";
            in >> choix;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (choix !=1 && choix!=2);

        if (choix == 1)
        {
            ProjetWeb* projetWeb = new ProjetWeb();
            in >> *projetWeb;
            h->projets.push_back(projetWeb);
        }
        else if (choix == 2)
        {
            ProjetEmbarque* projetEmbarque = new ProjetEmbarque();
            in >> *projetEmbarque;
            h->projets.push_back(projetEmbarque);
        }
        else
        {
            cout << "Choix invalide. Le projet sera ignoré." << endl;
        }

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre projet sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer !=0 && continuer!=1);
    }
    while (continuer == 1);
    string premierePlace, deuxiemePlace, troisiemePlace;
    cout << "Entrez la récompense de la première place : ";
    getline(in >> ws, premierePlace);
    cout << "Entrez la récompense de la deuxième place : ";
    getline(in >> ws, deuxiemePlace);
    cout << "Entrez la récompense de la troisième place : ";
    getline(in >> ws, troisiemePlace);
    h->remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

// Méthode pour affecter un hackathon à une autre (opérateur d'affectation)
Hackathon& Hackathon::operator=(const Hackathon& other)
{
    this->titre = other.titre;
    this->description = other.description;
    this->dateDeDebut = other.dateDeDebut;
    this->dateDeFin = other.dateDeFin;
    this->theme = other.theme;

    this->projets.clear();
    this->gagnants.clear();
    this->juges.clear();
    this->organisateurs.clear();

    for (Projet* projet : other.projets)
    {
        this->ajouterProjet(projet);
    }

    for (Gagnant* gagnant : other.gagnants)
    {
        this->ajouterGagnant(gagnant);
    }

    for (Juge* juge : other.juges)
    {
        this->ajouterJuge(juge);
    }

    for (Organisateur* organisateur : other.organisateurs)
    {
        this->ajouterOrganisateur(organisateur);
    }
    return *this;
};

// Méthode pour affecter un hackathon* à un autre hackathon* (opérateur d'affectation)
Hackathon& Hackathon::operator=(const Hackathon* other)
{
    this->titre = other->titre;
    this->description = other->description;
    this->dateDeDebut = other->dateDeDebut;
    this->dateDeFin = other->dateDeFin;
    this->theme = other->theme;

    this->projets.clear();
    this->gagnants.clear();
    this->juges.clear();
    this->organisateurs.clear();

    for (Projet* projet : other->projets)
    {
        this->ajouterProjet(projet);
    }

    for (Gagnant* gagnant : other->gagnants)
    {
        this->ajouterGagnant(gagnant);
    }

    for (Juge* juge : other->juges)
    {
        this->ajouterJuge(juge);
    }

    for (Organisateur* organisateur : other->organisateurs)
    {
        this->ajouterOrganisateur(organisateur);
    }
    return *this;
};

// Méthode pour créer un fichier contenant les informations d'un hackathon
void Hackathon::creerFichierHackathon()
{
    if (this->titre.empty()) // Vérifier si le titre du hackathon est vide
    {
        cerr << "Erreur : Le titre du hackathon est vide." << endl;
        return;
    }
    string nomFichier = "fichier/" +this->titre + ".txt"; // Nom du fichier avec le titre du hackathon
    try
    {
        ofstream fichier(nomFichier); // Créer un nouveau fichier

        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // Écrire les informations du hackathon dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier après écriture
        cout << "Fichier hackathon créé avec succès : " << nomFichier << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour ajouter les informations du hackathon dans un fichier
void Hackathon::ajouterHackathonDansFichier(const string& nomFichier)
{
    try
    {
        ofstream fichier(nomFichier, ios::app); // Ouvrir le fichier en mode append (ajout) pour ne pas écraser le contenu existant
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // Écrire les informations du hackathon dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier après écriture
        cout << "Hackathon ajouté avec succès dans le fichier." << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour afficher le fichier contenant les informations du hackathon
void Hackathon::afficherHackathonsDeFichier(const string& nomFichier)
{
    try
    {
        ifstream fichier(nomFichier); // Ouvrir le fichier en mode lecture
        if (!fichier.good())
        {
            cerr << "Erreur : Le fichier avec ce nom n'existe pas." << endl;
            return;
        }
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        string ligne;
        while (!fichier.eof())
        {
            getline(fichier, ligne); // Lire chaque ligne du fichier
            cout << ligne << endl; // Afficher la ligne lue
        }
        fichier.close(); // Fermer le fichier après lecture
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl;  // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour ajouter equipe gagnante dans le map
void Hackathon::ajouterEquipeGagnante()
{
    for (Gagnant* gagnant : this->getGagnants())
    {
        int rangEquipe = gagnant->getRang();
        string nomEquipe = gagnant->getProjet()->getEquipe().getNom();
        equipeGagnante[rangEquipe] = nomEquipe;
    };
};

// Méthode pour afficher équipe gagnante dans le map
void Hackathon::afficherEquipeGagnante()
{
    cout << "Équipes gagnantes :" << endl;
    for (auto& [rang, nomEquipe] : this->equipeGagnante)
    {
        cout << rang << " : " << nomEquipe << endl;
    }
};

// Méthode pour obtenir le projet embarqué avec plus de matériels dans le hackathon
ProjetEmbarque* Hackathon::getProjetEmbarqueAvecPlusDeMateriels()
{
    // Récupérer la liste des projets embarqué du hackathon
    vector<ProjetEmbarque*> projetsEmbarques = getProjetsEmbarques();
    // Vérifier si la liste des projets embarqué est vide
    if (projetsEmbarques.empty())
    {
        return nullptr; // Retourner nullptr si aucun projet embarqué n'est disponible
    }
    // Trier les projets embarqué par nombre de matériels décroissant
    sort(projetsEmbarques.begin(), projetsEmbarques.end(), [](ProjetEmbarque* a, ProjetEmbarque* b)
    {
        return *a > *b; // Utiliser l'opérateur > défini pour les projets embarqués pour comparer le nombre de matériels
    });
    return projetsEmbarques[0]; // Retourner le projet embarqué avec le plus de matériels (le premier élément après le tri)
};

// Méthode pour obtenir le projet web avec plus de technologies dans le hackathon
ProjetWeb* Hackathon::getProjetWebAvecPlusDeTechnologies()
{
    // Récupérer la liste des projets web du hackathon
    vector<ProjetWeb*> projetsWeb = getProjetsWeb();
    // Vérifier si la liste des projets web est vide
    if (projetsWeb.empty())
    {
        return nullptr; // Retourner nullptr si aucun projet web n'est disponible
    }
    // Trier les projets web par nombre de technologies décroissant
    sort(projetsWeb.begin(), projetsWeb.end(), [](ProjetWeb* a, ProjetWeb* b)
    {
        return *a > *b; // Utiliser l'opérateur > défini pour les projets web pour comparer le nombre de technologies
    });
    return projetsWeb[0]; // Retourner le projet web avec le plus de technologies (le premier élément après le tri)
};





