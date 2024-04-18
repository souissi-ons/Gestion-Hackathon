#include <string>;
#include <iostream>;
#include "Projet.h";
#include <limits>
#include "Evaluation.h";
using namespace std;


Projet::Projet() {};

Projet::Projet(string titre, string description)
{
    this->titre = titre;
    this->description = description;
};

Projet::~Projet() {
    delete this->equipe;
    delete this->evaluation;
};

Projet::Projet(const Projet& p)
{
    this->titre = p.titre;
    this->description = p.description;
    this->evaluation = p.evaluation;
    this->equipe = p.equipe;
};

string Projet::getTitre()
{
    return this->titre;
};

void Projet::setTitre(string titre)
{
    this->titre = titre;
};

string Projet::getDescription()
{
    return this->description;
};

void Projet::setDescription(string description)
{
    this->description = description;
};

void Projet::setEvaluation(Evaluation* evaluation)
{
    this->evaluation = evaluation;
};

Evaluation* Projet::getEvaluation()
{
    return this->evaluation;
};

void Projet::setEquipe(Equipe* equipe)
{
    this->equipe = equipe;
};

Equipe* Projet::getEquipe()
{
    return this->equipe;
};

void Projet::afficherDetails(){
    cout << "Titre: " << this->titre << endl;
    cout << "Description : " << this->description << endl;
    cout<< "Evaluation : " << this->evaluation;
    cout << "Equipe : " <<  this->equipe;
};

/*ostream& operator<<(ostream& out, Projet& p)
{
    out << "Titre du projet: " << p.titre << ", Description du projet: " << p.description << "\n" << "Evaluation du projet : " << p.evaluation << "Equipe du projet: " <<  p.equipe;
    return out;
};

istream& operator>>(istream& in, Projet& p)
{
    cout << "Entrez le titre du projet : ";
    getline(in, p.titre);
    in.ignore();
    cout << "Entrez la description du projet : ";
    getline(in, p.description);
    in.ignore();in.ignore(numeric_limits<streamsize>::max(), '\n');
    in >> p.evaluation;
    in >> p.equipe;
    return in;
};

Projet& Projet::operator=(const Projet& autreProjet)
{
    this->titre = autreProjet.titre;
    this->description = autreProjet.description;
    this->evaluation = autreProjet.evaluation;
    this->equipe = autreProjet.equipe;
    return *this;
};*/

