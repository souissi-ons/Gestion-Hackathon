#include <string>;
#include <vector>;
#include <iostream>;
#include "Equipe.h";
#include "Projet.h";
#include <limits>
using namespace std;

Equipe::Equipe() {};

Equipe::Equipe(const Equipe& e)
{
    this->nom = e.nom;
    this->dateCreation = e.dateCreation;
    Participant *p;
    for (int i=0; i<e.participants.size(); i++)
    {
        p=new Participant(*e.participants[i]);
        this->participants.push_back(p);
    }

};

Equipe::~Equipe()
{
    for (int i=0; i<this->participants.size(); i++)
    {
        delete this->participants[i];
    }
};

string Equipe::getNom()
{
    return this->nom;
};

void Equipe::setNom(string nom)
{
    this->nom = nom;
};

Date Equipe::getDateCreation()
{
    return this->dateCreation;
};

void Equipe::setDateCreation(Date dateCreation)
{
    this->dateCreation = dateCreation;
};

vector<Participant*> Equipe::getParticipants()
{
    return participants;
};

void Equipe::setParticipants(vector<Participant*> participants)
{
    this->participants = participants;
};

void Equipe::ajouterParticipant(Participant* participant)
{
    this->participants.push_back(participant);
};

int Equipe::rechercherParticipant(int nci)
{
    for (int i=0; i<this->participants.size(); i++)
    {
        if(this->participants[i]->getNci()==nci)
        {
            return i;
        }
    }
    return -1;
};

void Equipe::supprimerParticipant(int nci)
{
    int p = rechercherParticipant(nci);
    if (p!= -1)
    {
        this->participants.erase(participants.begin() + p);
    }
};

ostream& operator<<(ostream& out, Equipe& e)
{
    out << "Nom de l'équipe: " << e.nom << ", Date de création de l'équipe: " << e.dateCreation << endl;
    out << "Participants de l'equipe: " << endl;
    for (int i = 0; i < e.participants.size(); ++i)
    {
        out << "Participant " << i+1 << ": " << *(e.participants[i]);
    }
    return out;
}

istream& operator>>(istream& in, Equipe& e)
{
    cout << "Entrez le nom de l'équipe : ";
    getline(in, e.nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrez la date de création de l'équipe : ";
    in >> e.dateCreation; // Utilisation de l'opérateur >> de Date
    int continuer;
    do
    {
        Participant* p = new Participant();
        in >> *p; // Utilisation de l'opérateur >> de Participant
        e.participants.push_back(p);
        cout << "Veuillez saisir 1 si vous voulez ajouter un autre participant sinon 0: ";
        in >> continuer;
    }
    while (continuer == 1);
    return in;
};


Equipe& Equipe::operator=(const Equipe& autreEquipe)
{
    this->nom = autreEquipe.nom;
    this->dateCreation = autreEquipe.dateCreation;
    for (Participant* participant : this->participants)
    {
        delete participant;
    }
    this->participants.clear();
    for (Participant* participant : autreEquipe.participants)
    {
        this->ajouterParticipant(participant);
    }
    return *this;
};

ostream& operator<<(ostream& out, Equipe* e)
{
    out << "Nom de l'équipe: " << e->nom << ", Date de création de l'équipe: " << e->dateCreation << endl;
    out << "Participants de l'equipe: " << endl;
    for (int i = 0; i < e->participants.size(); ++i)
    {
        out << "Participant " << i+1 << ": " << *(e->participants[i]);
    }
    return out;
}

istream& operator>>(istream& in, Equipe* e)
{
    cout << "Entrez le nom de l'équipe : ";
    getline(in, e->nom);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrez la date de création de l'équipe : ";
    in >> e->dateCreation; // Utilisation de l'opérateur >> de Date
    int continuer;
    do
    {
        Participant* p = new Participant();
        in >> *p; // Utilisation de l'opérateur >> de Participant
        e->participants.push_back(p);
        cout << "Veuillez saisir 1 si vous voulez ajouter un autre participant sinon 0: ";
        in >> continuer;
    }
    while (continuer == 1);
    return in;
};

