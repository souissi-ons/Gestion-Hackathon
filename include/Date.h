#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
using namespace std;

class Date
{
private:
    int jour;
    int mois;
    int annee;

public:
    Date();
    Date(int, int, int);
    int getJour();
    void setJour(int);
    int getMois();
    void setMois(int);
    int getAnnee();
    void setAnnee(int);
    Date dateActuelle();
    friend ostream& operator << (ostream&, Date&);
    friend istream& operator >> (istream&, Date&);
    bool operator<(Date&);
    bool operator>(Date&);
    bool operator==(Date&);
    bool operator>=(Date&);
    bool operator<=(Date&);


};

#endif
