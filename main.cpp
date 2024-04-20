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
#include "Specialisation.h"

using namespace std;

void afficherMenuPrincipal()
{
    cout << "Menu principal :" << endl;
    cout << "1. Saisir hackathon" << endl;
    cout << "2. Afficher tous les hackathons dans le fichier" << endl;
    cout << "3. Afficher un hackathon dans le fichier" << endl;
    cout << "4. Saisir equipe" << endl;
    cout << "5. Afficher toutes les equipes dans le fichier" << endl;
    cout << "6. Afficher une equipe dans le fichier" << endl;
    cout << "7. Afficher le nombre total de participants dans tous le hackathon: " << endl;
    cout << "8. Afficher le nombre total de projets dans tous le hackathon: "  << endl;
    cout << "9. Quitter" << endl;
};

void afficherMenuHackathon()
{
    cout << "Menu hackathon :" << endl;
    cout << "1. Afficher le hackathon" << endl;
    cout << "2. Ajouter le hackathon dans le fichier des hackathons" << endl;
    cout << "3. Ajouter le hackathon dans un nouveau fichier" << endl;
    cout << "4. Afficher les noms des équipes gagnantes" << endl;
    cout << "5. Rechercher un membre de jury par numéro de carte identité" << endl;
    cout << "6. Supprimer un membre de jury par numéro de carte identité" << endl;
    cout << "7. Rechercher un organisateur par numéro de carte identité" << endl;
    cout << "8. Supprimer un organisateur par numéro de carte identité" << endl;
    cout << "9. Afficher le projet embarqué avec le plus de matériels" << endl;
    cout << "10. Afficher le projet web avec le plus de technologies" << endl;
    cout << "11. Retour au menu principal" << endl;

};

void afficherMenuEquipe()
{
    cout << "Menu équipe :" << endl;
    cout << "1. Afficher l'équipe" << endl;
    cout << "2. Ajouter l'équipe dans le fichier des equipes" << endl;
    cout << "3. Ajouter l'equipe dans un nouveau fichier" << endl;
    cout << "4. Afficher le participant avec le plus de compétences" << endl;
    cout << "5. Trier les participants par nom" << endl;
    cout << "6. Trier les participants par NCI" << endl;
    cout << "7. Afficher tous les participants de l'équipe" << endl;
    cout << "8. Retour au menu principal" << endl;
};

void nouvelleEquipe(Equipe& equipe)
{
    equipe= Equipe();
    Competence competence1("Programmation", "Compétence en programmation");
    Competence competence2("Design", "Compétence en design");
    Competence competence3("Réseaux", "Compétence en réseaux");

    Participant* participant1 = new Participant();
    participant1->setNci(333333);
    participant1->setNom("Participant 1");
    participant1->setEmail("participant1@example.com");

    participant1->ajouterCompetence(competence1);
    participant1->ajouterCompetence(competence2);

    Participant* participant2 = new Participant();
    participant2->setNci(222222);
    participant2->setNom("Participant 2");
    participant2->setEmail("participant2@example.com");

    participant2->ajouterCompetence(competence1);
    participant2->ajouterCompetence(competence2);
    participant2->ajouterCompetence(competence3);

    Participant* participant3 = new Participant();
    participant3->setNci(111111);
    participant3->setNom("Participant 3");
    participant3->setEmail("participant3@example.com");

    participant3->ajouterCompetence(competence3);

    Date dateDeCreation(10, 3, 2024);

    equipe.setNom("Équipe 1");
    equipe.setDateCreation(dateDeCreation);
    equipe.ajouterParticipant(participant1);
    equipe.ajouterParticipant(participant2);
    equipe.ajouterParticipant(participant3);
};


void nouveauHackathon(Hackathon& hackathon)
{
    hackathon = Hackathon();
    Date dateDeDebut(26, 5, 2024);
    Date dateDeFin(2, 6, 2024);
    Date dateDeCreation1(10, 3, 2024);
    Date dateDeCreation2(11, 3, 2024);
    Date dateDeCreation3(12, 3, 2024);
    Date dateDeCreation4(13, 3, 2024);

    // Compétences
    Competence competence1("Programmation", "Compétence en programmation");
    Competence competence2("Design", "Compétence en design");
    Competence competence3("Réseaux", "Compétence en réseaux");

    // Technologies
    Technologie* technologieWeb1 = new Technologie("HTML");
    Technologie* technologieWeb2 = new Technologie("React");
    Technologie* technologieWeb3 = new Technologie("Node.js");

    // Materiels
    Materiel* materielEmbarque1 = new Materiel("Carte Arduino", "Description du matériel embarqué");
    Materiel* materielEmbarque2 = new Materiel("Raspberry Pi", "Description du matériel Raspberry Pi pour l'embarqué");
    Materiel* materielEmbarque3 = new Materiel("ESP32", "Description du matériel ESP32 pour l'embarqué");

    // Participants
    vector<Participant*> participants;

    // Équipes
    vector<Equipe *> equipes;

    // Création des participants
    for (int i = 0; i < 7; ++i)
    {
        Participant* participant = new Participant();
        participant->setNci(100000 + i);
        participant->setNom("Participant " + to_string(i + 1));
        participant->setEmail("participant" + to_string(i + 1) + "@example.com");

        // Attribution de compétences différentes à chaque participant
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

    // Création des équipes avec leurs participants respectifs
    Equipe* equipe1 = new Equipe();
    equipe1->setNom("Équipe 1");
    equipe1->setDateCreation(dateDeCreation1);
    equipe1->ajouterParticipant(participants[0]);
    equipe1->ajouterParticipant(participants[1]);
    equipes.push_back(equipe1);

    Equipe *equipe2 = new Equipe();
    equipe2->setNom("Équipe 2");
    equipe2->setDateCreation(dateDeCreation2);
    equipe2->ajouterParticipant(participants[2]);
    equipe2->ajouterParticipant(participants[3]);
    equipe2->ajouterParticipant(participants[4]);
    equipes.push_back(equipe2);

    Equipe *equipe3 = new Equipe();
    equipe3->setNom("Équipe 3");
    equipe3->setDateCreation(dateDeCreation3);
    equipe3->ajouterParticipant(participants[5]);
    equipes.push_back(equipe3);


    Equipe *equipe4 = new Equipe();
    equipe4->setNom("Équipe 4");
    equipe4->setDateCreation(dateDeCreation4);
    equipe4->ajouterParticipant(participants[6]);
    equipes.push_back(equipe4);

    // Évaluations
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
    projetWeb2->ajouterTechnologie(technologieWeb3);

    ProjetWeb* projetWeb3 = new ProjetWeb();
    projetWeb3->setTitre("Projet Web 3");
    projetWeb3->setDescription("Description du projet web 3");
    projetWeb3->setEquipe(equipe3);
    projetWeb3->setEvaluation(eval4);
    projetWeb3->ajouterTechnologie(technologieWeb3);

    ProjetEmbarque* projetEmbarque1 = new ProjetEmbarque();
    projetEmbarque1->setTitre("Projet Embarqué 1");
    projetEmbarque1->setDescription("Description du projet embarqué 1");
    projetEmbarque1->setEquipe(equipe4);
    projetEmbarque1->setEvaluation(eval3);
    projetEmbarque1->ajouterMateriel(materielEmbarque1);


    // Hackathon
    hackathon.setTitre("HackathonC++");
    hackathon.setDescription("Hackathon sur la programmation en C++");
    hackathon.setDateDeDebut(dateDeDebut);
    hackathon.setDateDeFin(dateDeFin);
    hackathon.setTheme("Développement logiciel");
    hackathon.ajouterProjet(projetWeb1);
    hackathon.ajouterProjet(projetWeb2);
    hackathon.ajouterProjet(projetEmbarque1);
    hackathon.ajouterProjet(projetWeb3);

    // Gagnants
    hackathon.remplirGagnants("2000DT", "1000DT", "500DT");

    // Organisateurs
    Organisateur* org1 = new Organisateur(111111, "Organisateur 1", "org1@example.com", "Rôle 1");
    Organisateur* org2 = new Organisateur(222222, "Organisateur 2", "org2@example.com", "Rôle 2");
    hackathon.ajouterOrganisateur(org1);
    hackathon.ajouterOrganisateur(org2);

    // Création des spécialisations
    Specialisation* spec1 = new Specialisation("Langages de programmation", "Expertise en C++, Java, Python");
    Specialisation* spec2 = new Specialisation("Design UI/UX", "Expertise en conception d'interfaces utilisateur");
    Specialisation* spec3 = new Specialisation("Sécurité informatique", "Expertise en cryptographie et protection des données");

    // Juges
    Juge* juge1 = new Juge(333333, "Juge 1", "juge1@example.com", "Expertise 1");
    Juge* juge2 = new Juge(444444, "Juge 2", "juge2@example.com", "Expertise 2");
    juge1->ajouterSpecialisation(spec1);
    juge1->ajouterSpecialisation(spec2);
    juge2->ajouterSpecialisation(spec3);

    hackathon.ajouterJuge(juge1);
    hackathon.ajouterJuge(juge2);
};


int main()
{
    Hackathon hackathon;
    Equipe equipe;
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
                {
                    system("cls");
                    cout << hackathon << endl;
                    break;
                }
                case 2:
                {
                    system("cls");
                    hackathon.ajouterHackathonDansFichier("fichier/Hackathons.txt");
                    break;
                }
                case 3:
                {
                    system("cls");
                    hackathon.creerFichierHackathon();
                    break;
                }
                case 4:
                {
                    system("cls");
                    hackathon.ajouterEquipeGagnante();
                    hackathon.afficherEquipeGagnante();
                    break;
                }
                case 5:
                {
                    system("cls");
                    int nciJuge;
                    cout << "Entrez le numéro de carte identité du juge à rechercher : ";
                    cin >> nciJuge;
                    Juge* jugeTrouve = hackathon.rechercherJuge(nciJuge);
                    if (jugeTrouve != nullptr)
                    {
                        cout << "Juge trouvé : " << *jugeTrouve << endl;
                    }
                    else
                    {
                        cout << "Membre de jury non trouvé." << endl;
                    }
                    break;
                }
                case 6:
                {
                    system("cls");
                    int nciJuge;
                    cout << "Entrez le numéro de carte identité du juge à supprimer : ";
                    cin >> nciJuge;
                    hackathon.supprimerJuge(nciJuge);
                    cout << "Membre de jury supprimé avec succès." << endl;
                    break;
                }
                case 7:
                {
                    system("cls");
                    int nciOrg;
                    cout << "Entrez le numéro de carte identité de l'organisateur à rechercher : ";
                    cin >> nciOrg;
                    Organisateur* orgTrouve = hackathon.rechercherOrganisateur(nciOrg);
                    if (orgTrouve != nullptr)
                    {
                        cout << "Organisateur trouvé : " << *orgTrouve << endl;
                    }
                    else
                    {
                        cout << "Organisateur non trouvé." << endl;
                    }
                    break;
                }
                case 8:
                {
                    system("cls");
                    int nciOrg;
                    cout << "Entrez le numéro de carte identité de l'organisateur à supprimer : ";
                    cin >> nciOrg;
                    hackathon.supprimerOrganisateur(nciOrg);
                    cout << "Organisateur supprimé avec succès." << endl;
                    break;
                }
                case 9:
                {
                    system("cls");
                    ProjetEmbarque* projetEmbarqueAvecPlusDeMateriels = hackathon.getProjetEmbarqueAvecPlusDeMateriels();
                    if (projetEmbarqueAvecPlusDeMateriels != nullptr)
                    {
                        cout << "Projet embarqué avec le plus de matériels :" << endl;
                        cout << *projetEmbarqueAvecPlusDeMateriels << endl;
                    }
                    else
                    {
                        cout << "Aucun projet embarqué trouvé." << endl;
                    }
                    break;
                }
                case 10:
                {
                    system("cls");
                    ProjetWeb* projetWebAvecPlusDeTechnologies = hackathon.getProjetWebAvecPlusDeTechnologies();
                    if (projetWebAvecPlusDeTechnologies != nullptr)
                    {
                        cout << "Projet web avec le plus de technologies :" << endl;
                        cout << *projetWebAvecPlusDeTechnologies << endl;
                    }
                    else
                    {
                        cout << "Aucun projet web trouvé." << endl;
                    }
                    break;
                }
                case 11:
                {
                    system("cls");
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "Choix invalide." << endl;
                    break;
                }
                }
            }
            while (choixHackathon != 11);
            break;
        }
        case 2:
        {
            system("cls");
            Hackathon::afficherHackathonsDeFichier("fichier/Hackathons.txt");
            break;
        }
        case 3:
        {
            system("cls");
            string titre;
            string nomFichier;
            cout << "Donner le titre du Hackathon à afficher: ";
            getline(cin, titre);
            nomFichier = "fichier/" + titre + ".txt";
            Hackathon::afficherHackathonsDeFichier(nomFichier);
            break;
        }
        case 4:
        {
            system("cls");
            //cin >> equipe;
            nouvelleEquipe(equipe);
            int choixEquipe;
            do
            {
                afficherMenuEquipe();
                cout << "Choix : ";
                cin >> choixEquipe;

                switch (choixEquipe)
                {
                case 1:
                {
                    system("cls");
                    cout << equipe << endl;
                    break;
                }
                case 2:
                {
                    system("cls");
                    equipe.ajouterEquipeDansFichier("fichier/Equipes.txt");
                    break;
                }
                case 3:
                {
                    system("cls");
                    equipe.creerFichierEquipe();
                    break;
                }
                case 4:
                {
                    system("cls");
                    Participant* participantAvecPlusDeCompetences = equipe.participantAvecPlusDeCompetences();
                    if (participantAvecPlusDeCompetences != nullptr)
                    {
                        cout << "Participant avec le plus de compétences :" << endl;
                        cout << *participantAvecPlusDeCompetences << endl;
                    }
                    else
                    {
                        cout << "Aucun participant trouvé." << endl;
                    }
                    break;
                }
                case 5:
                {
                    system("cls");
                    equipe.trierParticipantsParNom();
                    cout << "Participants triés par nom :" << endl;
                    equipe.afficherParticipants();
                    break;
                }
                case 6:
                {
                    system("cls");
                    equipe.trierParticipantsParNci();
                    cout << "Participants triés par NCI :" << endl;
                    equipe.afficherParticipants();
                    break;
                }
                case 7:
                {
                    system("cls");
                    cout << "Tous les participants de l'équipe :" << endl;
                    equipe.afficherParticipants();
                    break;
                }
                case 8:
                {
                    system("cls");
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "Choix invalide." << endl;
                    break;
                }
                }
            }
            while (choixEquipe != 8);
            break;
        }
        case 5:
        {
            system("cls");
            Equipe::afficherEquipesDeFichier("fichier/Equipes.txt");
            break;
        }
        case 6:
        {
            system("cls");
            string nomEquipe;
            string nomFichier;
            cout << "Donner le nom de l'equipe à afficher: ";
            getline(cin, nomEquipe);
            nomFichier = "fichier/" + nomEquipe + ".txt";
            Equipe::afficherEquipesDeFichier(nomFichier);
            break;
        }
        case 7 :
        {
            system("cls");
            cout << "Le nombre total de participants dans tous les hackathons est: " << Participant::getNombreParticipants() << endl;
            break;
        }
        case 8 :
        {
            system("cls");
            cout << "Le nombre total de projets dans tous les hackathons est: " << Projet::getNombreProjets() << endl;
            break;
        }
        case 9:
        {
            system("cls");
            cout << "Programme terminé" << endl;
            break;
        }
        default:
        {
            system("cls");
            cout << "Choix invalide." << endl;
            break;
        }
        }
    }
    while (choixPrincipal != 9);
    return 0;
};
