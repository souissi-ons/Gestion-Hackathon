#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Organisateur.h";
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par d�faut
Organisateur::Organisateur() {};

// Constructeur avec param�tres
Organisateur::Organisateur(int nci, string nom, string email, string role): Personne(nci, nom, email)
{
    this->role = role;
};

// Desctructeur
Organisateur::~Organisateur(){}

// M�thodes pour acc�der et modifier les membres priv�s

// M�thode pour obtenir le role
string Organisateur::getRole()
{
    return this->role;
};

// M�thode pour modifier le role
void Organisateur::setRole(string role)
{
    this->role = role;
};

// Surcharge des op�rateurs pour l'entr�e/sortie

// Surcharge de l'op�rateur << pour afficher les informations d'un organisateur
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

// Surcharge de l'op�rateur >> pour saisir les informations d'un organisateur
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
        cout << "Entrez un num�ro de t�l�phone : ";
        getline(cin, numero);
        in.ignore();
        o.ajouterNumeroTelephone(numero);

        do {
            cout << "Veuillez saisir 1 si vous voulez ajouter un autre num�ro de t�l�phone sinon 0: ";
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

// M�thode pour afficher les details d'un organisateur
void Organisateur::afficherDetails() {
    cout << "D�tails de l'organisateur :" << endl;
    Personne::afficherDetails();
    cout << "Role : " << this->role << endl;
};

