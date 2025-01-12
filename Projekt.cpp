#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;

const int N=80;

//Deklaracja funkcji
int wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]);
int wyszukiwanieDrugaWersja(int tab[N]);

int main(int argc, char** argv) {

	srand (time(NULL));

	//Deklarowanie zmiennych
	int tab[N];
	int iP=0,iK=0,suma=0;
	double wynik1=0.0,wynik2=0.0;
	int liczbaOperacji1,liczbaOperacji2;

	//Generowanie tablicy losowych liczb z przedziału od -10 do 10
	for(int i=0; i<N; i++) {
		tab[i]=rand()%21-10;
	}

	//Wyświetlanie tablicy
	for(int i=0; i<N; i++) cout<<" "<<tab[i];
	cout<<endl;


	//Wywołanie funkcji brute force
	clock_t start = clock();
	liczbaOperacji1=wyszukiwanieBruteForce(suma,iP,iK,tab);
	clock_t end = clock();
	wynik1=double(end-start)/CLOCKS_PER_SEC;
	cout<<endl<<"Drugie rozwiazanie:"<<endl;
	clock_t start1 = clock();
	liczbaOperacji2=wyszukiwanieDrugaWersja(tab);
	clock_t end1 = clock();
	wynik2  = double(end1-start1)/CLOCKS_PER_SEC;
	cout<<"Czas poswiecony na wyszukiwanie w wersji podstawowej to: "<<wynik1<<", a liczba wykoanych operacji to: "<<liczbaOperacji1<<endl;
	cout<<"Czas poswiecony na wyszukiwanie w wersji drugiej to: "<<wynik2<<", a liczba wykoanych operacji to: "<<liczbaOperacji2;
	return 0;
}

//Uzupełnienie zadeklarowanej wcześniej funkcji
int wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]) {
	int liczbaOperacji = 0; // Zmienna zliczająca operacje
	for(iP=0; iP<N; iP++) { //Pierwsza pętla zmieniająca wyszukiwany początek
		liczbaOperacji++;
		suma=0;
		liczbaOperacji++;
		for(iK=iP; iK<N; iK++) {//Drugą pętla zmieniająca szukany koniec
			liczbaOperacji++;
			suma+=tab[iK];  //Sumowanie kolejnych wartości
			liczbaOperacji++;
			if(suma>((N-iK)*10) || suma<((N-iK)*-10)) {
				liczbaOperacji++;
				break;
			} else if(suma==0) { // Sprawdzanie, czy wyszukane podciągi spełniają waruneki
				liczbaOperacji++;
				cout<<"[";
				for(int k=iP; k<=iK; k++) {
					liczbaOperacji++;
					cout<<setw(4)<<tab[k]<<","; // Wypisywanie
				}
				cout<<"]";
				cout<<endl;
			}

		}

	}
	return liczbaOperacji;
}

int wyszukiwanieDrugaWersja(int tab[N]) {

	int tablicaSum[N];
	int sumaPom=0,h=0,z=0;
	int liczbaOperacji=0;

	//Generowanie tablicy pomocniczej w której przechowujemy wartości zsumowanych liczb
	for(int i=0; i<N; i++) {
		liczbaOperacji++;
		sumaPom+=tab[i];
		liczbaOperacji++;
		tablicaSum[i]=sumaPom;
		liczbaOperacji++;
	}
	cout<<endl;
	for(int i=0; i<N; i++) {
		liczbaOperacji++;
		for(int j=i; j<N; j++) {
			liczbaOperacji++;
			if(tablicaSum[j]==0 && i==0) {
				liczbaOperacji++;
				cout<<"[ ";
				for(int k=0; k<=j; k++) {
					liczbaOperacji++;
					cout<<setw(4)<<tab[k]<<",";
				}
				cout<<" ]";
				cout<<endl;
			} else if(tablicaSum[j]-tablicaSum[i]==0 &&  j>i) {
				liczbaOperacji++;
				z=i;
				liczbaOperacji++;
				z+=1;
				liczbaOperacji++;
				cout<<"[ ";
				for(z; z<=j; z++) {
					cout<<setw(4)<<tab[z]<<",";
					liczbaOperacji++;
				}
				cout<<" ]";
				cout<<endl;
			}
		}
	}
	return liczbaOperacji;
}
