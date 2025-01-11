#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int N=20;

//Deklaracja funkcji
void wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]);

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
	
	//Wywołanie funkcji brute force
	wyszukiwanieBruteForce(suma,iP,iK,tab);

	return 0;
}

//Uzupełnienie zadeklarowanej wcześniej funkcji
void wyszukiwanieBruteForce(int suma,int iP,int iK,int tab[N]) {
	for(iP=0; iP<N; iP++) {
		for(iK=iP; iK<N; iK++) {
			suma+=tab[iK];
			if(suma==0 && (iK==iP || iK>iP)) {
				cout<<"[";
				for(int k=iP; k<=iK; k++) {
					cout<<setw(4)<<tab[k]<<",";
				}
				cout<<"]";
				cout<<endl;
			}

		}
		suma=0;
	}
}