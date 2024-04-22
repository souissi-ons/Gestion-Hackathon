#include "Date.h";

using namespace std;

// Constructeurs

// Constructeur par défaut
Date::Date() {};

// Constructeur avec paramètres
Date::Date(int jour, int mois, int annee)
{
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour obtenir le jour
int Date::getJour()
{
    return jour;
};

// Méthode pour modifier le jour
void Date::setJour(int jour)
{
    this->jour = jour;
};

// Méthode pour obtenir le mois
int Date::getMois()
{
    return mois;
};

// Méthode pour modifier le mois
void Date::setMois(int mois)
{
    this->mois = mois;
};

// Méthode pour obtenir l'année
int Date::getAnnee()
{
    return annee;
};

// Méthode pour modifier l'année
void Date::setAnnee(int annee)
{
    this->annee = annee;
};

// Méthode pour obtenir la date actuelle
Date Date::dateActuelle()
{
    auto now = chrono::system_clock::now(); // Obtient le temps actuel depuis l'horloge système
    time_t currentTime = chrono::system_clock::to_time_t(now); // Convertit le temps en un format pouvant être utilisé
    tm* localTime = localtime(&currentTime); // Convertit le temps en une structure tm pour obtenir les éléments de la date
    // Extraire les composants de la date de la structure tm
    jour = localTime->tm_mday; // Jour du mois (1 à 31)
    mois = localTime->tm_mon + 1; // Mois de l'année (0 à 11, donc on ajoute 1 pour avoir 1 à 12)
    annee = localTime->tm_year + 1900; // Année depuis 1900, donc on ajoute 1900 pour obtenir l'année actuelle
    // Créer un objet Date avec la date actuelle obtenue
    Date d(jour, mois, annee);
    return d;
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations de date
ostream& operator<<(ostream& out, Date& d)
{
    out << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee();
    return out;
};

// Surcharge de l'opérateur >> pour saisir les informations de date
istream& operator>>(istream& in, Date& d)
{
    do
    {
        cout << "Donner l'annee : ";
        in >> d.annee;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (d.annee < 0);

    do
    {
        cout << "Donner le mois : ";
        in >> d.mois;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (d.mois < 1 || d.mois > 12);

    do
    {
        cout << "Donner le jour : ";
        in >> d.jour;
        in.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    while ((d.jour < 1) ||
            (d.mois == 4 || d.mois == 6 || d.mois == 9 || d.mois == 11) && (d.jour > 30) ||
            (d.mois == 2 && (d.annee % 4 == 0 && (d.annee % 100 != 0 || d.annee % 400 == 0))) && (d.jour > 29) ||
            (d.mois == 2 && (d.annee % 4 != 0 || (d.annee % 100 == 0 && d.annee % 400 != 0))) && (d.jour > 28) ||
            (d.mois != 2 && d.jour > 31));

    return in;
};

// Surcharge des opérateurs de comparaison

// Surcharge de l'opérateur <
bool Date::operator<(Date& autreDate)
{
    if (this->annee < autreDate.annee)
    {
        return true;
    }
    else if (this->annee == autreDate.annee)
    {
        if (this->mois < autreDate.mois)
        {
            return true;
        }
        else if (this->mois == autreDate.mois)
        {
            return this->jour < autreDate.jour;
        }
    }
    return false;
};

// Surcharge de l'opérateur >
bool Date::operator>(Date& autreDate)
{
    if (this->annee > autreDate.annee)
    {
        return true;
    }
    else if (this->annee == autreDate.annee)
    {
        if (this->mois > autreDate.mois)
        {
            return true;
        }
        else if (this->mois == autreDate.mois)
        {
            return this->jour > autreDate.jour;
        }
    }
    return false;
};

// Surcharge de l'opérateur ==
bool Date::operator==(Date& autreDate) {
    return (this->annee == autreDate.annee &&
            this->mois == autreDate.mois &&
            this->jour == autreDate.jour);
};

// Surcharge de l'opérateur >=
bool Date::operator>=(Date& autreDate)
{
    return !(*this < autreDate);
};

// Surcharge de l'opérateur <=
bool Date::operator<=(Date& autreDate)
{
    return !(*this > autreDate);
};
