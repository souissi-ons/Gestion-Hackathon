#include <string>;
#include <vector>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Participant.h";
#include <limits>
using namespace std;

Participant::Participant() {};

Participant::Participant(const Participant& p)
{
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;

    Competence *c;
    for (int i=0; i<p.competences.size(); i++)
    {
        c=new Competence(*p.competences[i]);
        this->competences.push_back(c);
    }
};

// Destructeur
Participant::~Participant()
{
    for (int i=0; i<this->competences.size(); i++)
    {
        delete this->competences[i];
    }
};

vector <Competence *> Participant::getCompetences()
{
    return this->competences;
};

void Participant::setCompetences(vector <Competence *> competences)
{
    this->competences = competences;
}

void Participant::ajouterCompetence(const Competence& competence)
{
    Competence* nouvelleCompetence = new Competence(competence);
    this->competences.push_back(nouvelleCompetence);
};

int Participant::rechercherCompetence(string nomCompetence)
{
    for (int i=0; i<this->competences.size(); i++)
    {
        if(this->competences[i]->getNom()==nomCompetence)
        {
            return i;
        }
    }
    return -1;
};

void Participant::supprimerCompetence(string nomCompetence)
{
    int p = rechercherCompetence(nomCompetence);
    if (p!= -1)
    {
        this->competences.erase(competences.begin() + p);
    }
};

ostream& operator<<(ostream& out, Participant& p)
{
    out << "Cin du participant: " << p.getNci() <<  ", Nom du participant: " << p.getNom() << ", Email du participant: " << p.getEmail() << endl;
    out << "Competences du participant: " << endl;
    for (int i = 0; i < p.competences.size(); ++i)
    {
        out << "Competence " << i+1 << ": " << p.competences[i];
    }
    return out;
};

istream& operator>>(istream& in, Participant& p)
{
    cout << "Entrez le NCI du participant : ";
    in >> p.nci;
    cout << "Entrez le nom du participant : ";
    getline(in, p.nom);
    in.ignore();
    cout << "Entrez l'email du participant : ";
    getline(in, p.email);
    in.ignore();
    int continuer;
    do
    {
        Competence *c = new Competence();
        in >> c;
        p.competences.push_back(c);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre competence sinon 0: ";
            in >> continuer;
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);
    return in;
};

Participant& Participant::operator=(const Participant& autreParticipant)
{
    this->nci= autreParticipant.nci;
    this->nom= autreParticipant.nom;
    this->email= autreParticipant.email;

    for (Competence* competence : this->competences)
    {
        delete competence;
    }

    this->competences.clear();

    for (Competence* competence : autreParticipant.competences)
    {
        this->ajouterCompetence(*competence);
    }

    return *this;
};


void Participant::afficherDetails(){
    cout << "Détails du participant :" << endl;
    Personne::afficherDetails();
    for (int i = 0; i < this->competences.size(); ++i)
    {
        cout << "Competence " << i+1 << ": " << this->competences[i];
    }
};
