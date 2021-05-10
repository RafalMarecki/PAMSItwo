/*|=========================================================================================|*/
/*|          PLIK SLUZY DO SPRAWDZENIA POPRAWNOSCI DZIALANIA ALAGORYTMOW SORTOWANIA         |*/
/*|=========================================================================================|*/

/*|=========================================================================================|*/
/*|               KOMPILACJA KOMENDĄ: g++ ranking.hh ranking.cpp test.cpp                   |*/
/*|=========================================================================================|*/

/*|======================================== UWAGA ==========================================|*/
/*| ABY URUCHOMIC TEST, W PLIKU ranking.cpp NALEŻY ZAKOMENTOWAC LINIE nr.11, A ODKOMENTOWAC |*/
/*|                                       LINIE nr.12                                       |*/
/*|=========================================================================================|*/

#include "ranking.hh"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
    int rozm_test = 20;
    ranking przed_sort (rozm_test);
    ranking sprawdzenie_quicksort (rozm_test);
    ranking sprawdzenie_kubelkowe (rozm_test);
    ranking sprawdzenie_scalanie (rozm_test);
    cout << "------------------------------\n\n";
    cout << "DANE PRZED SORTOWANIAMI:\n";
    przed_sort.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU SZYBKIM:\n"; 
    sprawdzenie_quicksort.sortowanie_szybkie(0, rozm_test-1);
    sprawdzenie_quicksort.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU PRZEZ SCALANIE:\n"; 
    sprawdzenie_scalanie.sortowanie_scalanie(0, rozm_test-1);
    sprawdzenie_scalanie.wypisz();
    cout << "------------------------------\n\n";
    cout << "DANE PO SORTOWANIU KUBELKOWYM:\n"; 
    sprawdzenie_kubelkowe.sortowanie_kubelkowe();
    sprawdzenie_kubelkowe.wypisz();

    return 0;
};