#include"universite.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    /*
        Etudiant e = Etudiant("Ayman", "Essaki", 14, 1, "Mécanique");
        cout<< e.afficher() <<endl;

        Enseignant E = Enseignant("Hamid", "Raefat", 32, 2, "Info");
        cout<< E.afficher() <<endl;

        Matiere m = Matiere("C++", 10, E);
        cout<< m.afficher() <<endl;

        Cours c = Cours(m);
        cout<< c.afficher() <<endl;
    */
    /*
        Etudiant* e = new Etudiant("Ayman", "Essaki", 14, 1, "Mécanique");
        cout<< e->afficher() <<endl;

        Enseignant* E = new Enseignant("Hamid", "Raefat", 32, 2, "Info");
        cout<< E->afficher() <<endl;

        Matiere* m = new Matiere("C++", 10, *E);
        cout<< m->afficher() <<endl;

        Cours* c = new Cours(*m);
        cout<< c->afficher() <<endl;
        
        c->inscritEtudiant(e);
        c->afficherListeEtudiants();

        c->deinscriptionEtudiant(e->getNumEtudiant());
        c->afficherListeEtudiants();
    */ 
    /*
        Personne* e = new Etudiant("Ayman", "Essaki", 14, 1, "Mécanique");
        cout<< e->afficher() <<endl;

        Personne* E = new Enseignant("Hamid", "Raefat", 32, 2, "Info");
        cout<< E->afficher() <<endl;

        Universite u;

        u.ajouterPersonne(e);
        u.ajouterPersonne(E);
        u.afficherPersonne();
        u.supprimerPersonne(e->getNom());
        u.afficherPersonne();
        u.supprimerPersonne(E->getNom());
        u.afficherPersonne();
    */
    /*
        Enseignant* E = new Enseignant("Hamid", "Raefat", 32, 2, "Info");
        Matiere m = Matiere("C++", 10, *E);

        Universite u;
        u.creerCours(m);
        u.afficherCours();
        u.supprimerCours(m.getNom());
        u.afficherCours();
    */
    int choix;
    Universite u;

    do
    {
        afficherMenu();
        cin>>choix;
        cin.ignore();

        string nom, prenom, domaineEtude, specialisation, nom_matiere;
        int age, numEtudiant, numEmploye, credit;
        Etudiant* e;
        Enseignant* E;
        Matiere m;

        switch (choix)
        {
        case 1:
                cout << "Ajout d'un étudiant\n";
                cout << "Nom: ";
                getline(cin, nom);
                cout << "Prénom: ";
                getline(cin, prenom);
                cout << "Âge: ";
                cin >> age;
                cin.ignore();
                cout << "Numéro d'étudiant: ";
                cin >> numEtudiant;
                cin.ignore();
                cout << "Domaine d'étude: ";
                getline(cin, domaineEtude);
                e = new Etudiant(nom, prenom, age, numEtudiant, domaineEtude);
                u.ajouterPersonne(e);
            break;
        
        case 2:
                cout << "Ajout d'un enseignant\n";
                cout << "Nom: ";
                getline(cin, nom);
                cout << "Prénom: ";
                getline(cin, prenom);
                cout << "Âge: ";
                cin >> age;
                cin.ignore();
                cout << "Numéro d'employé: ";
                cin >> numEmploye;
                cin.ignore();
                cout << "Spécialisation: ";
                getline(cin, specialisation);
                E = new Enseignant(nom, prenom, age, numEmploye, specialisation);
                u.ajouterPersonne(E);
                break;

        case 3:
                cout << "Création d'un cours\n";
                cout << "Nom de la matière: ";
                getline(cin, nom_matiere);
                cout << "Crédits: ";
                cin >> credit;
                cin.ignore();
                cout << "Nom: ";
                getline(cin, nom);
                cout << "Prénom: ";
                getline(cin, prenom);
                cout << "Âge: ";
                cin >> age;
                cin.ignore();
                cout << "Numéro d'employé: ";
                cin >> numEmploye;
                cin.ignore();
                cout << "Spécialisation: ";
                getline(cin, specialisation);
                E = new Enseignant(nom, prenom, age, numEmploye, specialisation);
                m = Matiere(nom_matiere, credit, *E);
                u.creerCours(m);
            break;

        case 4:
                u.afficherPersonne();
            break;

        case 5:
                u.afficherCours();
            break;
        
        case 6:
              cout << "Au revoir!\n";
              exit(0);
            break;
        
        default:
            cout << "\a\a\a\aOption invalide. Veuillez réessayer.\n";
            break;
        }
    } while (choix!=6);

    return 0;
}
