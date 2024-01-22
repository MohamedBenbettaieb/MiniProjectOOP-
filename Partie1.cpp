#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
class Note{
    private:
        double NoteControle;
        double NoteExamen;
    public:
        Note(int x, int y){
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
class Etudiant{
    private:
        int identifiant ;
        string nom;
        string prenom;
        vector<Note> Notes;
    public:
        Etudiant(int id1,string N,string P,vector<Note>V){
            identifiant=id1;
            nom=N;
            prenom=P;
            Notes=V;
        }
        int getID() const{
            return identifiant;
        }
        string getNom () const{
            return nom;
        }
        string getPrenom() const{
            return prenom;
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
        vector<Note> getNote() const{
            return Notes;
        }
};
class Gestion{
    private:
        vector<Etudiant> Etudiants;
    public:
        void saisir_etudiant(){
            cout<<"Combien d'etudiants vont etre ajoutes ?"<<endl;
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Donner le nom et le prenom de l'etudiant numero "<<i+1<<endl;
                string nm,prn;
                cin>>nm>>prn;
                cout<<"Donner l'identifiant de cet etudiant"<<endl;
                int idd;
                cin>>idd;
                vector<Note>v(10,Note(0,0));
                for(int j=0;j<10;j++){
                    cout<<"Donner la note de controle et d'examen de la matiere num "<<j+1<<endl;
                    double x,y;
                    cin>>x>>y;
                    v[j]=Note(x,y);
                }
                Etudiants.push_back(Etudiant(idd,nm,prn,v));
            }
        }


    void creer_fichier() {
        ofstream fichier("etudiants.txt");

        if (fichier) {
            for (const Etudiant& etudiant : Etudiants) {
                fichier << etudiant.getID() << " " << etudiant.getNom() << " " << etudiant.getPrenom() << " ";
                for (const Note& note : etudiant.getNote()) {
                    fichier << note.getNoteControle() << " " << note.getNoteExamen() << " ";
                }
            fichier << endl;
        }
        fichier.close();
        cout << "Le fichier a ete cree avec succès." << endl;
    } else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }
}

void etudiants_reussis() {
    ofstream fichier("res.txt");

    if (fichier) {
        vector<Etudiant> etudiantsReussis;

        for (const Etudiant& etudiant : Etudiants) {
            if (etudiant.moyenne() >= 10.0) {
                etudiantsReussis.push_back(etudiant);
            }
        }

        sort(etudiantsReussis.begin(), etudiantsReussis.end(),
            [](const Etudiant& a, const Etudiant& b) { return a.moyenne() < b.moyenne(); });

        for (const Etudiant& etudiant : etudiantsReussis) {
            fichier << etudiant.getID() << " " << etudiant.getNom() << " " << etudiant.getPrenom() << " " << etudiant.moyenne() << endl;
        }
        fichier.close();
        cout << "Le fichier a ete cree avec succès." << endl;
    } else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }
}

        void Affiche() {
            ifstream fichier("res.txt");

            if (fichier) {
                string ligne;
                while (getline(fichier, ligne)) {
                    cout << ligne << endl;
                }
                fichier.close();
            } else {
                cout << "Erreur lors de l'ouverture du fichier." << endl;
            }
        }



};

int main() {
    //en testant la classe Gestion , cela va tester toutes les autres classes
    Gestion gestion;
    gestion.saisir_etudiant();
    gestion.creer_fichier();
    gestion.etudiants_reussis();
    gestion.Affiche();
    return 0;
}
