#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Organisateur.h";
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Organisateur::Organisateur() {};

// Constructeur avec paramètres
Organisateur::Organisateur(int nci, string nom, string email, string role): Personne(nci, nom, email)
{
    this->role = role;
};

// Desctructeur
Organisateur::~Organisateur(){}

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le role
string Organisateur::getRole()
{
    return this->role;
};

// Méthode pour modifier le role
void Organisateur::setRole(string role)
{
    this->role = role;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations d'un organisateur
ostream& operator<<(ostream& out, Organisateur& o) {
    out << "Cin de l'organisateur: " << o.nci <<  ", Nom de l'organisateur: " << o.nom << ", Email de l'organisateur: " << o.email << ", Role de l'organisateur: " << o.role << endl;
        out << "Numeros de telephone de l'organisateur: ";
    list<string>::iterator itNumeros;
    for (itNumeros = o.numerosTelephone.begin(); itNumeros != o.numerosTelephone.end(); ++itNumeros) {
        out << *itNumeros << ", ";
    }
    out << endl;
    out << "Adresses de l'organisateur: ";
    list<string>::iterator itAdresses;
    for (itAdresses = o.adresses.begin(); itAdresses != o.adresses.end(); ++itAdresses) {
        out << *itAdresses << ", ";
    }
    out << endl;
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations d'un organisateur
istream& operator>>(istream& in, Organisateur& o) {
    cout << "Entrez le NCI de l'organisateur : ";
    in >> o.nci;
    cout << "Entrez le nom de l'organisateur : ";
    getline(in, o.nom);
    in.ignore();
    cout << "Entrez l'email de l'organisateur : ";
    getline(in, o.email);
    in.ignore();
        int continuerNumeros;
    do {
        string numero;
        cout << "Entrez un numéro de téléphone : ";
        getline(cin, numero);
        in.ignore();
        o.ajouterNumeroTelephone(numero);

        do {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre numéro de téléphone sinon 0: ";
            cin >> continuerNumeros;
        } while (continuerNumeros != 0 && continuerNumeros != 1);
    } while (continuerNumeros == 1);

    int continuerAdresses;
    do {
        string adresse;
        cout << "Entrez une adresse : ";
        getline(cin, adresse);
        in.ignore();
        o.ajouterAdresse(adresse);

        do {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            cin >> continuerAdresses;
        } while (continuerAdresses != 0 && continuerAdresses != 1);
    } while (continuerAdresses == 1);
    cout << "Entrez le role de l'organisateur :" ;
    getline(in, o.role);
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
};

// Méthode pour afficher les details d'un organisateur
void Organisateur::afficherDetails() {
    cout << "Détails de l'organisateur :" << endl;
    Personne::afficherDetails();
    cout << "Role : " << this->role << endl;
};

