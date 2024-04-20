#include <string>;
#include <iostream>;
#include "Juge.h";
#include <limits>
using namespace std;

Juge::Juge() {};

Juge::Juge(int nci, string nom, string email, string expertise): Personne(nci, nom, email)
{
    this->expertise = expertise;
};

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

Juge::~Juge()
{
    for (Specialisation* spec : specialisations)
    {
        delete spec;
    }
}

string Juge::getExpertise()
{
    return this->expertise;
};

void Juge::setExpertise(string expertise)
{
    this->expertise = expertise;
};

vector<Specialisation*> Juge::getSpecialisations()
{
    return this->specialisations;
};

void Juge::setSpecialisations(vector<Specialisation*> specialisations)
{
    this->specialisations = specialisations;
};

void Juge::ajouterSpecialisation(Specialisation* specialisation)
{
    specialisations.push_back(specialisation);
};

void Juge::afficherSpecialisations()
{
    cout << "Specialisations du membre jury " << getNom() << ":" << endl;
    for (const auto& spec : specialisations)
    {
        cout << *spec << endl;
    }
};

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
}

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

ostream& operator<<(ostream& out, Juge& juge)
{
    out << "NCI: " << juge.getNci() << ", Nom: " << juge.getNom() << ", Email: " << juge.getEmail() << ", Expertise: " << juge.expertise << endl;
    out << "Specialisations du membre jury:" << endl;
        out << "Numeros de telephone du membre jury: ";
    list<string>::iterator itNumeros;
    for (itNumeros = juge.numerosTelephone.begin(); itNumeros != juge.numerosTelephone.end(); ++itNumeros) {
        out << *itNumeros << ", ";
    }
    out << endl;
    out << "Adresses du membre jury: ";
    list<string>::iterator itAdresses;
    for (itAdresses = juge.adresses.begin(); itAdresses != juge.adresses.end(); ++itAdresses) {
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

istream& operator>>(istream& in, Juge& juge)
{
    cout << "Entrez le num�ro de carte identit� du membre jury : ";
    in >> juge.nci;
    cout << "Entrez le nom du membre jury : ";
    getline(in, juge.nom);
    in.ignore();
    cout << "Entrez l'email du membre jury : ";
    getline(in, juge.email);
    in.ignore();
    cout << "Entrez l'expertise du membre jury : ";
    getline(in, juge.expertise);
    in.ignore();
    int continuerNumeros;
    do
    {
        string numero;
        cout << "Entrez un num�ro de t�l�phone : ";
        getline(cin, numero);
        in.ignore();
        juge.ajouterNumeroTelephone(numero);
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
        juge.ajouterAdresse(adresse);

        do
        {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            cin >> continuerAdresses;
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
        }
        while (continuer != 0 && continuer != 1);
    }
    while (continuer == 1);

    return in;
};

Juge& Juge::operator=(const Juge& autreJuge)
{
    if (this != &autreJuge)
    {
        this->nci = autreJuge.nci;
        this->nom = autreJuge.nom;
        this->email = autreJuge.email;
        this->expertise = autreJuge.expertise;
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

