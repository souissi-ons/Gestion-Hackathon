#include <iostream>;
#include "Evaluation.h"

using namespace std;

Evaluation::Evaluation() {};

Evaluation::Evaluation(float noteOriginalite, float noteFaisabilite, float noteQualiteCode)
{
    this->noteOriginalite = noteOriginalite;
    this->noteFaisabilite = noteFaisabilite;
    this->noteQualiteCode = noteQualiteCode;
};

void Evaluation::setNoteOriginalite(float noteOriginalite)
{
    this->noteOriginalite = noteOriginalite;
};

float Evaluation::getNoteOriginalite()
{
    return this->noteOriginalite;
};

void Evaluation::setNoteFaisabilite(float noteFaisabilite)
{
    this->noteFaisabilite = noteFaisabilite;
};

float Evaluation::getNoteFaisabilite()
{
    return this->noteFaisabilite;
};

void Evaluation::setNoteQualiteCode(float noteQualiteCode)
{
    this->noteQualiteCode = noteQualiteCode;
};

float Evaluation::getNoteQualiteCode()
{
    return this->noteQualiteCode;
};

float Evaluation::calculerMoyenne()
{
    return ((this->noteOriginalite + this->noteFaisabilite + this->noteQualiteCode)/3);
};

ostream& operator<<(ostream& out, Evaluation& eval) {
    out  << "La note d'originalité: " << eval.noteOriginalite << ", la note de faisabilité: " << eval.noteFaisabilite << ", la note de qualité de code: " << eval.noteQualiteCode << endl;
    return out;
}

istream& operator>>(istream& in, Evaluation& eval) {
    do
    {
        cout << "Donner la note d originalité: ";
        in >> eval.noteOriginalite;
    }
    while (eval.noteOriginalite<0 || eval.noteOriginalite>20);

    do
    {
        cout << "Donner la note de faisabilité: ";
        in >> eval.noteFaisabilite;
    }
    while (eval.noteFaisabilite<0 || eval.noteFaisabilite>20);

    do
    {
        cout << "Donner la note de qualité de code: ";
        in >> eval.noteQualiteCode;
    }
    while (eval.noteQualiteCode<0 || eval.noteQualiteCode>20);
    return in;
};

ostream& operator<<(ostream& out, Evaluation* eval) {
    out  << "La note d'originalité: " << eval->noteOriginalite << ", la note de faisabilité: " << eval->noteFaisabilite << ", la note de qualité de code: " << eval->noteQualiteCode << endl;
    return out;
}

istream& operator>>(istream& in, Evaluation* eval) {
    do
    {
        cout << "Donner la note d originalité: ";
        in >> eval->noteOriginalite;
    }
    while (eval->noteOriginalite<0 || eval->noteOriginalite>20);

    do
    {
        cout << "Donner la note de faisabilité: ";
        in >> eval->noteFaisabilite;
    }
    while (eval->noteFaisabilite<0 || eval->noteFaisabilite>20);

    do
    {
        cout << "Donner la note de qualité de code: ";
        in >> eval->noteQualiteCode;
    }
    while (eval->noteQualiteCode<0 || eval->noteQualiteCode>20);
    return in;
};

