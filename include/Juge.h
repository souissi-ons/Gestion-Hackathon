#ifndef JUGE_H
#define JUGE_H

#include <string>;
#include "Personne.h";
using namespace std;

 class Juge : public Personne{
 private:
      string expertise;
 public:
    Juge();
    Juge(int, string, string, string);
    ~Juge();
    string getExpertise();
    void setExpertise(string);
    friend ostream& operator << (ostream&, Juge&);
    friend istream& operator >> (istream&, Juge&);
    void afficherDetails();
 };

 #endif
