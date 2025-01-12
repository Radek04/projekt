#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;

const int N=20;

//Deklaracja funkcji
void wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]);
void wyszukiwanieDrugaWersja(int tab[N]);

int main(int argc, char** argv) {

	srand (time(NULL));

	//Deklarowanie zmiennych
	int tab[N];
	int iP=0,iK=0,suma=0;

	//Generowanie tablicy losowych liczb z przedziału od -10 do 10
	for(int i=0; i<N; i++) {
		tab[i]=rand()%21-10;
	}

	//Wyświetlanie tablicy
	for(int i=0; i<N; i++) cout<<" "<<tab[i];
	cout<<endl;

	double wynik1=0.0,wynik2=0.0;
	//Wywołanie funkcji brute force
	wyszukiwanieBruteForce(suma,iP,iK,tab);
	
	cout<<endl<<"Drugie rozwiazanie:"<<endl;

	wyszukiwanieDrugaWersja(tab);
	
	return 0;
}

//Uzupełnienie zadeklarowanej wcześniej funkcji
void wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]) {
	for(iP=0; iP<N; iP++) { //Pierwsza pętla zmieniająca wyszukiwany początek
		for(iK=iP; iK<N; iK++) {//Drugą pętla zmieniająca szukany koniec
			suma+=tab[iK];  //Sumowanie kolejnych wartości
			if(suma==0 && (iK==iP || iK>iP)) { // Sprawdzanie, czy wyszukane podciągi spełniają waruneki
				cout<<"[";
				for(int k=iP; k<=iK; k++) {
					cout<<setw(4)<<tab[k]<<","; // Wypisywanie
				}
				cout<<"]";
				cout<<endl;
			}

		}
		suma=0;
	}
}

void wyszukiwanieDrugaWersja(int tab[N]) {

	int tablicaSum[N];
	int sumaPom=0,h=0,z=0;


	//Generowanie tablicy pomocniczej w której przechowujemy wartości zsumowanych liczb
	for(int i=0; i<N; i++) {
		sumaPom+=tab[i];
		tablicaSum[i]=sumaPom;
	}
	cout<<endl;
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(tablicaSum[j]==0 && i==0) {
				cout<<"[ ";
				for(int k=0; k<=j; k++) {
					cout<<setw(4)<<tab[k]<<",";
				}
				cout<<" ]";
				cout<<endl;
			} else if(tablicaSum[j]-tablicaSum[i]==0 &&  j>i) {
				z=i;
				z+=1;
				cout<<"[ ";
				for(z; z<=j; z++) {
					cout<<setw(4)<<tab[z]<<",";
				}
				cout<<" ]";
				cout<<endl;
			}
		}
	}
}







