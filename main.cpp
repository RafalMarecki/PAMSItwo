/*|=========================================================================================|*/
/*| KOMPILACJA KOMENDĄ: g++ ranking.hh ranking.cpp main.cpp                                 |*/
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
    int rozm_dziesiec = 10000, rozm_sto = 100000, rozm_piecset = 500000, rozm_X = 962903; // od 965 000
    double czas; clock_t start, stop;

    // DLA 10 TYS.
    ranking dziesiec_szybkie (rozm_dziesiec); 
    ranking dziesiec_scalanie (rozm_dziesiec);
    start = clock();
    dziesiec_szybkie.sortowanie_szybkie (0, rozm_dziesiec-1); stop = clock ();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "DLA 10 TYS." << endl;
    cout << "Czas sortowania 10 000 QUICKSORT: " << czas << endl; 
    start = clock(); dziesiec_scalanie.sortowanie_szybkie (0, rozm_dziesiec-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania 10 000 MERGESORT: " << czas << endl; 
    dziesiec_szybkie.wypisz_statystyki();
    
    // DLA 100 TYS.
    ranking sto (rozm_sto); 
    ranking sto_scalanie (rozm_sto);
    start = clock();
    sto.sortowanie_szybkie (0, rozm_sto-1); stop = clock ();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "DLA 100 TYS." << endl;
    cout << "Czas sortowania 100 000 QUICKSORT: " << czas << endl; 
    start = clock(); sto_scalanie.sortowanie_szybkie (0, rozm_sto-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania 100 000 MERGESORT: " << czas << endl; 
    sto.wypisz_statystyki();

    // DLA 500 TYS.
    ranking piecset (rozm_piecset); 
    ranking piecset_scalanie (rozm_piecset);
    start = clock();
    piecset.sortowanie_szybkie (0, rozm_piecset-1); stop = clock ();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "DLA 500 TYS." << endl;
    cout << "Czas sortowania 500 000 QUICKSORT: " << czas << endl; 
    start = clock(); piecset_scalanie.sortowanie_szybkie (0, rozm_piecset-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania 500 000 MERGESORT: " << czas << endl; 
    piecset.wypisz_statystyki();

    // DLA 962 903
    ranking X (rozm_X); 
    ranking X_scalanie (rozm_X);
    start = clock();
    X.sortowanie_szybkie (0, rozm_X-1); stop = clock ();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "DLA MAX WART. (962 903)" << endl;
    cout << "Czas sortowania 962 903 QUICKSORT: " << czas << endl; 
    start = clock(); X_scalanie.sortowanie_szybkie (0, rozm_X-1); stop = clock (); czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania 962 903 MERGESORT: " << czas << endl; 
    X.wypisz_statystyki();

    return 0;
};