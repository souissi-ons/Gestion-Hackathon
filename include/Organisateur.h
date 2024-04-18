#ifndef ORGANISATEUR_H
#define ORGANISATEUR_H

#include <string>;
#include "Personne.h";
using namespace std;

 class Organisateur : public Personne{
 private:
      string role;
 public:
    Organisateur();
    Organisateur(int, string, string, string);
    ~Organisateur();
    string getRole();
    void setRole(string);
    friend ostream& operator << (ostream&, Organisateur&);
    friend istream& operator >> (istream&, Organisateur&);
    void afficherDetails();
 };

 #endif

