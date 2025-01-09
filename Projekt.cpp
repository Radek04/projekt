#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int N=20;

int main(int argc, char** argv) {

	srand (time(NULL));

	//Deklarowanie zmiennych
	int tab[N];
	int i=0,j=0;
	
	for(i=0; i<N; i++) {
		tab[i]=rand()%21-10;
	}
	for(i=0; i<N; i++) cout<<" "<<tab[i];
	return 0;
}