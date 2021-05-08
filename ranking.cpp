#include "ranking.hh"
#include <iostream>
#include <string>
#include <cstring> //strcpy
#include <fstream>
using namespace std;

ranking::ranking (int rozmiar)
{
  ifstream dane;
  //dane.open ("projekt2_dane.csv");
  dane.open ("test.csv");

  //konstruowanie
  this->ROZM = rozmiar;
  this->TYTUL = new string [rozmiar];
  this->OCENA = new int [rozmiar]; 

  //zmienne pomocnicze
  int gdzie_kon, gdzie_pocz; // przechowuję miejsce przecinka początkowego i końcowego
  string pomoc_ocen, pomoc_tyt; // zmienne pomocnicze do tytułu i oceny
  int ocena; // zmienna do konwersji na int

  //zmienne główne
  string odczyt; // tu znajduje się odczytana linia
  int j = 0; // licznik rekordów

  //odczyt z pliku
  getline (dane, odczyt); // ignoruję te pierwszą linię w excelu
  while (j < this->ROZM && !dane.eof())
  {
    pomoc_tyt = ""; // resetujemy pole tytuł
    getline (dane, odczyt); // odczytuję linię 
    gdzie_kon = odczyt.rfind (','); // pozycja początkowego przecinka
    gdzie_pocz = odczyt.find_first_of (','); // pozycja końcowego przecinka
    
    for (int i=gdzie_pocz+1; i<gdzie_kon; i++) // podpisywanie tytułu
    {
      pomoc_tyt += odczyt [i];
    }
    this->TYTUL[j] = pomoc_tyt;

    if (odczyt[gdzie_kon+2] == '.' && gdzie_kon +2 < odczyt.size()) // podpisywanie oceny
    {
      pomoc_ocen [0] = odczyt [gdzie_kon+1];
      this->OCENA[j] = stoi(pomoc_ocen);
      j++;
    }
    if (odczyt[gdzie_kon+3] == '.' && gdzie_kon +3 < odczyt.size())
    {
      this->OCENA[j] = 10;
      j++;
    }
  }
  dane.close();
} 

string & ranking::operator [] (int i) const
{
  return this->TYTUL [i];
}

int & ranking::operator [] (int i) 
{
  return this->OCENA[i];
}

void ranking::wypisz ()
{
  for(int i=0; i < this->ROZM; i++)
  {
    cout<< this->TYTUL[i] << "  " << this->OCENA[i] << endl;
  }
}

void ranking::wypisz_statystyki()
{
  double mediana=0, srednia=0;
  double suma=0;
  for (int i=0; i<this->ROZM; i++)
  {
    suma += this->OCENA[i];
  }
  srednia = suma / this->ROZM;
  if (this->ROZM/2 % 2 == 0)
    mediana = (this->OCENA[this->ROZM/2 -1] + this->OCENA[this->ROZM/2]) / 2;
  else
    mediana = this->OCENA[(this->ROZM-1) / 2];

  cout << "Srednia ocen podanego rankingu wynosi: " << srednia <<endl;
  cout << "Medniana ocen podanego rankingu wynosi: " << mediana <<endl;
}

int ranking::podzial (int p, int r) // Wywolywane w funkcji sortowanie_szybkie. Dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
  int x = this->OCENA[p];  // punkt kontrolny (pivot)
  int i = p;  // zawsze na lewo
  int j = r;  // zawsze na prawo
  int tmp1;
  string tmp2;
  
  while (true) 
  {
    while (this->OCENA[j] > x) // zaczynamy od pierwszyego elem
      j--;
    while (this->OCENA[i] < x) 
      i++;
    if (i < j) // zamieniamy miejscami gdy i < j
    {
      tmp1 = this->OCENA[i];
      this->OCENA[i] = this->OCENA[j];
      this->OCENA[j] = tmp1;
      tmp2 = this->TYTUL[i];
      this->TYTUL[i] = this->TYTUL[j];
      this->TYTUL[j] = tmp2;
      i++;
      j--;
    }
    else // gdy i >= j zwracamy j jako punkt podzialu tablicy
      return j;  
 }
}

void ranking::sortowanie_szybkie (int p, int r) // sortowanie szybkie
{
  int q;
  if (p < r) 
  {	
    q = podzial (p, r); // dziele tablice na dwie czesci, gdzie q to punkt podzialu
    sortowanie_szybkie (p, q); // rekurencyjnie quicksort dla pierwszej czesci tablicy
    sortowanie_szybkie (q+1, r); // rekurencyjnie quicksort dla drugiej czesci tablicy
  }
}

void ranking::scal (int poczatek, int srodek, int koniec)
{
  // TABLICE POMOCNICZE
  int *ocena_pom = new int[koniec-poczatek+1]; 
  string *tytul_pom = new string[koniec-poczatek+1];
  // LICZNIKI ELEMENTÓW lewo(i) i prawo(j) tablicy oryginalnej, oraz licznik elementów tablicy pomocniczej(k)
  int i = poczatek, j = srodek+1, k = 0; 
 
  while (i <= srodek && j <= koniec) // jeżeli znajdujemy się w pierwszej części tablicy zaznaczono obrazowo klamerkami: <---{------|------}--->
  {
    if (this->OCENA[j] < this->OCENA[i]) // jeżeli ocena końcowa < ocena początkowa to ocena końcowa podpisywana jest na kolejne pole początkowe tablicy pomocniczej
    {
      ocena_pom[k] = this->OCENA[j];
      tytul_pom[k] = this->TYTUL[j++]; // przesuwam indeks z prawej strony (z końca) o jedno pole w lewo
    }
    else                               // jeżeli ocena końcowa >= ocena początkowa to ocena początkowa podpisywana jest na kolejne pole początkowe tablicy pomocniczej
    {
      ocena_pom[k] = this->OCENA[i]; 
      tytul_pom[k] = this->TYTUL[i++]; // przesuwam indeks z lewej strony (z początku) o jedno pole w prawo
    }
    k++;
  }
 
  if (i <= srodek) // jeżeli licznik j (środek) wyrównał się z końcem, a licznik i (początek) jest minejszy od środka; znaczy to, że oceny od i w prawo należy opdpisać pod kolejne elementy tabliczy pomocniczej
  {
    while (i <= srodek)
    {
      ocena_pom[k] = this->OCENA[i];
      tytul_pom[k] = this->TYTUL[i++];
      k++;
    }
  }
  else           // w przeciwnym przypadku należy podpisać oceny od j w prawo, pod kolejne indeksy tablicy pomocniczej
  {
    while (j <= koniec)
    {
      ocena_pom[k] = this->OCENA[j];
      tytul_pom[k] = this->TYTUL[j++];
      k++;
    }
}
 
  for (i = 0; i <= koniec-poczatek; i++) // podpisanie wartości elem. tab pomocniczych pod oryginalne zmienne
  {
    this->OCENA[poczatek+i] = ocena_pom[i]; 
    this->TYTUL[poczatek+i] = tytul_pom[i];
  }
}
 
void ranking::sortowanie_scalanie (int poczatek, int koniec)
{
  int srodek = (poczatek + koniec)/2;
 
  if (poczatek < koniec)
  {
    this->sortowanie_scalanie (poczatek, srodek); // rekurencyjne wywołanie sorta dla lewej strony tablicy
    this->sortowanie_scalanie (srodek+1, koniec); // rekurencyjne wywołanie sorta dla prawej strony tablicy
    this->scal (poczatek, srodek, koniec); // scalenie tablic 
  }
}

void ranking::sortowanie_kubelkowe () // sypie program
{ 
	int* buckets = new int [10];
  int* buckets_kopia = new int [10];
	
	for (int x=0; x<10; x++)
  {
    buckets [x] = 0;
  }
 
	for (int x=0; x<this->ROZM; x++)
  {
    buckets [this->OCENA[x]-1]++;
  }
  
  for (int x=0; x<10; x++)
  {
    buckets [x] = buckets_kopia[x];
  }

  string ** pomoc = new string *[10];
  for (int x=0; x<10; x++)
  {
    pomoc [x] = new string [buckets[x]];
  }
  
  for (int x=0; x<this->ROZM; x++)
	{
    pomoc[this->OCENA[x]-1][buckets_kopia[x]] = this->TYTUL[x];
    buckets_kopia[x]--;
	}
  for (int x=0; x<10; x++)
  {
    buckets [x] = buckets_kopia[x];
  }

  int ostatni_licznik=0;

  for (int x=0; x <10; x++)
  {
    int y;
    for (y = ostatni_licznik; y < buckets[x] + ostatni_licznik; y++)
    {
      this->OCENA[y] = x + 1;
      this->TYTUL[y] = pomoc[x][buckets_kopia[x]];
      buckets_kopia[x]--;
    }
    ostatni_licznik = y;
  }
}
