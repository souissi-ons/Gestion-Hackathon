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
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;
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
bool Participant::rechercherCompetence(string nomCompetence)
{
    for (const auto& it : this->competences)
    {
        if (it.first == nomCompetence)
        {
            return true; // La comp�tence existe d�j�
        }
    }
    return false; // La comp�tence n'existe pas encore
};

// M�thode pour ajouter une comp�tence  dans le map des comp�tences
void Participant::ajouterCompetence(Competence& competence)
{
    string nom = competence.getNom();
    if (!this->rechercherCompetence(nom))
    {
        this->competences[nom] = competence.getDescription();
    }
    else
    {
        cout << "La comp�tence avec ce nom existe d�j�." << endl;
    }
}


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
    in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le caract�re de retour � la ligne

    cout << "Entrez le nom du participant : ";
    getline(in>> ws, p.nom);

    cout << "Entrez l'email du participant : ";
    getline(in, p.email);

    int continuerNumeros;
    do
    {
        string numero;
        cout << "Entrez un num�ro de t�l�phone : ";
        getline(in >> ws, numero);
        p.ajouterNumeroTelephone(numero);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre num�ro de t�l�phone sinon 0: ";
            in >> continuerNumeros;
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le caract�re de retour � la ligne
        }
        while (continuerNumeros != 0 && continuerNumeros != 1);
    }
    while (continuerNumeros == 1);

    int continuerAdresses;
    do
    {
        string adresse;
        cout << "Entrez une adresse : ";
        getline(in >> ws, adresse);
        p.ajouterAdresse(adresse);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            in >> continuerAdresses;
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le caract�re de retour � la ligne
        }
        while (continuerAdresses != 0 && continuerAdresses != 1);
    }
    while (continuerAdresses == 1);

    Competence c;
    int continuer;
    do
    {
        in >> c;
        p.ajouterCompetence(c);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre competence sinon 0: ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le caract�re de retour � la ligne

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

