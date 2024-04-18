#ifndef EVALUATION_H
#define EVALUATION_H

using namespace std;

 class Evaluation {
 private:
      float noteOriginalite;
      float noteFaisabilite;
      float noteQualiteCode;
 public:
    Evaluation();
    Evaluation(float, float, float);
    void setNoteOriginalite(float);
    float getNoteOriginalite();
    void setNoteFaisabilite(float);
    float getNoteFaisabilite();
    void setNoteQualiteCode(float);
    float getNoteQualiteCode();
    float calculerMoyenne();
    friend ostream& operator << (ostream&, Evaluation&);
    friend istream& operator >> (istream&, Evaluation&);
    friend ostream& operator << (ostream&, Evaluation*);
    friend istream& operator >> (istream&, Evaluation*);
};

 #endif

