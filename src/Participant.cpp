#include <string>;
#include <map>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include "Participant.h";
#include <limits>
using namespace std;

int Participant::nombreParticipants = 0;

Participant::Participant() {
    Participant::nombreParticipants++;
};

Participant::Participant(const Participant& p) {
    Participant::nombreParticipants++;
    this->nci = p.nci;
    this->nom = p.nom;
    this->email = p.email;

    map<string, string>::const_iterator it;

    for (it = p.competences.begin(); it != p.competences.end(); ++it) {
        this->competences[it->first] = it->second;
    }
}

Participant::~Participant() {}


map<string, string> Participant::getCompetences() {
    return this->competences;
};

void Participant::setCompetences(const map<string, string>& competences) {
    this->competences = competences;
};

int Participant::getNombreParticipants()
{
    return Participant::nombreParticipants;
};

void Participant::setNombreParticipants(int nb)
{
    Participant::nombreParticipants = nb;
};

int Participant::rechercherCompetence(const string& nomCompetence) {
    map<string, string>::iterator it;
    for (it = this->competences.begin(); it != this->competences.end(); ++it) {
        if (it->first == nomCompetence) {
            return distance(this->competences.begin(), it);
        }
    }
    return -1;
};

void Participant::ajouterCompetence(Competence& competence)  {
    if (this->competences.find(competence.getNom()) == this->competences.end()) {
        this->competences[competence.getNom()] = competence.getDescription();
    } else {
        cout << "La competence avec le nom '" << competence.getNom() << "' existe deja." << endl;
    }
};

void Participant::supprimerCompetence(const string& nomCompetence) {
    this->competences.erase(nomCompetence);
};

ostream& operator<<(ostream& out, Participant& p) {
    out << "Cin du participant: " << p.getNci() << ", Nom du participant: " << p.getNom() << ", Email du participant: " << p.getEmail() << endl;
    out << "Numeros de telephone du participant: ";
    list<string>::iterator itNumeros;
    for (itNumeros = p.numerosTelephone.begin(); itNumeros != p.numerosTelephone.end(); ++itNumeros) {
        out << *itNumeros << ", ";
    }
    out << endl;
    out << "Adresses du participant: ";
    list<string>::iterator itAdresses;
    for (itAdresses = p.adresses.begin(); itAdresses != p.adresses.end(); ++itAdresses) {
        out << *itAdresses << ", ";
    }
    out << endl;
    out << "Competences du participant: " << endl;
    map<string, string>::iterator it;
    for (it = p.competences.begin(); it != p.competences.end(); ++it) {
        out << "Nom de la competence: " << it->first << ", Description de la competence: " << it->second << endl;
    }
    return out;
};

istream& operator>>(istream& in, Participant& p) {
    cout << "Entrez le NCI du participant : ";
    in >> p.nci;
    cout << "Entrez le nom du participant : ";
    getline(in, p.nom);
    in.ignore();
    cout << "Entrez l'email du participant : ";
    getline(in, p.email);
    in.ignore();
    int continuerNumeros;
    do {
        string numero;
        cout << "Entrez un numéro de téléphone : ";
        getline(cin, numero);
        in.ignore();
        p.ajouterNumeroTelephone(numero);

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
        p.ajouterAdresse(adresse);

        do {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre adresse sinon 0: ";
            cin >> continuerAdresses;
        } while (continuerAdresses != 0 && continuerAdresses != 1);
    } while (continuerAdresses == 1);

    Competence c;
    int continuer;
    do {
        cin >> c;
        p.ajouterCompetence(c);

        do {
            cout << "Veuillez saisir 1 si vous voulez ajouter une autre competence sinon 0: ";
            in >> continuer;
        } while (continuer != 0 && continuer != 1);
    } while (continuer == 1);

    return in;
};

Participant& Participant::operator=(Participant& autreParticipant) {
    this->nci = autreParticipant.nci;
    this->nom = autreParticipant.nom;
    this->email = autreParticipant.email;
    this->competences.clear();
    map<string, string>::iterator it;
    for (it = autreParticipant.competences.begin(); it != autreParticipant.competences.end(); ++it) {
        this->competences[it->first] = it->second;
    }
    return *this;
}

void Participant::afficherDetails() {
    cout << "Détails du participant :" << endl;
    Personne::afficherDetails();
    cout << "Competences du participant: " << endl;
    map<string, string>::iterator it;
    for (it = this->competences.begin(); it != this->competences.end(); ++it) {
        cout << "Nom de la competence: " << it->first << ", Description de la competence: " << it->second << endl;
    }
}

bool Participant::operator<(Participant& autreParticipant) {
    return this->competences.size() < autreParticipant.competences.size();
}

bool Participant::operator>(Participant& autreParticipant) {
    return this->competences.size() > autreParticipant.competences.size();
}

bool Participant::operator<=(Participant& autreParticipant) {
    return this->competences.size() <= autreParticipant.competences.size();
}

bool Participant::operator>=(Participant& autreParticipant) {
    return this->competences.size() >= autreParticipant.competences.size();
}

