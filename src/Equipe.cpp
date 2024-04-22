#include <string>;
#include <vector>;
#include <iostream>;
#include <fstream>;
#include "Equipe.h";
#include "Projet.h";
#include <limits>
#include <algorithm>

using namespace std;

// Constructeurs

// Constructeur par d�faut
Equipe::Equipe() {};

// Constructeur par recopie
Equipe::Equipe(const Equipe& e)
{
    this->nom = e.nom;
    this->dateCreation = e.dateCreation;
    Participant *p;
    for (int i=0; i<e.participants.size(); i++)
    {
        p=new Participant(*e.participants[i]);
        this->participants.push_back(p);    }
};

// Desctructeur
Equipe::~Equipe()
{
    for (int i=0; i<this->participants.size(); i++)
    {
        delete this->participants[i];
    }
};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le nom
string Equipe::getNom()
{
    return this->nom;
};

// M�thode pour modifier le nom
void Equipe::setNom(string nom)
{
    this->nom = nom;
};

// M�thode pour obtenir la date de cr�ation
Date Equipe::getDateCreation()
{
    return this->dateCreation;
};

// M�thode pour modifier la date de cr�ation
void Equipe::setDateCreation(Date dateCreation)
{
    this->dateCreation = dateCreation;
};

// M�thode pour obtenir le vector des participants
vector<Participant*> Equipe::getParticipants()
{
    return participants;
};

// M�thode pour modifier le vector des participants
void Equipe::setParticipants(vector<Participant*> participants)
{
    this->participants = participants;
};

// M�thode pour ajouter un participant dans le vector des participants
void Equipe::ajouterParticipant(Participant* participant)
{
    this->participants.push_back(participant);
};

// M�thode pour rechercher un participant dans le vector des participants par son num�ro de carte d'identit� nationale (NCI)
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

// M�thode pour supprimer un participant dans le vector des participants par son num�ro de carte d'identit� nationale (NCI)
void Equipe::supprimerParticipant(int nci)
{
    int p = rechercherParticipant(nci);
    if (p!= -1)
    {
        this->participants.erase(participants.begin() + p);
    }
    int nb = (Participant::getNombreParticipants()) -1;
    Participant::setNombreParticipants(nb);
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations de l'�quipe
ostream& operator<<(ostream& out, Equipe& e)
{
    out << "Nom de l'�quipe: " << e.nom << ", Date de cr�ation de l'�quipe: " << e.dateCreation << endl;
    out << "Participants de l'equipe: " << endl;
    for (int i = 0; i < e.participants.size(); ++i)
    {
        out << "Participant " << i+1 << ": " << endl;
        out << *(e.participants[i]);
    }
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations de l'�quipe
istream& operator>>(istream& in, Equipe& e)
{
    cout << "Entrez le nom de l'�quipe : ";
    getline(in >> ws, e.nom);
    cout << "Entrez la date de cr�ation de l'�quipe : ";
    in >> e.dateCreation;
    int continuer;
    do
    {
        Participant* p = new Participant();
        in >> *p;
        e.participants.push_back(p);
        cout << "Veuillez saisir 1 si vous voulez ajouter un autre participant sinon 0: ";
        in >> continuer;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (continuer == 1);
    return in;
};

// Surcharge de l'op�rateur << pour afficher les informations de l'�quipe*
ostream& operator<<(ostream& out, Equipe* e)
{
    out << "Nom de l'�quipe: " << e->nom << ", Date de cr�ation de l'�quipe: " << e->dateCreation << endl;
    out << "Participants de l'equipe: " << endl;
    for (int i = 0; i < e->participants.size(); ++i)
    {
        out << "Participant " << i+1 << ": " << *(e->participants[i]);
    }
    return out;
}

// Surcharge de l'op�rateur >> pour saisir les informations de l'�quipe*
istream& operator>>(istream& in, Equipe* e)
{
    cout << "Entrez le nom de l'�quipe : ";
    getline(in >> ws, e->nom);
    cout << "Entrez la date de cr�ation de l'�quipe : ";
    in >> e->dateCreation;
    int continuer;
    do
    {
        Participant* p = new Participant();
        in >> *p;
        e->participants.push_back(p);
        cout << "Veuillez saisir 1 si vous voulez ajouter un autre participant sinon 0: ";
        in >> continuer;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (continuer == 1);
    return in;
};

// M�thode pour affecter une �quipe � une autre (op�rateur d'affectation)
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

// M�thode pour ajouter les informations de l'�quipe dans un fichier
void Equipe::ajouterEquipeDansFichier(const string& nomFichier)
{
    try
    {
        ofstream fichier(nomFichier, ios::app); // Ouvrir le fichier en mode append (ajout) pour ne pas �craser le contenu existant
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // �crire les informations de l'�quipe dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier apr�s �criture
        cout << "Equipe ajout�e avec succ�s dans le fichier." << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour cr�er un fichier contenant les informations de l'�quipe
void Equipe::creerFichierEquipe()
{
    if (this->nom.empty()) // V�rifier si le nom de l'�quipe est vide
    {
        cerr << "Erreur : Le nom de l'equipe est vide." << endl;
        return;
    }
    string nomFichier = "fichier/" +this->nom + ".txt"; // Nom du fichier avec le nom de l'�quipe
    try
    {
        ofstream fichier(nomFichier); // Cr�er un nouveau fichier

        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // �crire les informations de l'�quipe dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier apr�s �criture
        cout << "Fichier equipe cr�� avec succ�s : " << nomFichier << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour afficher le fichier contenant les informations de l'�quipe
void Equipe::afficherEquipesDeFichier(const string& nomFichier)
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
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'�chec
    }
};

// M�thode pour trouver le participant avec le plus de comp�tences dans l'�quipe
Participant* Equipe::participantAvecPlusDeCompetences()
{
    if (participants.empty()) // V�rifier si l'�quipe n'a pas de participants
    {
        return nullptr;
    }
    // Trier les participants en pour comparer le nombre de comp�tences
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b)
    {
        return *a > *b; // Utiliser l'op�rateur > de la classe Participant pour la comparaison
    });
    return participants[0];
};

// M�thode pour trier les participants par nom dans l'�quipe
void Equipe::trierParticipantsParNom()
{
    // Trie les participants pour comparer les noms
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b) {
        return a->getNom() < b->getNom(); // Utiliser la m�thode getNom() de la classe Participant pour la comparaison
    });
};

// M�thode pour trier les participants par num�ro de carte d'identit� nationale (NCI) dans l'�quipe
void Equipe::trierParticipantsParNci()
{
    // Trier les participants pour comparer les NCI des participants
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b) {
        return a->getNci() < b->getNci(); // Utiliser la m�thode getNci() de la classe Participant pour la comparaison
    });
};

// M�thode pour afficher la liste des participants dans l'�quipe
void Equipe::afficherParticipants()
{
    if (participants.empty()) // V�rifier si l'�quipe n'a pas de participants
    {
        cout << "Aucun participant dans cette �quipe." << endl;
        return;
    }
    cout << "Liste des participants de l'�quipe :" << endl;
    for (const auto& participant : participants) // Parcourt tous les participants de l'�quipe
    {
        cout << *participant << endl; // Afficher chaque participant en utilisant l'op�rateur << de la classe Participant
    }
};
