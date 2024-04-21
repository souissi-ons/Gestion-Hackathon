#ifndef EMBARQUE_H
#define EMBARQUE_H
#include <list>;
#include "Projet.h";
#include "Materiel.h";

using namespace std;

class ProjetEmbarque : public Projet
{
private:
    list <Materiel *> materiels;
public:
    ProjetEmbarque();
    ProjetEmbarque(const ProjetEmbarque&);
    ~ProjetEmbarque()override;
    list <Materiel *> getMateriels();
    void setMateriels(list <Materiel *>);
    void ajouterMateriel(Materiel*);
    Materiel* rechercherMateriel(string);
    void supprimerMateriel(string);
    friend ostream& operator << (ostream&, ProjetEmbarque&);
    friend istream& operator >> (istream&, ProjetEmbarque&);
    ProjetEmbarque& operator=(const ProjetEmbarque&);
    bool operator>(ProjetEmbarque&);
    bool operator<(ProjetEmbarque&);
    bool operator>=(ProjetEmbarque&);
    bool operator<=(ProjetEmbarque&);
    void afficherDetails()override;

};

#endif

