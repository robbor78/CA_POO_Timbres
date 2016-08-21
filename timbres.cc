#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  string nom;
  unsigned int annee;
  string pays;
  double valeur_faciale;

public:
  Timbre(string nom, unsigned int annee, string pays="Suisse", double valeur_faciale=1.0) :nom(nom), annee(annee), pays(pays), valeur_faciale(valeur_faciale) {}

  double vente() const {return valeur_faciale;}
  unsigned int age() const {return ANNEE_COURANTE - annee;}

  string getNom() const {return nom;}
  unsigned int getAnnee() const {return annee;}
  string getPays() const {return pays;}
  double getValeurFaciale() const {return valeur_faciale;}


  string getType() const {return "Timbre";}

  ostream& afficher(ostream &out) const {
    out << "de nom "<<getNom()<<" datant de "<<getAnnee()<<" (provenance "<<getPays()<<") ayant pour valeur faciale "<<getValeurFaciale()<<" francs";
    return out;
  }
};

ostream& operator<<(ostream &out, Timbre const &t) {
  out << t.getType() << " ";
  t.afficher(out);
  return out;
}

class Rare : public Timbre {
private:
  unsigned int nbExemplaires;
public:
  Rare(string nom, unsigned int annee, string pays, double valeur_facial, unsigned int nbExemplaires=100) : Timbre(nom,annee,pays,valeur_facial), nbExemplaires(nbExemplaires) {}

  unsigned int nb_exemplaires() const {return nbExemplaires;}
  string getType() const {return "Timbre rare";}

  ostream& afficher(ostream &out) const {
    out << "("<< nb_exemplaires() <<")";
    Timbre::afficher(out);
    return out;
  }
};

class Commemoratif : public Timbre {
public:
  Commemoratif(string nom, unsigned int annee, string pays, double valeur_facial): Timbre(nom,annee,pays,valeur_facial) {}

   string getType() const {return "Timbre commémoratif";}

};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
