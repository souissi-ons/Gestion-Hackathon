#include <string>;
#include <map>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Participant.h";
#include <limits>

using namespace std;

// Initialisation du nombre de participants
int Participant::nombreParticipants = 0;

// Constructeurs

// Constructeur par d�faut
Participant::Participant()
{
    Participant::nombreParticipants++;
};

// Constructeur par recopie
Participant::Participant(const Participant& p)
{
    Participant::nombreParticipants++;
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;
    for (list<string>::const_iterator it = p.numerosTelephone.begin(); it != p.numerosTelephone.end(); ++it)
    {
        this->numerosTelephone.push_back(*it);
    }
    for (list<string>::const_iterator it = p.adresses.begin(); it != p.adresses.end(); ++it)
    {
        this->adresses.push_back(*it);
    }
    map<string, string>::const_iterator it;
    for (it = p.competences.begin(); it != p.competences.end(); ++it)
    {
        this->competences[it->first] = it->second;
    }
}

// Desctructeur
Participant::~Participant() {}

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le map des participants
map<string, string> Participant::getCompetences()
{
    return this->competences;
};

// M�thode pour modifier le map des participants
void Participant::setCompetences(map<string, string> competences)
{
    this->competences = competences;
};

// M�thode pour obtenir le nombre de participants
int Participant::getNombreParticipants()
{
    return Participant::nombreParticipants;
};

// M�thode pour modifier le nombre de participants
void Participant::setNombreParticipants(int nb)
{
    Participant::nombreParticipants = nb;
};

// M�thode pour rechercher une comp�tence dans le map des comp�tences par son nom
int Participant::rechercherCompetence(string nomCompetence)
{
    map<string, string>::iterator it;
    for (it = this->competences.begin(); it != this->competences.end(); ++it)
    {
        if (it->first == nomCompetence)
        {
            return distance(this->competences.begin(), it);
        }
    }
    return -1;
};

// M�thode pour ajouter une comp�tence dans le map des comp�tences
void Participant::ajouterCompetence(Competence& competence)
{
    if (this->competences.find(competence.getNom()) == this->competences.end())
    {
        this->competences[competence.getNom()] = competence.getDescription();
    }
    else
    {
        cout << "La competence avec le nom '" << competence.getNom() << "' existe deja." << endl;
    }
};

// M�thode pour supprimer une comp�tence dans le map des comp�tences par son nom
void Participant::supprimerCompetence(string nomCompetence)
{
    this->competences.erase(nomCompetence);
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations d'un participant
ostream& operator<<(ostream& out, Participant& p)
{
    out << "Cin du participant: " << p.getNci() << ", Nom du participant: " << p.getNom() << ", Email du participant: " << p.getEmail() << endl;
    out << "Numeros de telephone du participant: ";
    list<string>::iterator itNumeros;
    for (itNumeros = p.numerosTelephone.begin(); itNumeros != p.numerosTelephone.end(); ++itNumeros)
    {
        out << *itNumeros << ", ";
    }
    out << endl;
    out << "Adresses du participant: ";
    list<string>::iterator itAdresses;
    for (itAdresses = p.adresses.begin(); itAdresses != p.adresses.end(); ++itAdresses)
    {
        out << *itAdresses << ", ";
    }
    out << endl;
    out << "Competences du participant: " << endl;
    map<string, string>::iterator it;
    for (it = p.competences.begin(); it != p.competences.end(); ++it)
    {
        out << "Nom de la competence: " << it->first << ", Description de la competence: " << it->second << endl;
    }
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations d'un participant
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
    int continuerNumeros;
    do
    {
        string numero;
        cout << "Entrez un num�ro de t�l�phone : ";
        getline(cin, numero);
        in.ignore();
        p.ajouterNumeroTelephone(numero);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre num�ro de t�l�phone sinon 0: ";
            cin >> continuerNumeros;
        }
        while (continuerNumeros != 0 && continuerNumeros != 1);
    }
    while (continuerNumeros == 1);

    int continuerAdresses;
    do
    {
        string adresse;
        cout << "Entrez une adresse : ";
        getline(cin, adresse);
        in.ignore();
        p.ajouterAdresse(adresse);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            cin >> continuerAdresses;
        }
        while (continuerAdresses != 0 && continuerAdresses != 1);
    }
    while (continuerAdresses == 1);

    Competence c;
    int continuer;
    do
    {
        cin >> c;
        p.ajouterCompetence(c);

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

// M�thode pour affecter un participant � une autre (op�rateur d'affectation)
Participant& Participant::operator=(Participant& autreParticipant)
{
    this->nci = autreParticipant.nci;
    this->nom = autreParticipant.nom;
    this->email = autreParticipant.email;
    this->numerosTelephone.clear();
    for (list<string>::const_iterator it = autreParticipant.numerosTelephone.begin(); it != autreParticipant.numerosTelephone.end(); ++it) {
        this->numerosTelephone.push_back(*it);
    }
    this->adresses.clear();
    for (list<string>::const_iterator it = autreParticipant.adresses.begin(); it != autreParticipant.adresses.end(); ++it) {
        this->adresses.push_back(*it);
    }
    this->competences.clear();
    map<string, string>::iterator it;
    for (it = autreParticipant.competences.begin(); it != autreParticipant.competences.end(); ++it)
    {
        this->competences[it->first] = it->second;
    }
    return *this;
};

// M�thode pour afficher les details d'un participant
void Participant::afficherDetails()
{
    cout << "D�tails du participant :" << endl;
    Personne::afficherDetails();
    cout << "Competences du participant: " << endl;
    map<string, string>::iterator it;
    for (it = this->competences.begin(); it != this->competences.end(); ++it)
    {
        cout << "Nom de la competence: " << it->first << ", Description de la competence: " << it->second << endl;
    }
};

// Surcharge des op�rateurs de comparaison

// Surcharge de l'op�rateur <
bool Participant::operator<(Participant& autreParticipant)
{
    return this->competences.size() < autreParticipant.competences.size();
};

// Surcharge de l'op�rateur >
bool Participant::operator>(Participant& autreParticipant)
{
    return this->competences.size() > autreParticipant.competences.size();
};

// Surcharge de l'op�rateur <=
bool Participant::operator<=(Participant& autreParticipant)
{
    return this->competences.size() <= autreParticipant.competences.size();
};

// Surcharge de l'op�rateur >=
bool Participant::operator>=(Participant& autreParticipant)
{
    return this->competences.size() >= autreParticipant.competences.size();
};

