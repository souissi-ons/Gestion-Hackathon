#ifndef Gagnant_H
#define Gagnant_H

#include <string>
#include "Projet.h"

using namespace std;

class Gagnant
{
private:
    int rang;
    Projet* projet;
    string recompense;
    float score;
public:
    Gagnant();
    Gagnant(int, string, float);
    Gagnant(const Gagnant&);
    ~Gagnant();
    int getRang();
    void setProjet(Projet*);
    Projet* getProjet();
    void setRang(int);
    string getRecompense();
    void setRecompense(string);
    float getScore();
    void setScore(float);
    friend ostream& operator << (ostream&, Gagnant&);
    friend istream& operator >> (istream&, Gagnant&);
    Gagnant& operator=(const Gagnant&);
};

#endif

