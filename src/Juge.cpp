#include <string>;
#include <iostream>;
#include "Juge.h";
#include <limits>
using namespace std;

// Constructeurs

// Constructeur par d�faut
Juge::Juge() {};

// Constructeur avec param�tres
Juge::Juge(int nci, string nom, string email, string expertise): Personne(nci, nom, email)
{
    this->expertise = expertise;
};

// Constructeur par recopie
Juge::Juge(const Juge& autreJuge)
{
    this->nci = autreJuge.nci;
    this->nom = autreJuge.nom;
    this->email = autreJuge.email;
    this->expertise = autreJuge.expertise;
    for (Specialisation* spec : autreJuge.specialisations)
    {
        this->specialisations.push_back(new Specialisation(*spec));
    }
};

// Desctructeur
Juge::~Juge()
{
    for (Specialisation* spec : this->specialisations)
    {
        delete spec;
    }
};

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir l'expertise
string Juge::getExpertise()
{
    return this->expertise;
};

// M�thode pour modifier l'expertise
void Juge::setExpertise(string expertise)
{
    this->expertise = expertise;
};

// M�thode pour obtenir le vector de specialisations
vector<Specialisation*> Juge::getSpecialisations()
{
    return this->specialisations;
};

// M�thode pour modifier le vector de specialisations
void Juge::setSpecialisations(vector<Specialisation*> specialisations)
{
    this->specialisations = specialisations;
};

// M�thode pour ajouter une specialisation dans la vector des specialisations
void Juge::ajouterSpecialisation(Specialisation* specialisation)
{
    specialisations.push_back(specialisation);
};

// M�thode pour afficher les specialisations dans la vector des specialisations
void Juge::afficherSpecialisations()
{
    cout << "Specialisations du membre jury " << getNom() << ":" << endl;
    for (const auto& spec : specialisations)
    {
        cout << *spec << endl;
    }
};

// M�thode pour rechercher une specialisation dans le vector des specialisations par son nom
Specialisation* Juge::rechercherSpecialisationParNom(string nomSpec)
{
    for (Specialisation* spec : specialisations)
    {
        if (spec->getNom() == nomSpec)
        {
            return spec;
        }
    }
    return nullptr;
};

// M�thode pour supprimer une specialisation dans le vector des specialisations par son nom
void Juge::supprimerSpecialisationParNom(string nomSpec)
{
    for (size_t i = 0; i < specialisations.size(); ++i)
    {
        if (specialisations[i]->getNom() == nomSpec)
        {
            delete specialisations[i];
            specialisations.erase(specialisations.begin() + i);
            cout << "Sp�cialisation supprim�e avec succ�s." << endl;
            return;
        }
    }
    cout << "Sp�cialisation non trouv�e." << endl;
};
// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations d'un juge
ostream& operator<<(ostream& out, Juge& juge)
{
    out << "NCI: " << juge.getNci() << ", Nom: " << juge.getNom() << ", Email: " << juge.getEmail() << ", Expertise: " << juge.expertise << endl;
    out << "Specialisations du membre jury:" << endl;
    out << "Numeros de telephone du membre jury: ";
    list<string>::iterator itNumeros;
    for (itNumeros = juge.numerosTelephone.begin(); itNumeros != juge.numerosTelephone.end(); ++itNumeros)
    {
        out << *itNumeros << ", ";
    }
    out << endl;
    out << "Adresses du membre jury: ";
    list<string>::iterator itAdresses;
    for (itAdresses = juge.adresses.begin(); itAdresses != juge.adresses.end(); ++itAdresses)
    {
        out << *itAdresses << ", ";
    }
    out << endl;
    int i = 1;
    for (auto& spec : juge.specialisations)
    {
        out << "Specialisation " << i++ << ": " << *spec << endl;
    }
    out << endl;
    return out;
};

// Surcharge de l'op�rateur >> pour saisir les informations d'un juge
istream& operator>>(istream& in, Juge& juge)
{
    cout << "Entrez le num�ro de carte identit� du membre jury : ";
    in >> juge.nci;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrez le nom du membre jury : ";
    getline(in >> ws, juge.nom);
    cout << "Entrez l'email du membre jury : ";
    getline(in >> ws, juge.email);
    cout << "Entrez l'expertise du membre jury : ";
    getline(in, juge.expertise);
    int continuerNumeros;
    do
    {
        string numero;
        cout << "Entrez un num�ro de t�l�phone : ";
        getline(in >> ws, numero);
        juge.ajouterNumeroTelephone(numero);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre num�ro de t�l�phone sinon 0: ";
            in >> continuerNumeros;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
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
        juge.ajouterAdresse(adresse);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            in >> continuerAdresses;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuerAdresses != 0 && continuerAdresses != 1);
    }
    while (continuerAdresses == 1);

    int continuer;
    do
    {
        Specialisation* specialisation = new Specialisation();
        in >> *specialisation;
        juge.specialisations.push_back(specialisation);
        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre sp�cialisation sinon 0 : ";
            in >> continuer;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);

    return in;
};
// M�thode pour affecter un juge � une autre (op�rateur d'affectation)
Juge& Juge::operator=(const Juge& autreJuge)
{
    if (this != &autreJuge)
    {
        this->nci = autreJuge.nci;
        this->nom = autreJuge.nom;
        this->email = autreJuge.email;
        this->expertise = autreJuge.expertise;
        for (list<string>::const_iterator it = autreJuge.numerosTelephone.begin(); it != autreJuge.numerosTelephone.end(); ++it)
        {
            this->numerosTelephone.push_back(*it);
        }
        for (list<string>::const_iterator it = autreJuge.adresses.begin(); it != autreJuge.adresses.end(); ++it)
        {
            this->adresses.push_back(*it);
        }
        for (Specialisation* spec : this->specialisations)
        {
            delete spec;
        }
        this->specialisations.clear();
        for (Specialisation* spec : autreJuge.specialisations)
        {
            this->ajouterSpecialisation(new Specialisation(*spec));
        }
    }
    return *this;
};

// M�thode pour afficher les details d'un juge
void Juge::afficherDetails()
{
    cout << "D�tails du membre jury :" << endl;
    Personne::afficherDetails();
    cout << "Expertise : " << this->expertise << endl;
    cout << "Specialisations du membre jury:" << endl;
    int i=0;
    for (auto& spec : this->specialisations)
    {
        cout << "Specialisation " << i++ << ": " << *spec << endl;
    }
}

