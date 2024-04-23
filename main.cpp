#include "Date.h"
#include "Gagnant.h"
#include "Hackathon.h"
#include "Juge.h"
#include "Organisateur.h"
#include "Participant.h"
#include "Projet.h"
#include "ProjetEmbarque.h"
#include "ProjetWeb.h"
#include "Specialisation.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

void afficherMenuPrincipal() {
  cout << "Menu principal :" << endl;
  cout << "1. Saisir hackathon" << endl;
  cout << "2. Afficher tous les hackathons dans le fichier" << endl;
  cout << "3. Afficher un hackathon dans le fichier" << endl;
  cout << "4. Saisir equipe" << endl;
  cout << "5. Afficher toutes les equipes dans le fichier" << endl;
  cout << "6. Afficher une equipe dans le fichier" << endl;
  cout << "7. Afficher le nombre total de participants dans tous le hackathon: "
       << endl;
  cout << "8. Afficher le nombre total de projets dans tous le hackathon: "
       << endl;
  cout << "9. Quitter" << endl;
};

void afficherMenuHackathon() {
  cout << "Menu hackathon :" << endl;
  cout << "1. Afficher le hackathon" << endl;
  cout << "2. Ajouter le hackathon dans le fichier des hackathons" << endl;
  cout << "3. Ajouter le hackathon dans un nouveau fichier" << endl;
  cout << "4. Afficher les noms des equipes gagnantes" << endl;
  cout << "5. Rechercher un membre de jury par numero de carte identite"
       << endl;
  cout << "6. Supprimer un membre de jury par numero de carte identite" << endl;
  cout << "7. Rechercher un organisateur par numero de carte identite" << endl;
  cout << "8. Supprimer un organisateur par numero de carte identite" << endl;
  cout << "9. Afficher le projet embarque avec le plus de materiels" << endl;
  cout << "10. Afficher le projet web avec le plus de technologies" << endl;
  cout << "11. Retour au menu principal" << endl;
};

void afficherMenuEquipe() {
  cout << "Menu equipe :" << endl;
  cout << "1. Afficher l'equipe" << endl;
  cout << "2. Ajouter l'equipe dans le fichier des equipes" << endl;
  cout << "3. Ajouter l'equipe dans un nouveau fichier" << endl;
  cout << "4. Afficher le participant avec le plus de competences" << endl;
  cout << "5. Trier les participants par nom" << endl;
  cout << "6. Trier les participants par NCI" << endl;
  cout << "7. Afficher tous les participants de l'equipe" << endl;
  cout << "8. Retour au menu principal" << endl;
};


int main() {
  Hackathon hackathon;
  Equipe equipe;
  int choixPrincipal;
  do {
    afficherMenuPrincipal();
    cout << "Choix : ";
    cin >> choixPrincipal;

    switch (choixPrincipal) {
    case 1: {
      system("cls");
      cin >> hackathon;
      int choixHackathon;
      do {
        afficherMenuHackathon();
        cout << "Choix : ";
        cin >> choixHackathon;

        switch (choixHackathon) {
        case 1: {
          system("cls");
          cout << hackathon << endl;
          break;
        }
        case 2: {
          system("cls");
          hackathon.ajouterHackathonDansFichier("fichier/Hackathons.txt");
          break;
        }
        case 3: {
          system("cls");
          hackathon.creerFichierHackathon();
          break;
        }
        case 4: {
          system("cls");
          hackathon.ajouterEquipeGagnante();
          hackathon.afficherEquipeGagnante();
          break;
        }
        case 5: {
          system("cls");
          int nciJuge;
          cout << "Entrez le numero de carte identite du juge e rechercher : ";
          cin >> nciJuge;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          Juge *jugeTrouve = hackathon.rechercherJuge(nciJuge);
          if (jugeTrouve != nullptr) {
            cout << "Juge trouve : " << *jugeTrouve << endl;
            delete jugeTrouve;
          } else {
            cout << "Membre de jury non trouve." << endl;
          }
          break;
        }
        case 6: {
          system("cls");
          int nciJuge;
          cout << "Entrez le numero de carte identite du juge e supprimer : ";
          cin >> nciJuge;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          hackathon.supprimerJuge(nciJuge);
          cout << "Membre de jury supprime avec succes." << endl;
          break;
        }
        case 7: {
          system("cls");
          int nciOrg;
          cout << "Entrez le numero de carte identite de l'organisateur e "
                  "rechercher : ";
          cin >> nciOrg;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          Organisateur *orgTrouve = hackathon.rechercherOrganisateur(nciOrg);
          if (orgTrouve != nullptr) {
            cout << "Organisateur trouve : " << *orgTrouve << endl;
            delete orgTrouve;
          } else {
            cout << "Organisateur non trouve." << endl;
          }
          break;
        }
        case 8: {
          system("cls");
          int nciOrg;
          cout << "Entrez le numero de carte identite de l'organisateur a supprimer : ";
          cin >> nciOrg;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          hackathon.supprimerOrganisateur(nciOrg);
          cout << "Organisateur supprime avec succes." << endl;
          break;
        }
        case 9: {
          system("cls");
          ProjetEmbarque *projetEmbarqueAvecPlusDeMateriels =
              hackathon.getProjetEmbarqueAvecPlusDeMateriels();
          if (projetEmbarqueAvecPlusDeMateriels != nullptr) {
            cout << "Projet embarque avec le plus de materiels :" << endl;
            cout << *projetEmbarqueAvecPlusDeMateriels << endl;
            delete projetEmbarqueAvecPlusDeMateriels;
          } else {
            cout << "Aucun projet embarque trouve." << endl;
          }
          break;
        }
        case 10: {
          system("cls");
          ProjetWeb *projetWebAvecPlusDeTechnologies =
              hackathon.getProjetWebAvecPlusDeTechnologies();
          if (projetWebAvecPlusDeTechnologies != nullptr) {
            cout << "Projet web avec le plus de technologies :" << endl;
            cout << *projetWebAvecPlusDeTechnologies << endl;
            delete projetWebAvecPlusDeTechnologies;
          } else {
            cout << "Aucun projet web trouve." << endl;
          }
          break;
        }
        case 11: {
          system("cls");
          break;
        }
        default: {
          system("cls");
          cout << "Choix invalide." << endl;
          break;
        }
        }
      } while (choixHackathon != 11);
      break;
    }
    case 2: {
      system("cls");
      Hackathon::afficherHackathonsDeFichier("fichier/Hackathons.txt");
      break;
    }
    case 3: {
      system("cls");
      string titre;
      string nomFichier;
      cout << "Donner le titre du Hackathon e afficher: ";
      getline(cin >> ws, titre);
      nomFichier = "fichier/" + titre + ".txt";
      Hackathon::afficherHackathonsDeFichier(nomFichier);
      break;
    }
    case 4: {
      system("cls");
      cin >> equipe;
      int choixEquipe;
      do {
        afficherMenuEquipe();
        cout << "Choix : ";
        cin >> choixEquipe;

        switch (choixEquipe) {
        case 1: {
          system("cls");
          cout << equipe << endl;
          break;
        }
        case 2: {
          system("cls");
          equipe.ajouterEquipeDansFichier("fichier/Equipes.txt");
          break;
        }
        case 3: {
          system("cls");
          equipe.creerFichierEquipe();
          break;
        }
        case 4: {
          system("cls");
          Participant *participantAvecPlusDeCompetences =
              equipe.participantAvecPlusDeCompetences();
          if (participantAvecPlusDeCompetences != nullptr) {
            cout << "Participant avec le plus de competences :" << endl;
            cout << *participantAvecPlusDeCompetences << endl;
            delete participantAvecPlusDeCompetences;
          } else {
            cout << "Aucun participant trouve." << endl;
          }
          break;
        }
        case 5: {
          system("cls");
          equipe.trierParticipantsParNom();
          cout << "Participants tries par nom :" << endl;
          equipe.afficherParticipants();
          break;
        }
        case 6: {
          system("cls");
          equipe.trierParticipantsParNci();
          cout << "Participants tries par NCI :" << endl;
          equipe.afficherParticipants();
          break;
        }
        case 7: {
          system("cls");
          cout << "Tous les participants de l'equipe :" << endl;
          equipe.afficherParticipants();
          break;
        }
        case 8: {
          system("cls");
          break;
        }
        default: {
          system("cls");
          cout << "Choix invalide." << endl;
          break;
        }
        }
      } while (choixEquipe != 8);
      break;
    }
    case 5: {
      system("cls");
      Equipe::afficherEquipesDeFichier("fichier/Equipes.txt");
      break;
    }
    case 6: {
      system("cls");
      string nomEquipe;
      string nomFichier;
      cout << "Donner le nom de l'equipe e afficher: ";
      getline(cin >> ws, nomEquipe);
      nomFichier = "fichier/" + nomEquipe + ".txt";
      Equipe::afficherEquipesDeFichier(nomFichier);
      break;
    }
    case 7: {
      system("cls");
      cout << "Le nombre total de participants dans tous les hackathons est: "
           << Participant::getNombreParticipants() << endl;
      break;
    }
    case 8: {
      system("cls");
      cout << "Le nombre total de projets dans tous les hackathons est: "
           << Projet::getNombreProjets() << endl;
      break;
    }
    case 9: {
      system("cls");
      cout << "Programme termine" << endl;
      break;
    }
    default: {
      system("cls");
      cout << "Choix invalide." << endl;
      break;
    }
    }
  } while (choixPrincipal != 9);

  return 0;
}
