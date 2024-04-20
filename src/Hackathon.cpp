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

Hackathon::Hackathon() {};

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

    for (list<Organisateur*>::const_iterator it = h.organisateurs.begin(); it != h.organisateurs.end(); ++it)
    {
        this->organisateurs.push_back(*it);
    }

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

string Hackathon::getTitre()
{
    return (this->titre);
};

void Hackathon::setTitre(string titre)
{
    this->titre = titre;
};

string Hackathon::getDescription()
{
    return (this->description);
};

void Hackathon::setDescription(string description)
{
    this->description = description;
};

Date Hackathon::getDateDeDebut()
{
    return (this->dateDeDebut);
};

void Hackathon::setDateDeDebut(Date dateDeDebut)
{
    this->dateDeDebut = dateDeDebut;
};

Date Hackathon::getDateDeFin()
{
    return (this->dateDeFin);
};

void Hackathon::setDateDeFin(Date dateDeFin)
{
    this->dateDeFin = dateDeFin;
};

string Hackathon::getTheme()
{
    return (this->theme);
};

void Hackathon::setTheme(string theme)
{
    this->theme = theme;
};

vector <Gagnant*> Hackathon::getGagnants()
{
    return this->gagnants;
};

vector <Projet*> Hackathon::getProjets()
{
    return this->projets;
};

list <Juge*> Hackathon::getJuges()
{
    return this->juges;
};

list <Organisateur*> Hackathon::getOrganisateurs()
{
    return this->organisateurs;
};

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

void Hackathon::ajouterOrganisateur(Organisateur* organisateur)
{
    this->organisateurs.push_back(organisateur);
};

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

void Hackathon::supprimerOrganisateur(int nciOrganisateur)
{
    Organisateur* organisateur = rechercherOrganisateur(nciOrganisateur);

    if (organisateur != nullptr)
    {
        this->organisateurs.remove(organisateur);
        delete organisateur;
    }
};

void Hackathon::ajouterJuge(Juge* juge)
{
    this->juges.push_back(juge);
};

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

void Hackathon::supprimerJuge(int nciJuge)
{
    Juge* juge = rechercherJuge(nciJuge);

    if (juge != nullptr)
    {
        this->juges.remove(juge);
        delete juge;
    }
};

void Hackathon::ajouterProjet(Projet* projet)
{
    this->projets.push_back(projet);
};

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

void Hackathon::ajouterGagnant(Gagnant* gagnant)
{
    this->gagnants.push_back(gagnant);
};

int Hackathon::rechercherGagnant(string nomEquipeGagnante)
{
    for (int i=0; i<this->gagnants.size(); i++)
    {
        if(this->gagnants[i]->getProjet()->getEquipe()->getNom()== nomEquipeGagnante)
        {
            return i;
        }
    }
    return -1;
};

void Hackathon::remplirGagnants(string recompense1, string recompense2, string recompense3)
{
    if (projets.empty())
    {
        cout << "Aucun projet inscrit au this->" << endl;
        return;
    }

    // Trier les projets par moyenne décroissante
    sort(projets.begin(), projets.end(), [](Projet* a, Projet* b)
    {
        return a->getEvaluation()->calculerMoyenne() > b->getEvaluation()->calculerMoyenne();
    });

    // Créer les trois premiers gagnants s'il y a au moins trois projets
    for (int i = 0; i < min(3, static_cast<int>(projets.size())); ++i)
    {
        float moyenne = projets[i]->getEvaluation()->calculerMoyenne();
        string recompense = "";
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
        gagnants.push_back(gagnant);
    }
}

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

istream& operator>>(istream& in, Hackathon& h)
{
    Date d;
    cout << "Entrez le titre du hackathon : ";
    getline(in, h.titre);
    in.ignore();
    cout << "Entrez la description du hackathon : ";
    getline(in, h.description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrez la date de debut du hackathon : ";
    in >> h.dateDeDebut;
    do
    {
        cout << "Entrez la date de fin du hackathon : ";
        in >> h.dateDeFin;
    }
    while (h.dateDeFin <= h.dateDeDebut);
    cout << "Entrez le theme du hackathon : ";
    getline(in, h.theme);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
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
        }
        while (continuer !=0 && continuer!=1);
    }
    while (continuer == 1);
    string premierePlace, deuxiemePlace, troisiemePlace;
    cout << "Entrez la récompense de la première place : ";
    getline(in, premierePlace);
    in.ignore();
    cout << "Entrez la récompense de la deuxième place : ";
    getline(in, deuxiemePlace);
    in.ignore();
    cout << "Entrez la récompense de la troisième place : ";
    getline(in, troisiemePlace);
    in.ignore();
    h.remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

void Hackathon::creerFichierHackathon()
{
    if (this->titre.empty())
    {
        cerr << "Erreur : Le titre du hackathon est vide." << endl;
        return;
    }
    string nomFichier = "fichier/" +this->titre + ".txt";
    try
    {
        ofstream fichier(nomFichier);

        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this;
        fichier << endl;
        fichier << endl;
        fichier.close();
        cout << "Fichier hackathon créé avec succès : " << nomFichier << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }
};

void Hackathon::ajouterHackathonDansFichier(const string& nomFichier)
{
    try
    {
        ofstream fichier(nomFichier, ios::app);
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this;
        fichier << endl;
        fichier << endl;
        fichier.close();
        cout << "Hackathon ajouté avec succès dans le fichier." << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }
};

void Hackathon::afficherHackathonsDeFichier(const string& nomFichier)
{
    try
    {
        ifstream fichier(nomFichier);
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
            getline(fichier, ligne);
            cout << ligne << endl;
        }
        fichier.close();
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }
};

void Hackathon::ajouterEquipeGagnante()
{
    for (Gagnant* gagnant : this->getGagnants())
    {
        int rangEquipe = gagnant->getRang();
        string nomEquipe = gagnant->getProjet()->getEquipe()->getNom();
        equipeGagnante[rangEquipe] = nomEquipe;
    };
};

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

void Hackathon::afficherEquipeGagnante()
{
    cout << "Équipes gagnantes :" << endl;
    for (auto& [rang, nomEquipe] : this->equipeGagnante)
    {
        cout << rang << " : " << nomEquipe << endl;
    }
};

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

istream& operator>>(istream& in, Hackathon* h)
{
    Date d;
    cout << "Entrez le titre du hackathon : ";
    getline(in, h->titre);
    in.ignore();
    cout << "Entrez la description du hackathon : ";
    getline(in, h->description);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrez la date de debut du hackathon : ";
    in >> h->dateDeDebut;
    do
    {
        cout << "Entrez la date de fin du hackathon : ";
        in >> h->dateDeFin;
    }
    while (h->dateDeFin <= h->dateDeDebut);
    cout << "Entrez le theme du hackathon : ";
    getline(in, h->theme);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
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
        }
        while (continuer !=0 && continuer!=1);
    }
    while (continuer == 1);
    string premierePlace, deuxiemePlace, troisiemePlace;
    cout << "Entrez la récompense de la première place : ";
    getline(in, premierePlace);
    in.ignore();
    cout << "Entrez la récompense de la deuxième place : ";
    getline(in, deuxiemePlace);
    in.ignore();
    cout << "Entrez la récompense de la troisième place : ";
    getline(in, troisiemePlace);
    in.ignore();
    h->remplirGagnants(premierePlace, deuxiemePlace, troisiemePlace);
    return in;
};

ProjetEmbarque* Hackathon::getProjetEmbarqueAvecPlusDeMateriels()
{
    vector<ProjetEmbarque*> projetsEmbarques = getProjetsEmbarques();
    if (projetsEmbarques.empty())
    {
        return nullptr;
    }
    sort(projetsEmbarques.begin(), projetsEmbarques.end(), [](ProjetEmbarque* a, ProjetEmbarque* b)
    {
        return *a > *b;
    });
    return projetsEmbarques[0];

};

ProjetWeb* Hackathon::getProjetWebAvecPlusDeTechnologies()
{
    vector<ProjetWeb*> projetsWeb = getProjetsWeb();
    if (projetsWeb.empty())
    {
        return nullptr;
    }
    sort(projetsWeb.begin(), projetsWeb.end(), [](ProjetWeb* a, ProjetWeb* b)
    {
        return *a > *b;
    });
    return projetsWeb[0];
};





