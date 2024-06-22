#include"universite.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

Personne::Personne()
{
        nom="vide";
        prenom="vide";
        age=0;
}
Personne::Personne(string nom, string prenom, int age):nom(nom), prenom(prenom), age(age){}
Personne::Personne(const Personne & autre_personne):nom(autre_personne.nom), prenom(autre_personne.prenom), age(autre_personne.age){}
Personne::~Personne(){}

string Personne::getNom()const{ return(nom); }
string Personne::getPrenom()const{ return(prenom); }
int Personne::getAge()const{ return(age); }

void Personne::setNom(string nom){ this->nom = nom; }
void Personne::setPrenom(string prenom){ this->prenom = prenom; }
void Personne::setAge(int age){ this->age = age; }

string Personne::afficher()const{ return ("Nom:\t"+ nom + "\tPrenom:\t"+ prenom + "\tAge:\t"+ to_string(age) ); }

Etudiant::Etudiant():Personne()
{
    numEtudiant = 0;
    domaineEtude ="";
}
Etudiant::Etudiant(string nom, string prenom, int age, int numEtudiant, string domaineEtude):Personne(nom, prenom, age), numEtudiant(numEtudiant), domaineEtude(domaineEtude){}
Etudiant::Etudiant(const Etudiant & etudiant):Personne(etudiant), numEtudiant(etudiant.numEtudiant), domaineEtude(etudiant.domaineEtude){}
Etudiant::~Etudiant(){}

int Etudiant::getNumEtudiant() const{ return(numEtudiant); }
string Etudiant::getDomaineEtude() const{ return(domaineEtude); }

void Etudiant::setNumEtudiant(int numEtudiant){ this->numEtudiant = numEtudiant;}
void Etudiant::setDomaineEtude(string getDomaineEtude){ this->domaineEtude = domaineEtude;}

string Etudiant::afficher() const { return(Personne::afficher()+"\tNumEtudiant:\t"+ to_string(numEtudiant) +"\tDomaineEtude:\t"+ domaineEtude); }

Enseignant::Enseignant():Personne()
{
    numEmploye = 0;
    specialisation ="Aucune";
}
Enseignant::Enseignant(string nom, string prenom, int age, int numEmploye, string specialisation):Personne(nom, prenom, age), numEmploye(numEmploye), specialisation(specialisation){}
Enseignant::Enseignant(const Enseignant & enseignant):Personne(enseignant), numEmploye(enseignant.numEmploye), specialisation(enseignant.specialisation){}
Enseignant::~Enseignant(){}

int Enseignant::getNumEmploye()const{ return(numEmploye); }
string Enseignant::getSpecialisation()const{ return(specialisation); }

void Enseignant::setNumEmploye(int numEmploye){ this->numEmploye = numEmploye; }
void Enseignant::setSpecialisation(string specialisation){ this->specialisation = specialisation; }

string Enseignant::afficher()const{ return(Personne::afficher()+"\tNumEmploye:\t"+ to_string(numEmploye) +"\tSpecialisation:\t"+  specialisation); }

Matiere::Matiere()
{
    nom ="";
    credit = 0;
    enseignantResponsable.getNom()="";
    enseignantResponsable.getPrenom()="";
    enseignantResponsable.getSpecialisation()="";
}
Matiere::Matiere(string nom, int credit, Enseignant enseignantResponsable): nom(nom), credit(credit), enseignantResponsable(enseignantResponsable){}
Matiere::Matiere(const Matiere & matiere): nom(matiere.nom), credit(matiere.credit), enseignantResponsable(matiere.enseignantResponsable){}
Matiere::~Matiere(){}

string Matiere::getNom()const{ return(nom); }
int Matiere::getCredit()const{ return(credit); }
Enseignant Matiere::getEnseignantResponsable()const{ return(enseignantResponsable); }

void Matiere::setNom(string nom){ this->nom = nom; }
void Matiere::setCredit(int credit){ this->credit = credit; }
void Matiere::setEnseignantResponsablr(Enseignant enseignantResponsable){ this->enseignantResponsable = enseignantResponsable; }

string Matiere::afficher()const{ return("Nom:\t"+ nom +"\tCredit:\t"+ to_string(credit) +"\tNom_enseignant:\t"+ enseignantResponsable.getNom() +"\tPrenom_enseignant:\t"+ enseignantResponsable.getPrenom() +"\tAge_enseignant:\t"+ to_string(enseignantResponsable.getAge()) +"\tNum_employe_enseignant:\t"+ to_string(enseignantResponsable.getNumEmploye()) +"\tSpecialisation_enseignant:\t"+ enseignantResponsable.getSpecialisation()); }

Cours::Cours()
{
    matiere.getNom()="";
    matiere.getEnseignantResponsable().getNom()="";
    matiere.getEnseignantResponsable().getNom()="";
    matiere.getEnseignantResponsable().getPrenom()="";
    matiere.getEnseignantResponsable().getSpecialisation()="";
}
Cours::Cours(Matiere matiere): matiere(matiere){}
Cours::Cours(const Cours & cours): matiere(cours.matiere), listeEtudiants(cours.listeEtudiants){}
Cours::~Cours(){}

Matiere Cours::getMatiere()const{ return(matiere); }
vector<Etudiant*> Cours::getListeEtudiants()const{ return(listeEtudiants); }

void Cours::setMatiere(Matiere matiere){ this->matiere = matiere; }
//void Cours::setListeEtudiants(vector<Etudiant*> listeEtudiants){ this->listeEtudiants = listeEtudiants; }

string Cours::afficher()const{ return("Nom:\t"+ matiere.getNom() +"\tCredit:\t"+ to_string(matiere.getCredit()) +"\tNom_enseignant:\t"+ matiere.getEnseignantResponsable().getNom() +"\tPrenom_enseignant:\t"+ matiere.getEnseignantResponsable().getPrenom() +"\tAge_enseignant:\t"+ to_string(matiere.getEnseignantResponsable().getAge()) +"\tNum_employe_enseignant:\t"+ to_string(matiere.getEnseignantResponsable().getNumEmploye()) +"\tSpecialisation_enseignant:\t"+ matiere.getEnseignantResponsable().getSpecialisation());}

void Cours::inscritEtudiant(Etudiant* etudiant)
{
    listeEtudiants.push_back(etudiant);
}
void Cours::deinscriptionEtudiant(int numEtudiant)
{
    for(int i=0; i<listeEtudiants.size(); i++)
    {
        if(listeEtudiants.at(i)->getNumEtudiant() == numEtudiant)
        {
            for(int j=i; j<listeEtudiants.size()-1; j++)
            {
            listeEtudiants.at(i)=listeEtudiants.at(i+1);
            }

            listeEtudiants.pop_back();

            if(listeEtudiants.size() == 0)
            {
                cout<<"La liste est vide"<<endl;
            }
            break;
        }
    }
}
void Cours::afficherListeEtudiants()const
{
    for(const auto temp:listeEtudiants)
    {
        cout<< temp->afficher() <<endl;
    }
}

void Universite::ajouterPersonne(Personne* p)
{
    listePersonnes.push_back(p);
}
void Universite::supprimerPersonne(string nom)
{
    for(auto it=listePersonnes.begin(); it!=listePersonnes.end(); it++)
    {
        if((*it)->getNom() == nom)
        {
            listePersonnes.erase(it);
            break;
        }
    }
}
void Universite::afficherPersonne()const
{
    if(listePersonnes.size()!=0)
    {
        cout<<"La liste des personnes est :"<<endl;
        for(auto it:listePersonnes)
        {
            cout<<it->afficher()<<endl;
        }
    }
    else
    {
        cout<<"La liste est vide"<<endl;
    }
}
void Universite::creerCours(Matiere matiere)
{
    Cours* c = new Cours(matiere);
    listesCours.push_back(c);
}
void Universite::supprimerCours(string nom)
{
    for(int i=0; i<listesCours.size(); i++)
    {
        if(listesCours.at(i)->getMatiere().getNom() == nom)
        {
            for(int j=i; j<listesCours.size()-1; j++)
            {
                listesCours.at(i)=listesCours.at(i+1);
            }
              listesCours.pop_back();

            if(listesCours.size() == 0)
            {
                cout<<"La liste est vide"<<endl;
            }
            break;
        }
    }
}
void Universite::afficherCours()const
{
    for(auto uni:listesCours)
    {
        cout<< uni->afficher() <<endl;
    }
}

void afficherMenu()
{
    cout << "===========================\n";
    cout << "   Gestion Universitaire   \n";
    cout << "===========================\n";
    cout << "1. Ajouter un étudiant\n";
    cout << "2. Ajouter un enseignant\n";
    cout << "3. Créer un cours\n";
    cout << "4. Afficher toutes les personnes\n";
    cout << "5. Afficher tous les cours\n";
    cout << "6. Quitter\n";
    cout << "===========================\n";
    cout << "Choisissez une option : ";
}