#ifndef HACKATHON_H
#define HACKATHON_H

#include <string>;
#include <vector>;
#include <list>;
#include <map>;
#include <iterator>
#include "Gagnant.h";
#include "Projet.h";
#include "Date.h";
#include "Organisateur.h";
#include "Juge.h";
#include "Date.h";
using namespace std;

class Hackathon
{
private:
    string titre;
    string description;
    Date dateDeDebut;
    Date dateDeFin;
    string theme;
    vector <Gagnant *> gagnants;
    vector <Projet *> projets;
    list <Juge *> juges;
    list <Organisateur *> organisateurs;
    map<int, string> equipeGagnante;

public:
    Hackathon();
    Hackathon(const Hackathon&);
    ~Hackathon();
    string getTitre();
    void setTitre(string);
    string getDescription();
    void setDescription(string);
    Date getDateDeDebut();
    void setDateDeDebut(Date);
    Date getDateDeFin();
    void setDateDeFin(Date);
    string getTheme();
    void setTheme(string);
    vector <Gagnant*> getGagnants();
    vector <Projet*> getProjets();
    list <Juge*> getJuges();
    list <Organisateur*> getOrganisateurs();
    void ajouterOrganisateur(Organisateur*);
    Organisateur* rechercherOrganisateur(int);
    void supprimerOrganisateur(int);
    void ajouterJuge(Juge*);
    Juge* rechercherJuge(int);
    void supprimerJuge(int);
    void ajouterProjet(Projet*);
    int rechercherProjet(string);
    void supprimerProjet(string);
    void ajouterGagnant(Gagnant*);
    int rechercherGagnant(string);
    void supprimerGagnant(string);
    void remplirGagnants(string, string, string);
    friend ostream& operator << (ostream&, Hackathon&);
    friend istream& operator >> (istream&, Hackathon&);
    friend ostream& operator << (ostream&, Hackathon*);
    friend istream& operator >> (istream&, Hackathon*);
    Hackathon& operator=(const Hackathon&);
    Hackathon& operator=(const Hackathon*);
    static void afficherHackathonsDeFichier(const string&);
    void ajouterHackathonDansFichier(const string&);
    void creerFichierHackathon();
    void ajouterEquipeGagnante();
    void afficherEquipeGagnante();
};
#endif

