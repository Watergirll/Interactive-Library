#include <iostream>
#include <vector>
#include <optional>
using std::string;

class Carte {
private:
    string titlu;
    string autor;
    string genLiterar;
    int numarPagini;
    int anPublicatie;
    string zodiacSignC;
    string anotimpC;

public:
    // Constructor de initializare prin lista
    Carte(string t, string a, string g, int nP, int an, string zS, string anot) : titlu(t), autor(a), genLiterar(std::move(g)), numarPagini(nP), anPublicatie(an), zodiacSignC(zS), anotimpC(anot) {}

    //Cc
    Carte (const Carte& c1): Carte(c1.titlu, c1.autor, c1.genLiterar, c1.numarPagini, c1.anPublicatie, c1.zodiacSignC, c1.anotimpC) {}//aici apelez constructorul init -> overloading

    Carte& operator= (const Carte& c) {
        titlu = c.titlu;
        autor = c.autor;
        genLiterar = c.genLiterar;
        numarPagini = c.numarPagini;
        anPublicatie = c.anPublicatie;
        zodiacSignC = c.zodiacSignC;
        anotimpC = c.anotimpC;
        return *this;
    }
    //destructor
    ~Carte()  {std::cout<<"Aceasta carte a fost eliminata din colectie"<<std::endl;}


    // Metode pentru accesarea datelor cărții
    string getTitlu() const { return titlu; }
    string getAutor() const { return autor; }
    string getGenLiterar() const { return genLiterar; }
    int getnumarPagini() const {return numarPagini;}
    int getAnPublicatie() const { return anPublicatie; }
    string getzodiacSign() const { return zodiacSignC; }
    string getAnotimp() const { return anotimpC; }


    //afisare a datelor despre carte
    friend std::ostream& operator<<(std::ostream& os, const Carte& c) {
        os <<  c.titlu << " " << c.autor << " " << c.genLiterar << " " << c.numarPagini << " " << c.anPublicatie << std::endl;
        return os;
    }

};


class Taste {
private:
    string genLit;
    std::optional <string> autor;
    string zodiacSign;
    int anMax;
    int anMin;
    int lenMin;
    int lenMax;
public:
    //Constructor
    Taste (string gL, string a, string zS, int anmin, int anmax, int lmin, int lmax) : genLit(gL), autor(a), zodiacSign(zS), anMin(anmin), anMax(anmax), lenMin(lmin), lenMax(lmax) {}

    //getters
    auto getautor() const { return autor; }
    [[nodiscard]] string getgenLit() const { return genLit; }
    string getzodiacSign() const {return zodiacSign;}
    int getlenMin() const {return lenMin;}
    int getlenMax() const { return lenMax; }
    int getanMax() const { return anMax; }
    int getanMin() const { return anMin; }

    //afisare a datelor despre Taste
    friend std::ostream& operator<<(std::ostream& os, const Taste& t) {
        os << t.genLit << " " << t.zodiacSign<< std::endl;
        //INTREBARE: cum pot afisa ceva care e optional cum e aici "autor"?????
        return os;
    }
};

/*
 * // Clasa pentru evaluarea stării de spirit a utilizatorului și recomandarea unei cărți
class Mood {
private:
    //voi face un sistem pe note pt mai multe mood uri posibile pe care il voi implementa si pt carti -> ceva cu inheritance
    string anotimpM;

public:
    // Constructor
    Mood(string anot) : anotimpM(anot) {}

};*/


// Clasa pentru gestionarea întregii biblioteci
class Biblioteca {
private:
    //un struct pt set flag
    //de cautat cppref standard std::chrono time_point -> update carti

    std::vector<Carte> colectieCarti;

public:
    // Constructor
    Biblioteca() : colectieCarti(std::vector<Carte>()) {}

    // Constructor de copiere
    Biblioteca(const Biblioteca& altaBiblioteca) {
        colectieCarti = altaBiblioteca.colectieCarti;
    }

    // Metoda pentru adăugarea de cărți
    void adaugaCarte(const Carte& carte) {
        colectieCarti.push_back(carte);
    }
    //Metoda pentru stergerea unui elem din vector - marcare inactiva

    // Metoda pentru a obține o carte din colecție pe baza indexului
    Carte getCarteDinColectie(int index) {
        // Verificăm dacă indexul este în limitele vectorului
        if(index >= 0 && index < colectieCarti.size()) {
            return colectieCarti[index];
        } else {
            throw std::out_of_range("Indexul este în afara limitelor colecției de cărți.");
        }
    }

    // Metoda pentru recomandarea unei cărți în funcție de starea de spirit
    Carte recomandaCarte(const Taste& userTaste) {
        // Logica de recomandare a cărții
        int maxScore = 0, score = 0;
        Carte& c = colectieCarti[0];

       for(auto const &carte : colectieCarti)
       {
            //logica de selectare a cartii potrivite -> mai am de lucru

            if (userTaste.getzodiacSign() == carte.getzodiacSign()){
                score += 10;
            }
            //alte if - uri dupa ce voi face clasa cu inheritance
            if (score > maxScore) {
                c = carte;
                maxScore = score;
            }
            score = 0;
        }
        return c; // Returnează prima carte ca exemplu
    }
};

int main(){
    //construiesc Biblioteca
    Biblioteca B;
    Carte c1("Titanic Vals", "Tudor Musatescu", "drama", 100, 1932, "leu", "vara"), c2("Plumb", "George Bacovia", "poezie", 100, 1916, "scorpion", "toamna");
    Biblioteca biblioteca;
    biblioteca.adaugaCarte(c1);
    biblioteca.adaugaCarte(c1);

    //inregistrez Taste ul userului
    Taste userTaste("poezie", "", "scorpion", 2000, 1900, 10, 500);

    std::cout<<biblioteca.recomandaCarte(userTaste);
    return 0;
}
