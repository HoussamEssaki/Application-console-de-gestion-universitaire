#ifndef UNIVERSITE_HPP
#define UNIVERSITE_HPP

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Personne
{
    protected:
    string nom;
    string prenom;
    int age;

    public:
    Personne();
    Personne(string nom, string prenom, int age);
    Personne(const Personne & autre_personne);
    virtual ~Personne();

    string getNom() const;
    string getPrenom() const;
    int getAge() const;

    void setNom(string nom);
    void setPrenom(string prenom);
    void setAge(int age);

    virtual string afficher() const;
    
};

class Etudiant :public Personne
{
    private:
    int numEtudiant;
    string domaineEtude;

    public:
    Etudiant();
    Etudiant(string nom, string prenom, int age, int numEtudiant, string domaineEtude);
    Etudiant(const Etudiant & etudiant);
    ~Etudiant();

    int getNumEtudiant() const;
    string getDomaineEtude() const;

    void setNumEtudiant(int numEtudiant);
    void setDomaineEtude(string doamineEtude);

    string afficher() const override;
};

class Enseignant :public Personne
{
    private:
    int numEmploye;
    string specialisation;

    public:
    Enseignant();
    Enseignant(string nom, string prenom, int age, int numEmploye, string specialisation);
    Enseignant(const Enseignant & enseignant);
    ~Enseignant();

    int getNumEmploye() const;
    string getSpecialisation() const;

    void setNumEmploye(int numEmploye);
    void setSpecialisation(string specialisation);

    string afficher() const override;
};

class Matiere
{
    private:
    string nom;
    int credit;
    Enseignant enseignantResponsable;

    public:
    Matiere();
    Matiere(string nom, int credit, Enseignant enseignantResponsable);
    Matiere( const Matiere & matiere);
    ~Matiere();

    string getNom() const;
    int getCredit() const;
    Enseignant getEnseignantResponsable() const;

    void setNom(string nom);
    void setCredit(int credit);
    void setEnseignantResponsablr(Enseignant enseignantResponsable);

    string afficher() const;
};

class Cours
{
    private:
    Matiere matiere;
    vector<Etudiant*> listeEtudiants;

    public:
    Cours();
    Cours(Matiere matiere);
    Cours(const Cours & cours);
    ~Cours();

    Matiere getMatiere() const;
    vector<Etudiant*> getListeEtudiants() const;

    void setMatiere(Matiere matiere);
    //void setListeEtudiants(vector<Etudiant*> listeEtudiants);

    string afficher()const;
    void inscritEtudiant(Etudiant* etudiant);
    void deinscriptionEtudiant(int numEtudiant);
    void afficherListeEtudiants() const;
};

class Universite
{
    private:
    vector<Personne*> listePersonnes;
    vector<Cours*> listesCours;

    public:
    void ajouterPersonne(Personne* p);
    void supprimerPersonne(string nom);
    void afficherPersonne() const;

    void creerCours(Matiere matiere);
    void supprimerCours(string nom);
    void afficherCours()const;

};

void afficherMenu();

#endif // UNIVERSITE_HPP