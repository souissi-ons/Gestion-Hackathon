#ifndef TECHNOLOGIE_H
#define TECHNOLOGIE_H

#include <string>;

using namespace std;

class Technologie{
private:
    string nom;
public:
    Technologie();
    Technologie(string);
    string getNom();
    void setNom(string);
    friend ostream& operator << (ostream&, Technologie&);
    friend istream& operator >> (istream&, Technologie&);
    friend ostream& operator << (ostream&, Technologie*);
    friend istream& operator >> (istream&, Technologie*);
};

#endif
