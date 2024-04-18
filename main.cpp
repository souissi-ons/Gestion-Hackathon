#include <string>
#include <vector>
#include <iostream>
#include "Hackathon.h"
#include "Projet.h"
#include "ProjetEmbarque.h"
#include "ProjetWeb.h"
#include "Gagnant.h"
#include "Participant.h"
#include "Date.h"
#include "Organisateur.h"
#include "Juge.h"


using namespace std;


void afficherMenuPrincipal()
{
    cout << "Menu principal :" << endl;
    cout << "1. Saisir hackathon" << endl;
    cout << "2. Afficher tous les hackathons dans le fichier" << endl;
    cout << "3. Quitter" << endl;
}

void afficherMenuHackathon()
{
    cout << "Menu hackathon :" << endl;
    cout << "1. Afficher le hackathon" << endl;
    cout << "2. Ajouter le hackathon dans le fichier" << endl;
    cout << "3. Afficher les noms des �quipes gagnantes" << endl;
    cout << "4. Retour au menu principal" << endl;
}

void nouveauHackathon(Hackathon& hackathon)
{
    hackathon = Hackathon();
    Date dateDeDebut(26, 5, 2024);
    Date dateDeFin(2, 6, 2024);
    Date dateDeCreation1(10, 3, 2024);
    Date dateDeCreation2(11, 3, 2024);
    Date dateDeCreation3(12, 3, 2024);
    Date dateDeCreation4(13, 3, 2024);

    // Comp�tences
    Competence competence1("Programmation", "Comp�tence en programmation");
    Competence competence2("Design", "Comp�tence en design");
    Competence competence3("R�seaux", "Comp�tence en r�seaux");

    // Technologies
    Technologie* technologieWeb1 = new Technologie("HTML");
    Technologie* technologieWeb2 = new Technologie("React");
    Technologie* technologieWeb3 = new Technologie("Node.js");

    // Materiels
    Materiel* materielEmbarque1 = new Materiel("Carte Arduino", "Description du mat�riel embarqu�");
    Materiel* materielEmbarque2 = new Materiel("Raspberry Pi", "Description du mat�riel Raspberry Pi pour l'embarqu�");
    Materiel* materielEmbarque3 = new Materiel("ESP32", "Description du mat�riel ESP32 pour l'embarqu�");

    // Participants
    vector<Participant*> participants;

    // �quipes
    vector<Equipe *> equipes;

    // Cr�ation des participants
    for (int i = 0; i < 7; ++i)
    {
        Participant* participant = new Participant();
        participant->setNci(100000 + i); // Num�ro de NCI arbitraire pour la d�mo
        participant->setNom("Participant " + to_string(i + 1));
        participant->setEmail("participant" + to_string(i + 1) + "@example.com");

        // Attribution de comp�tences diff�rentes � chaque participant
        if (i < 2)
        {
            participant->ajouterCompetence(competence1);
        }
        else if (i < 5)
        {
            participant->ajouterCompetence(competence2);
        }
        else
        {
            participant->ajouterCompetence(competence3);
        }

        participants.push_back(participant);
    }

    // Cr�ation des �quipes avec leurs participants respectifs
    Equipe* equipe1 = new Equipe();
    equipe1->setNom("�quipe 1");
    equipe1->setDateCreation(dateDeCreation1);
    equipe1->ajouterParticipant(participants[0]);
    equipe1->ajouterParticipant(participants[1]);
    equipes.push_back(equipe1);

    Equipe *equipe2 = new Equipe();
    equipe2->setNom("�quipe 2");
    equipe2->setDateCreation(dateDeCreation2);
    equipe2->ajouterParticipant(participants[2]);
    equipe2->ajouterParticipant(participants[3]);
    equipe2->ajouterParticipant(participants[4]);
    equipes.push_back(equipe2);

    Equipe *equipe3 = new Equipe();
    equipe3->setNom("�quipe 3");
    equipe3->setDateCreation(dateDeCreation3);
    equipe3->ajouterParticipant(participants[5]);
    equipes.push_back(equipe3);


    Equipe *equipe4 = new Equipe();
    equipe4->setNom("�quipe 4");
    equipe4->setDateCreation(dateDeCreation4);
    equipe4->ajouterParticipant(participants[6]);
    equipes.push_back(equipe4);

    // �valuations
    Evaluation *eval1 = new Evaluation(18.5, 16.7, 19.0);
    Evaluation *eval2 = new Evaluation(17.8, 15.9, 18.2);
    Evaluation *eval3 = new Evaluation(19.0, 18.0, 19.5);
    Evaluation *eval4 = new Evaluation(16.5, 14.8, 17.2);

    // Projets
    ProjetWeb* projetWeb1 = new ProjetWeb();
    projetWeb1->setTitre("Projet Web 1");
    projetWeb1->setDescription("Description du projet web 1");
    projetWeb1->setEquipe(equipe1);
    projetWeb1->setEvaluation(eval1);
    projetWeb1->ajouterTechnologie(technologieWeb1);

    ProjetWeb* projetWeb2 = new ProjetWeb();
    projetWeb2->setTitre("Projet Web 2");
    projetWeb2->setDescription("Description du projet web 2");
    projetWeb2->setEquipe(equipe2);
    projetWeb2->setEvaluation(eval2);
    projetWeb2->ajouterTechnologie(technologieWeb2);

    ProjetWeb* projetWeb3 = new ProjetWeb();
    projetWeb3->setTitre("Projet Web 3");
    projetWeb3->setDescription("Description du projet web 3");
    projetWeb3->setEquipe(equipe3);
    projetWeb3->setEvaluation(eval4);
    projetWeb3->ajouterTechnologie(technologieWeb3);

    ProjetEmbarque* projetEmbarque1 = new ProjetEmbarque();
    projetEmbarque1->setTitre("Projet Embarqu� 1");
    projetEmbarque1->setDescription("Description du projet embarqu� 1");
    projetEmbarque1->setEquipe(equipe4);
    projetEmbarque1->setEvaluation(eval3);
    projetEmbarque1->ajouterMateriel(materielEmbarque1);


    // Hackathon
    hackathon.setTitre("Hackathon C++");
    hackathon.setDescription("Hackathon sur la programmation en C++");
    hackathon.setDateDeDebut(dateDeDebut);
    hackathon.setDateDeFin(dateDeFin);
    hackathon.setTheme("D�veloppement logiciel");
    hackathon.ajouterProjet(projetWeb1);
    hackathon.ajouterProjet(projetWeb2);
    hackathon.ajouterProjet(projetEmbarque1);
    hackathon.ajouterProjet(projetWeb3);

    // Gagnants
    hackathon.remplirGagnants("2000DT", "1000DT", "500DT");

    // Organisateurs
    Organisateur* org1 = new Organisateur(111111, "Organisateur 1", "org1@example.com", "R�le 1");
    Organisateur* org2 = new Organisateur(222222, "Organisateur 2", "org2@example.com", "R�le 2");
    hackathon.ajouterOrganisateur(org1);
    hackathon.ajouterOrganisateur(org2);

    // Juges
    Juge* juge1 = new Juge(333333, "Juge 1", "juge1@example.com", "Expertise 1");
    Juge* juge2 = new Juge(444444, "Juge 2", "juge2@example.com", "Expertise 2");
    hackathon.ajouterJuge(juge1);
    hackathon.ajouterJuge(juge2);

};


int main()
{
    Hackathon hackathon;
    int choixPrincipal;
    do
    {
        afficherMenuPrincipal();
        cout << "Choix : ";
        cin >> choixPrincipal;

        switch (choixPrincipal)
        {
        case 1:
        {
            system("cls");
            //cin >> hackathon;
            nouveauHackathon(hackathon);
            int choixHackathon;
            do
            {
                afficherMenuHackathon();
                cout << "Choix : ";
                cin >> choixHackathon;

                switch (choixHackathon)
                {
                case 1:
                    system("cls");
                    cout << hackathon << endl;
                    break;
                case 2:
                    system("cls");
                    hackathon.ajouterHackathonDansFichier("fichier/Hackathon.txt");
                    break;
                case 3:
                    system("cls");
                    hackathon.ajouterEquipeGagnante();
                    hackathon.afficherEquipeGagnante();
                    break;
                case 4:
                    system("cls");
                    break;
                default:
                    cout << "Choix invalide." << endl;
                    break;
                }
            }
            while (choixHackathon != 4);
            break;
        }
        case 2:
            system("cls");
            Hackathon::afficherHackathonDeFichier("fichier/Hackathon.txt");
            break;
        case 3:
            system("cls");
            cout << "Programme termin�" << endl;
            break;
        default:
            system("cls");
            cout << "Choix invalide." << endl;
            break;
        }
    }
    while (choixPrincipal != 3);



    return 0;
};