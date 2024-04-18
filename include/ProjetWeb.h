#ifndef WEB_H
#define WEB_H

#include <list>;
#include "Projet.h";
#include "Technologie.h"

class ProjetWeb : public Projet
{
private:
    list <Technologie *> technologies;
public:
    ProjetWeb();
    ProjetWeb(const ProjetWeb&);
    ~ProjetWeb()override;
    list <Technologie *> getTechnologies();
    void setTechnologies(list <Technologie *>);
    void ajouterTechnologie(Technologie*);
    Technologie* rechercherTechnologie(string);
    void supprimerTechnologie(string);
    friend ostream& operator << (ostream&, ProjetWeb&);
    friend istream& operator >> (istream&, ProjetWeb&);
    ProjetWeb& operator=(const ProjetWeb&);
    void afficherDetails();

};

#endif
