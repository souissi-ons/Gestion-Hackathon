#include "Date.h";
using namespace std;

Date::Date() {};

Date::Date(int jour, int mois, int annee)
{
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
};

int Date::getJour()
{
    return jour;
};

void Date::setJour(int jour)
{
    this->jour = jour;
};

int Date::getMois()
{
    return mois;
};

void Date::setMois(int mois)
{
    this->mois = mois;
};

int Date::getAnnee()
{
    return annee;
};

void Date::setAnnee(int annee)
{
    this->annee = annee;
};

Date Date::dateActuelle()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);
    jour = localTime->tm_mday;
    mois = localTime->tm_mon + 1;
    annee = localTime->tm_year + 1900;
    Date d(jour, mois, annee);
    return d;
};

ostream& operator<<(ostream& out, Date& d)
{
    out << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee();
    return out;
};

istream& operator>>(istream& in, Date& d)
{
    do
    {
        cout << "Donner l'annee : ";
        in >> d.annee;
    }
    while (d.annee < 0);

    do
    {
        cout << "Donner le mois : ";
        in >> d.mois;
    }
    while (d.mois < 1 || d.mois > 12);

    do
    {
        cout << "Donner le jour : ";
        in >> d.jour;
    }
    while ((d.jour < 1) ||
            (d.mois == 4 || d.mois == 6 || d.mois == 9 || d.mois == 11) && (d.jour > 30) ||
            (d.mois == 2 && (d.annee % 4 == 0 && (d.annee % 100 != 0 || d.annee % 400 == 0))) && (d.jour > 29) ||
            (d.mois == 2 && (d.annee % 4 != 0 || (d.annee % 100 == 0 && d.annee % 400 != 0))) && (d.jour > 28) ||
            (d.mois != 2 && d.jour > 31));

    return in;
};

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

bool Date::operator==(Date& autreDate) {
    return (this->annee == autreDate.annee &&
            this->mois == autreDate.mois &&
            this->jour == autreDate.jour);
};

bool Date::operator>=(Date& autreDate)
{
    return !(*this < autreDate);
};

bool Date::operator<=(Date& autreDate)
{
    return !(*this > autreDate);
};
