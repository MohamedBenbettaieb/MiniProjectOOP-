#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Personne{
    protected:
        int id;
        string nom,prenom;
    public:
        Personne(int ID1,string N,string P){
            id=ID1;
            nom=N;
            prenom=P;
        }
        virtual ~Personne(){} // Virtual destructor
        virtual void afficher(){
            cout<<"l'id de cette personne est = "<<id<<endl;
            cout<<"nom : "<<nom<<" prenom : " <<prenom<<endl;
        }
        int get_id ()const{
            return id;
        }
        string get_nom ()const{
        return nom;}
        string get_prenom ()const{
        return prenom;}


};
class Note{
    private:
        double NoteControle;
        double NoteExamen;
    public:
        Note(double x, double y){
            NoteControle=x;
            NoteExamen=y;
        }
        ~Note(){}
        double getNoteControle() const{
            return NoteControle;
        }
        double getNoteExamen() const{
            return NoteExamen;
        }
};
class Etudiant:public Personne{
    private:
        vector<Note> Notes;
    public:
        Etudiant(int IDD,string NOMM,string Prenomm,vector<Note> vv):Personne(IDD,NOMM,Prenomm){
            Notes=vv;
        }
        vector<Note> getNote() const{
            return Notes;
        }
        double moyenne()const{
            double moyenne = 0.0;
            double totalControle = 0.0;
            double totalExamen = 0.0;
            for (const Note& note : Notes) {
                totalControle += note.getNoteControle();
                totalExamen += note.getNoteExamen();
            }
            double moyenneControle = totalControle / Notes.size();
            double moyenneExamen = totalExamen / Notes.size();
            moyenne = moyenneControle * 0.3 + moyenneExamen * 0.7;
            return moyenne;
            }
        void afficher(){
            Personne::afficher();
            cout<<"Les Notes de cet etudiant sont :"<<endl;
            for(int j=0;j<10;j++){
                    cout<<"La note de controle de la matiere num " <<j+1<<" est : "<<Notes[j].getNoteControle()<<" ; la note d'examen est : "<<Notes[j].getNoteExamen()<<endl;
        }
}
};
class Professeur: public Personne{
    private:
        string cours;
    public:
        Professeur(int ID,string N,string P,string C) : Personne(ID, N, P) { // Constructor initialization list
            cours=C;
        }
        ~Professeur(){}
        void afficher(){
            Personne::afficher();
            cout<<"Le cours assure par ce professeur est : "<<cours<<endl;
        }
        string get_cours ()const{
        return cours;}

};

class Personnel: public Personne{
    private:
        string metier;
    public:
        Personnel (int ID ,string N ,string P,string m) : Personne(ID, N, P) { // Constructor initialization list
            metier=m;
        }
        ~Personnel(){}
        void afficher(){
            Personne::afficher();
            cout<<"le metier de ce personnel est "<<metier<<endl;
        }
        string get_metier()const{
            return metier;}
};


int main(){
     Personne* personneArray[3];
    personneArray[0] = new Professeur(1, "Rhouma", "Mounir", "Physique");
    personneArray[1] = new Personnel(2, "Doe", "Jane", "Secretaire");
    vector<Note>vx={Note(10,3),Note(20,15.5),Note(20,18.5),Note(17,17),Note(15.25,15.75),Note(5,3),Note(10,10.5),Note(12,18.5),Note(14,17),Note(15.25,15.75)};
    personneArray[2]=new Etudiant(3,"Benbettaieb","Mohamed",vx);
    for(int i=0;i<3;i++){
        personneArray[i]->afficher();
        cout<<endl;
    }

    return 0;
}


