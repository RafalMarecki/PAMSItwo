/*|=========================================================================================|*/
/*|                KOMPILACJA KOMENDĄ: g++ ranking.hh ranking.cpp main.cpp                  |*/
/*|=========================================================================================|*/

/*|======================================== UWAGA ==========================================|*/
/*| ABY URUCHOMIC main, W PLIKU ranking.cpp NALEŻY ODKOMENTOWAC LINIE nr.11, A ZAKOMENTOWAC |*/
/*|                                       LINIE nr.12                                       |*/
/*|=========================================================================================|*/

#include "ranking.hh"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdio> // CLOCKS_PER_SEC
using namespace std;

int main ()
{
    int rozm_dziesiec = 10000, rozm_sto = 100000, rozm_piecset = 500000, rozm_siedemset = 700000, rozm_MAX = 962903; // od 965 000
    double czas; clock_t start, stop;

    // DLA 10 TYS.
    ranking dziesiec_szybkie (rozm_dziesiec), dziesiec_scalanie (rozm_dziesiec), dziesiec_kubelkowe (rozm_dziesiec);
    cout << "DLA 10 TYS." << endl;
    start = clock(); dziesiec_szybkie.sortowanie_szybkie (0, rozm_dziesiec-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Szybkie
    cout << "Czas sortowania SZYBKIEGO 10 000: " << czas << " s." <<endl;  
    start = clock(); dziesiec_scalanie.sortowanie_scalanie (0, rozm_dziesiec-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Scalanie
    cout << "Czas sortowania SCALANIE 10 000: " << czas << " s." <<endl; 
    start = clock(); dziesiec_kubelkowe.sortowanie_kubelkowe (); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Kubelkowe
    cout << "Czas sortowania KUBELKOWEGO 10 000: " << czas << " s." <<endl << "-----------------------------------------------\n"; 
    dziesiec_szybkie.wypisz_statystyki();

    // DLA 100 TYS.
    ranking sto_szybkie (rozm_sto), sto_scalanie (rozm_sto), sto_kubelkowe (rozm_sto);
    cout << endl << "DLA 100 TYS." << endl;
    start = clock(); sto_szybkie.sortowanie_szybkie (0, rozm_sto-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Szybkie
    cout << "Czas sortowania SZYBKIEGO 100 000: " << czas << " s." <<endl;  
    start = clock(); sto_scalanie.sortowanie_scalanie (0, rozm_sto-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Scalanie
    cout << "Czas sortowania SCALANIE 100 000: " << czas << " s." <<endl;  
    start = clock(); sto_kubelkowe.sortowanie_kubelkowe (); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Kubelkowe
    cout << "Czas sortowania KUBELKOWEGO 100 000: " << czas << " s." <<endl << "-----------------------------------------------\n"; 
    sto_szybkie.wypisz_statystyki();

    // DLA 500 TYS.
    ranking piecset_szybkie (rozm_piecset), piecset_scalanie (rozm_piecset), piecset_kubelkowe (rozm_piecset);
    cout << endl << "DLA 500 TYS." << endl;
    start = clock(); piecset_szybkie.sortowanie_szybkie (0, rozm_piecset-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Szybkie
    cout << "Czas sortowania SZYBKIEGO 500 000: " << czas << " s." <<endl; 
    start = clock(); piecset_scalanie.sortowanie_scalanie (0, rozm_piecset-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Scalanie
    cout << "Czas sortowania SCALANIE 500 000: " << czas << " s." <<endl; 
    start = clock(); piecset_kubelkowe.sortowanie_kubelkowe (); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Kubelkowe
    cout << "Czas sortowania KUBELKOWEGO 500 000: " << czas << " s." <<endl << "-----------------------------------------------\n"; 
    piecset_szybkie.wypisz_statystyki();

    // DLA 700 TYS.
    ranking siedemset_szybkie (rozm_siedemset), siedemset_scalanie (rozm_siedemset), siedemset_kubelkowe (rozm_siedemset);
    cout << endl << "DLA 700 TYS." << endl;
    start = clock(); siedemset_szybkie.sortowanie_szybkie (0, rozm_siedemset-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Szybkie
    cout << "Czas sortowania SZYBKIEGO 700 000: " << czas << " s." <<endl; 
    start = clock(); siedemset_scalanie.sortowanie_scalanie (0, rozm_siedemset-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Scalanie
    cout << "Czas sortowania SCALANIE 700 000: " << czas << " s." <<endl; 
    start = clock(); siedemset_kubelkowe.sortowanie_kubelkowe (); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Kubelkowe
    cout << "Czas sortowania KUBELKOWEGO 700 000: " << czas << " s." <<endl << "-----------------------------------------------\n"; 
    siedemset_szybkie.wypisz_statystyki();

    // DLA 962 903
    ranking MAX_szybkie (rozm_MAX), MAX_scalanie (rozm_MAX), MAX_kubelkowe (rozm_MAX);
    cout << endl << "DLA MAX WART. (962 903)" << endl;
    start = clock(); MAX_szybkie.sortowanie_szybkie (0, rozm_MAX-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Szybkie
    cout << "Czas sortowania SZYBKIEGO max wartosci: " << czas << " s." <<endl; 
    start = clock(); MAX_scalanie.sortowanie_scalanie (0, rozm_MAX-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Scalanie
    cout << "Czas sortowania SCALANIE max wartosci: " << czas << " s." <<endl; 
    start = clock(); MAX_kubelkowe.sortowanie_kubelkowe (); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC; // Kubelkowe
    cout << "Czas sortowania KUBELKOWEGO max wartosci: " << czas << " s." << endl << "-----------------------------------------------\n"; 
    MAX_szybkie.wypisz_statystyki();

    getchar();
    
    return 0;
};