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

// Constructeur par défaut
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

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le nom
string Equipe::getNom()
{
    return this->nom;
};

// Méthode pour modifier le nom
void Equipe::setNom(string nom)
{
    this->nom = nom;
};

// Méthode pour obtenir la date de création
Date Equipe::getDateCreation()
{
    return this->dateCreation;
};

// Méthode pour modifier la date de création
void Equipe::setDateCreation(Date dateCreation)
{
    this->dateCreation = dateCreation;
};

// Méthode pour obtenir le vector des participants
vector<Participant*> Equipe::getParticipants()
{
    return participants;
};

// Méthode pour modifier le vector des participants
void Equipe::setParticipants(vector<Participant*> participants)
{
    this->participants = participants;
};

// Méthode pour ajouter un participant dans le vector des participants
void Equipe::ajouterParticipant(Participant* participant)
{
    this->participants.push_back(participant);
};

// Méthode pour rechercher un participant dans le vector des participants par son numéro de carte d'identité nationale (NCI)
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

// Méthode pour supprimer un participant dans le vector des participants par son numéro de carte d'identité nationale (NCI)
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

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations de l'équipe
ostream& operator<<(ostream& out, Equipe& e)
{
    out << "Nom de l'équipe: " << e.nom << ", Date de création de l'équipe: " << e.dateCreation << endl;
    out << "Participants de l'equipe: " << endl;
    for (int i = 0; i < e.participants.size(); ++i)
    {
        out << "Participant " << i+1 << ": " << endl;
        out << *(e.participants[i]);
    }
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations de l'équipe
istream& operator>>(istream& in, Equipe& e)
{
    cout << "Entrez le nom de l'équipe : ";
    getline(in >> ws, e.nom);
    cout << "Entrez la date de création de l'équipe : ";
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

// Surcharge de l'opérateur << pour afficher les informations de l'équipe*
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

// Surcharge de l'opérateur >> pour saisir les informations de l'équipe*
istream& operator>>(istream& in, Equipe* e)
{
    cout << "Entrez le nom de l'équipe : ";
    getline(in >> ws, e->nom);
    cout << "Entrez la date de création de l'équipe : ";
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

// Méthode pour affecter une équipe à une autre (opérateur d'affectation)
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

// Méthode pour ajouter les informations de l'équipe dans un fichier
void Equipe::ajouterEquipeDansFichier(const string& nomFichier)
{
    try
    {
        ofstream fichier(nomFichier, ios::app); // Ouvrir le fichier en mode append (ajout) pour ne pas écraser le contenu existant
        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // Écrire les informations de l'équipe dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier après écriture
        cout << "Equipe ajoutée avec succès dans le fichier." << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour créer un fichier contenant les informations de l'équipe
void Equipe::creerFichierEquipe()
{
    if (this->nom.empty()) // Vérifier si le nom de l'équipe est vide
    {
        cerr << "Erreur : Le nom de l'equipe est vide." << endl;
        return;
    }
    string nomFichier = "fichier/" +this->nom + ".txt"; // Nom du fichier avec le nom de l'équipe
    try
    {
        ofstream fichier(nomFichier); // Créer un nouveau fichier

        if (!fichier.is_open())
        {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }
        fichier << *this; // Écrire les informations de l'équipe dans le fichier
        fichier << endl;
        fichier << endl;
        fichier.close(); // Fermer le fichier après écriture
        cout << "Fichier equipe créé avec succès : " << nomFichier << endl;
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour afficher le fichier contenant les informations de l'équipe
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
        fichier.close(); // Fermer le fichier après lecture
    }
    catch (const exception& e)
    {
        cerr << "Erreur : " << e.what() << endl; // Afficher un message d'erreur en cas d'échec
    }
};

// Méthode pour trouver le participant avec le plus de compétences dans l'équipe
Participant* Equipe::participantAvecPlusDeCompetences()
{
    if (participants.empty()) // Vérifier si l'équipe n'a pas de participants
    {
        return nullptr;
    }
    // Trier les participants en pour comparer le nombre de compétences
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b)
    {
        return *a > *b; // Utiliser l'opérateur > de la classe Participant pour la comparaison
    });
    return participants[0];
};

// Méthode pour trier les participants par nom dans l'équipe
void Equipe::trierParticipantsParNom()
{
    // Trie les participants pour comparer les noms
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b) {
        return a->getNom() < b->getNom(); // Utiliser la méthode getNom() de la classe Participant pour la comparaison
    });
};

// Méthode pour trier les participants par numéro de carte d'identité nationale (NCI) dans l'équipe
void Equipe::trierParticipantsParNci()
{
    // Trier les participants pour comparer les NCI des participants
    sort(participants.begin(), participants.end(), [](Participant* a, Participant* b) {
        return a->getNci() < b->getNci(); // Utiliser la méthode getNci() de la classe Participant pour la comparaison
    });
};

// Méthode pour afficher la liste des participants dans l'équipe
void Equipe::afficherParticipants()
{
    if (participants.empty()) // Vérifier si l'équipe n'a pas de participants
    {
        cout << "Aucun participant dans cette équipe." << endl;
        return;
    }
    cout << "Liste des participants de l'équipe :" << endl;
    for (const auto& participant : participants) // Parcourt tous les participants de l'équipe
    {
        cout << *participant << endl; // Afficher chaque participant en utilisant l'opérateur << de la classe Participant
    }
};
