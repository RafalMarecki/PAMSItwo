/*|=========================================================================================|*/
/*| KOMPILACJA KOMENDĄ: g++ ranking.hh ranking.cpp test.cpp                                 |*/
/*|=========================================================================================|*/

#include "ranking.hh"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
    int rozm_test = 10;
    ranking przed_sort (rozm_test);
    ranking sprawdzenie_quicksort (rozm_test);
    ranking sprawdzenie_kubelkowe (rozm_test);
    ranking sprawdzenie_scalanie (rozm_test);
    cout << "DANE PRZED SORTOWANIAMI:\n";
    przed_sort.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU SZYBKIM:\n"; 
    sprawdzenie_quicksort.sortowanie_szybkie(0, rozm_test-1);
    sprawdzenie_quicksort.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU KUBELKOWYM:\n"; 
    sprawdzenie_kubelkowe.sortowanie_kubelkowe();
    sprawdzenie_kubelkowe.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU PRZEZ SCALANIE:\n"; 
    sprawdzenie_scalanie.sortowanie_scalanie(0, rozm_test-1);
    sprawdzenie_scalanie.wypisz();

    return 0;
};