#include "ranking.hh"
#include <iostream>
#include <string>
#include <cstring> //strcpy
#include <fstream>
using namespace std;

ranking::ranking (int rozmiar)
{
  ifstream dane;
  dane.open ("projekt2_dane.csv"); // DO KOMPILOWANIA PLIKU main.cpp
  // dane.open ("test.csv"); // DO KOMPILOWANIA PLIKU test.cpp

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
    else // gdy i >= j zwraca j jako oś podziału tablicy
      return j;  
 }
}

void ranking::sortowanie_szybkie (int p, int r) // sortowanie szybkie
{
  int q;
  if (p < r) 
  {	
    q = podzial (p, r); // dziele tablice na dwie czesci, gdzie q to punkt podzialu
    sortowanie_szybkie (p, q); // rekurencyjnie quicksort dla pierwszej (lewej) czesci tablicy
    sortowanie_szybkie (q+1, r); // rekurencyjnie quicksort dla drugiej (prawej) czesci tablicy
  }
}

void ranking::scal (int poczatek, int srodek, int koniec)
{
  // TABLICE POMOCNICZE
  int *ocena_pom = new int [koniec-poczatek+1]; 
  string *tytul_pom = new string [koniec-poczatek+1];
  // LICZNIKI ELEMENTÓW lewo(i) i prawo(j) tablicy oryginalnej, oraz licznik elementów tablicy pomocniczej(k)
  int i = poczatek, j = srodek+1, k = 0; 
 
  while (i <= srodek && j <= koniec) // jeżeli znajdujemy się w pierwszej części tablicy zaznaczono obrazowo klamerkami
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

  // Zwalnianie pamieci
  delete [] ocena_pom;
  delete [] tytul_pom;
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

void ranking::sortowanie_kubelkowe () 
{ 
	int* kubelki = new int [10];
  int* kubelki_kopia = new int [10];
	
	for (int i=0; i<10; i++) // ZERUJE KUBEŁKI
    kubelki [i] = 0;
 
	for (int i=0; i<this->ROZM; i++) // LECI PRZEZ CAŁY PLIK I DODAJE DO KUBEŁKA 
    kubelki [this->OCENA[i]-1]++;

  string ** pomoc = new string *[10]; // TWORZY DWUWYMIAROWĄ DYNAMICZNA TABLICE STRING 
  for (int i=0; i<10; i++)
    pomoc [i] = new string [kubelki[i]];

  for (int i=0; i<10; i++) // KOPIUJE ILOŚĆ LICZB W KUBEŁKACH
    kubelki_kopia[i] = kubelki[i];
  
  for (int i=0; i<this->ROZM && kubelki_kopia[this->OCENA[i]-1]>0; i++) // PRZYPISUJE TYTUŁY DO DANEJ OCENY w tabeli pomocniczej: pomoc[OCENA][INDEKS]
	{
    pomoc [this->OCENA[i]-1] [kubelki_kopia[this->OCENA[i]-1]-1] = this->TYTUL[i];
    kubelki_kopia[this->OCENA[i]-1]--; // Przechodzi na poprzedni rekord (wypełniam tablicę od końca)
	}

  for (int i=0; i<10; i++) // KOPIUJE ILOŚĆ LICZB W KUBEŁKACH
    kubelki_kopia[i] = kubelki[i];

  int ostatni_licznik=0;
  for (int i=0; i<10; i++) // PODPISUJE WARTOŚCI DO POSZCZEGÓLNYCH REKORDÓW
  {
    int j;
    for (j = ostatni_licznik; j < kubelki[i] + ostatni_licznik && kubelki_kopia[i]>0; j++)
    {
      this->OCENA[j] = i + 1;
      this->TYTUL[j] = pomoc[i][kubelki_kopia[i]-1]; 
      kubelki_kopia[i]--; // Przechodzi na poprzedni rekord (podpisuję najpierw końcowe wartości, czyli tak naprawdę te pierwsze, bo wypełniałem tablicę pomoc[][] od końca)
    }
    ostatni_licznik = j;
  }

  for (int i = 0; i <10; i++) // Zwalnianie pamięci
    delete[] pomoc [i];
  delete [] pomoc;
  delete [] kubelki;
  delete [] kubelki_kopia;
}
