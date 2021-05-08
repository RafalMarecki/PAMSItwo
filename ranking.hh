#ifndef RANKING_HH
#define RANKING_HH

#include <string>
#include <fstream>
using namespace std;

class ranking
{
    private:
    int ROZM;
    string *TYTUL;
    int *OCENA; 

    public:
    ranking (int rozmiar); //KONSTRUKTOR BEZARGUMENTOWY
    ranking (const ranking & X); //KONSTRUKTOR KOPIUJĄCY

    string & operator [] (int i) const;
    int & operator [] (int i); 
    void wypisz ();
    void wypisz_statystyki();

    //SORTOWANIE
    int podzial (int p, int r); // Wywolywany w funkcji sortowanie_szybkie. Dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
    void sortowanie_szybkie (int p, int r); // Sortowanie szybkie
    void sortowanie_kubelkowe ();
    void scal (int start, int srodek, int koniec);
    void sortowanie_scalanie (int start, int koniec);
    
};

#endif