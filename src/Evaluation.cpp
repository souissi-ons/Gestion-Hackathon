#include <iostream>;
#include "Evaluation.h"
#include <limits>

using namespace std;

// Constructeurs

// Constructeur par défaut
Evaluation::Evaluation() {};

// Constructeur avec paramètres
Evaluation::Evaluation(float noteOriginalite, float noteFaisabilite, float noteQualiteCode)
{
    this->noteOriginalite = noteOriginalite;
    this->noteFaisabilite = noteFaisabilite;
    this->noteQualiteCode = noteQualiteCode;
};

// Méthodes pour accéder et modifier les membres privés

// Méthode pour modifier la note d'originalité
void Evaluation::setNoteOriginalite(float noteOriginalite)
{
    this->noteOriginalite = noteOriginalite;
};

// Méthode pour obtenir la note d'originalité
float Evaluation::getNoteOriginalite()
{
    return this->noteOriginalite;
};

// Méthode pour modifier la note de faisabilité
void Evaluation::setNoteFaisabilite(float noteFaisabilite)
{
    this->noteFaisabilite = noteFaisabilite;
};

// Méthode pour obtenir la note de faisabilité
float Evaluation::getNoteFaisabilite()
{
    return this->noteFaisabilite;
};

// Méthode pour modifier la note de qualité de code
void Evaluation::setNoteQualiteCode(float noteQualiteCode)
{
    this->noteQualiteCode = noteQualiteCode;
};

// Méthode pour obtenir la note de qualité de code
float Evaluation::getNoteQualiteCode()
{
    return this->noteQualiteCode;
};

// Méthode pour calculer la moyenne des notes
float Evaluation::calculerMoyenne()
{
    return ((this->noteOriginalite + this->noteFaisabilite + this->noteQualiteCode)/3);
};

// Surcharge des opérateurs pour l'entrée/sortie

// Surcharge de l'opérateur << pour afficher les informations de l'évaluation
ostream& operator<<(ostream& out, Evaluation& eval) {
    out  << "La note d'originalité: " << eval.noteOriginalite << ", la note de faisabilité: " << eval.noteFaisabilite << ", la note de qualité de code: " << eval.noteQualiteCode << endl;
    return out;
}

// Surcharge de l'opérateur >> pour saisir les informations de l'evaluation
istream& operator>>(istream& in, Evaluation& eval) {
    do {
        cout << "Donner la note d'originalité (entre 0 et 20) : ";
        in >> eval.noteOriginalite;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (eval.noteOriginalite < 0 || eval.noteOriginalite > 20);

    do {
        cout << "Donner la note de faisabilité (entre 0 et 20) : ";
        in >> eval.noteFaisabilite;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (eval.noteFaisabilite < 0 || eval.noteFaisabilite > 20);

    do {
        cout << "Donner la note de qualité de code (entre 0 et 20) : ";
        in >> eval.noteQualiteCode;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (eval.noteQualiteCode < 0 || eval.noteQualiteCode > 20);

    return in;
};


// Surcharge de l'opérateur << pour afficher les informations de l'évaluation*
ostream& operator<<(ostream& out, Evaluation* eval) {
    out  << "La note d'originalité: " << eval->noteOriginalite << ", la note de faisabilité: " << eval->noteFaisabilite << ", la note de qualité de code: " << eval->noteQualiteCode << endl;
    return out;
}

// Surcharge de l'opérateur >> pour saisir les informations de l'evaluation*
istream& operator>>(istream& in, Evaluation* eval) {
    do {
        cout << "Donner la note d'originalité (entre 0 et 20) : ";
        in >> eval->noteOriginalite;
        in.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (eval->noteOriginalite < 0 || eval->noteOriginalite > 20);

    do {
        cout << "Donner la note de faisabilité (entre 0 et 20) : ";
        in >> eval->noteFaisabilite;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (eval->noteFaisabilite < 0 || eval->noteFaisabilite > 20);

    do {
        cout << "Donner la note de qualité de code (entre 0 et 20) : ";
        in >> eval->noteQualiteCode;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (eval->noteQualiteCode < 0 || eval->noteQualiteCode > 20);

    return in;
};


