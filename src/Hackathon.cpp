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

// Constructeur par d�faut
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

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le titre
string Hackathon::getTitre()
{
    return (this->titre);
};

// M�thode pour modifier le titre
void Hackathon::setTitre(string titre)
{
    this->titre = titre;
};

// M�thode pour obtenir la description
string Hackathon::getDescription()
{
    return (this->description);
};

// M�thode pour modifier la description
void Hackathon::setDescription(string description)
{
    this->description = description;
};

// M�thode pour obtenir la date de d�but
Date Hackathon::getDateDeDebut()
{
    return (this->dateDeDebut);
};

// M�thode pour modifier la date de d�but
void Hackathon::setDateDeDebut(Date dateDeDebut)
{
    this->dateDeDebut = dateDeDebut;
};

// M�thode pour obtenir la date de fin
Date Hackathon::getDateDeFin()
{
    return (this->dateDeFin);
};

// M�thode pour modifier la date de fin
void Hackathon::setDateDeFin(Date dateDeFin)
{
    this->dateDeFin = dateDeFin;
};

// M�thode pour obtenir le th�me
string Hackathon::getTheme()
{
    return (this->theme);
};

// M�thode pour modifier le th�me
void Hackathon::setTheme(string theme)
{
    this->theme = theme;
};

// M�thode pour obtenir le vector de gagnants
vector <Gagnant*> Hackathon::getGagnants()
{
    return this->gagnants;
};

// M�thode pour obtenir le vector de projets
vector <Projet*> Hackathon::getProjets()
{
    return this->projets;
};

// M�thode pour obtenir la liste de juges
list <Juge*> Hackathon::getJuges()
{
    return this->juges;
};

// M�thode pour obtenir la liste d'organisateurs
list <Organisateur*> Hackathon::getOrganisateurs()
{
    return this->organisateurs;
};

// M�thode pour obtenir le vector de projets embarqu�
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

// M�thode pour obtenir le vector de projets web
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

// M�thode pour ajouter un organisateur dans la liste des organisateurs
void Hackathon::ajouterOrganisateur(Organisateur* organisateur)
{
    this->organisateurs.push_back(organisateur);
};

// M�thode pour rechercher un organisateur dans la liste des organisateurs par son num�ro de carte d'identit� nationale (NCI)
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

// M�thode pour supprimer un organisateur dans la liste des organisateurs par son num�ro de carte d'identit� nationale (NCI)
void Hackathon::supprimerOrganisateur(int nciOrganisateur)
{
    Organisateur* organisateur = rechercherOrganisateur(nciOrganisateur);

    if (organisateur != nullptr)
    {
        this->organisateurs.remove(organisateur);
        delete organisateur;
    }
};

// M�thode pour ajouter un juge dans la liste des juges
void Hackathon::ajouterJuge(Juge* juge)
{
    this->juges.push_back(juge);
};

// M�thode pour rechercher un juge dans la liste des juges par son num�ro de carte d'identit� nationale (NCI)
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

// M�thode pour supprimer un juge dans la liste des juges par son num�ro de carte d'identit� nationale (NCI)
void Hackathon::supprimerJuge(int nciJuge)
{
    Juge* juge = rechercherJuge(nciJuge);

    if (juge != nullptr)
    {
        this->juges.remove(juge);
        delete juge;
    }
};

// M�thode pour ajouter projet dans le vector des projets
void Hackathon::ajouterProjet(Projet* projet)
{
    this->projets.push_back(projet);
};

// M�thode pour rechercher un projet dans le vector des projets par son titre
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

// M�thode pour supprimer un projet dans le vector des projets par son titre
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

// M�thode pour ajouter un gagnant dans le vector des gagnants
void Hackathon::ajouterGagnant(Gagnant* gagnant)
{
    this->gagnants.push_back(gagnant);
};

// M�thode pour rechercher un gagnant dans le vector des gagnants par le nom de l'�quipe
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

// M�thode pour remplir la liste des gagnants du hackathon en attribuant des r�compenses aux trois meilleurs projets �valu�s.
void Hackathon::remplirGagnants(string recompense1, string recompense2, string recompense3)
{
    // V�rifier s'il y a des projets inscrits
    if (projets.empty())
    {
        cout << "Aucun projet inscrit au this->" << endl;
        return;
    }
    // Trier les projets par moyenne d�croissante
    sort(projets.begin(), projets.end(), [](Projet* a, Projet* b)
    {
        return a->getEvaluation().calculerMoyenne() > b->getEvaluation().calculerMoyenne();
    });
    // Cr�er les trois premiers gagnants s'il y a au moins trois projets
    for (int i = 0; i < min(3, static_cast<int>(projets.size())); ++i)
    {
        float moyenne = projets[i]->getEvaluation().calculerMoyenne();
        string recompense = "";
        // D�terminer la r�compense en fonction du classement
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
        // Cr�er le gagnant avec le projet actuel
        Gagnant* gagnant = new Gagnant(i + 1, recompense, moyenne);
        gagnant->setProjet(projetActuel);
        gagnants.push_back(gagnant); // Ajouter le gagnant � le vector des gagnants
    }
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations d'un hackathon
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

// Surcharge de l'op�rateur >> pour saisir les informations d'un hackathon
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
            cout << "Choisissez le type de projet � ajouter (1 pour Projet Web, 2 pour Projet Embarque) : ";
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
            cout << "Choix invalide. Le projet sera ignor�." << endl;
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
    cout << "Entrez la r�compense de la premi�re place : ";
    getline(in >> ws, premierePlace);
    cout << "Entrez la r�compense de la deuxi�me place : ";
    getline(in >> ws, deuxiemePlace);
    cout << "Entrez la r�compense de la troisi�me place : ";
    getline(in >> ws, troisiemePlace);
    h.remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations d'un hackathon*
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

// Surcharge de l'op�rateur >> pour saisir les informations d'un hackathon*
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
            cout << "Choisissez le type de projet � ajouter (1 pour Projet Web, 2 pour Projet Embarque) : ";
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
            cout << "Choix invalide. Le projet sera ignor�." << endl;
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
    cout << "Entrez la r�compense de la premi�re place : ";
    getline(in >> ws, premierePlace);
    cout << "Entrez la r�compense de la deuxi�me place : ";
    getline(in >> ws, deuxiemePlace);
    cout << "Entrez la r�compense de la troisi�me place : ";
    getline(in >> ws, troisiemePlace);
    h->remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

// M�thode pour affecter un hackathon � une autre (op�rateur d'affectation)
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

// M�thode pour affecter un hackathon* � un autre hackathon* (op�rateur d'affectation)
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

// M�thode pour cr�er un fichier contenant les informations d'un hackathon
void Hackathon::creerFichierHackathon()
{
    if (this->titre.empty()) // V�rifier si le titre du hackathon est vide
    {
        cerr << "Erreur : Le titre du hackathon est vide." << endl;
        return;
    }
    string nomFichier = "fichier/" +this->titre + ".txt"; // Nom du fichier avec le titre du hackathon
    try
    {
        ofstream fichier(nomFichier); // Cr�er un nouveau fichier

        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // �crire les informations du hackathon dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier apr�s �criture
        cout << "Fichier hackathon cr�� avec succ�s : " << nomFichier << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour ajouter les informations du hackathon dans un fichier
void Hackathon::ajouterHackathonDansFichier(const string& nomFichier)
{
    try
    {
        ofstream fichier(nomFichier, ios::app); // Ouvrir le fichier en mode append (ajout) pour ne pas �craser le contenu existant
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // �crire les informations du hackathon dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier apr�s �criture
        cout << "Hackathon ajout� avec succ�s dans le fichier." << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour afficher le fichier contenant les informations du hackathon
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
        fichier.close(); // Fermer le fichier apr�s lecture
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl;  // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour ajouter equipe gagnante dans le map
void Hackathon::ajouterEquipeGagnante()
{
    for (Gagnant* gagnant : this->getGagnants())
    {
        int rangEquipe = gagnant->getRang();
        string nomEquipe = gagnant->getProjet()->getEquipe().getNom();
        equipeGagnante[rangEquipe] = nomEquipe;
    };
};

// M�thode pour afficher �quipe gagnante dans le map
void Hackathon::afficherEquipeGagnante()
{
    cout << "�quipes gagnantes :" << endl;
    for (auto& [rang, nomEquipe] : this->equipeGagnante)
    {
        cout << rang << " : " << nomEquipe << endl;
    }
};

// M�thode pour obtenir le projet embarqu� avec plus de mat�riels dans le hackathon
ProjetEmbarque* Hackathon::getProjetEmbarqueAvecPlusDeMateriels()
{
    // R�cup�rer la liste des projets embarqu� du hackathon
    vector<ProjetEmbarque*> projetsEmbarques = getProjetsEmbarques();
    // V�rifier si la liste des projets embarqu� est vide
    if (projetsEmbarques.empty())
    {
        return nullptr; // Retourner nullptr si aucun projet embarqu� n'est disponible
    }
    // Trier les projets embarqu� par nombre de mat�riels d�croissant
    sort(projetsEmbarques.begin(), projetsEmbarques.end(), [](ProjetEmbarque* a, ProjetEmbarque* b)
    {
        return *a > *b; // Utiliser l'op�rateur > d�fini pour les projets embarqu�s pour comparer le nombre de mat�riels
    });
    return projetsEmbarques[0]; // Retourner le projet embarqu� avec le plus de mat�riels (le premier �l�ment apr�s le tri)
};

// M�thode pour obtenir le projet web avec plus de technologies dans le hackathon
ProjetWeb* Hackathon::getProjetWebAvecPlusDeTechnologies()
{
    // R�cup�rer la liste des projets web du hackathon
    vector<ProjetWeb*> projetsWeb = getProjetsWeb();
    // V�rifier si la liste des projets web est vide
    if (projetsWeb.empty())
    {
        return nullptr; // Retourner nullptr si aucun projet web n'est disponible
    }
    // Trier les projets web par nombre de technologies d�croissant
    sort(projetsWeb.begin(), projetsWeb.end(), [](ProjetWeb* a, ProjetWeb* b)
    {
        return *a > *b; // Utiliser l'op�rateur > d�fini pour les projets web pour comparer le nombre de technologies
    });
    return projetsWeb[0]; // Retourner le projet web avec le plus de technologies (le premier �l�ment apr�s le tri)
};





