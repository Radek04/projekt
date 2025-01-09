#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int N=20;

int main(int argc, char** argv) {

	srand (time(NULL));

	//Deklarowanie zmiennych
	int tab[N]= {3,4,-7,3,1,3,1,-4,-2,-2};
	int iP=0,iK=0,suma=0;

	for(int i=0; i<N; i++) {
		tab[i]=rand()%21-10;
	}
	for(int i=0; i<N; i++) cout<<" "<<tab[i];
	cout<<endl;
	suma=0;
	for(iP=0; iP<N; iP++) {
		cout<<endl<<"IP: "<<iP<<endl;
		for(iK=iP; iK<=N; iK++) {
			suma+=tab[iK];
			cout<<"Suma: "<<suma<<" IP:  "<<iP<<" IK: "<<iK<<endl;
			if(suma==0 && (iK==iP || iK>iP)) {
				cout<<"[";
				for(int k=iP; k<=iK; k++) {
					cout<<setw(3)<<tab[k]<<",";
				}
				cout<<"]";
				cout<<endl;
			}

		}
		suma=0;
	}
	return 0;
}