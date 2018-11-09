#include <iostream>
#include <time.h>
//#include <string>

using namespace std;

int tablica1d();
int tablica2d();
// tablica liczniki[4]

int main() {

	srand(time(NULL));
	cout << "Tablica 1d:" << endl;
	tablica1d();

	

	cout << "Tablica 2d:" << endl;
	tablica2d();

	


}


int tablica1d() {
	
	int tablica_losowa[20];
	int zakres1, zakres2, zakres3, zakres4;
	zakres1 = zakres2 = zakres3 = zakres4 = 0;

	for (int i = 0; i < 20; i++) {
	tablica_losowa[i] = (rand()%101);
	//cout << tablica_losowa[i] << endl;
	if (tablica_losowa[i] < 25) zakres1++;
	else if (tablica_losowa[i] < 51) zakres2++;
	else if (tablica_losowa[i] < 76) zakres3++;
	else zakres4++;

	}

	for (int i = 0; i < zakres1; i++) cout << "x";
	cout << endl;

	for (int i = 0; i < zakres2; i++) cout << "x";
	cout << endl;

	for (int i = 0; i < zakres3; i++) cout << "x";
	cout << endl;

	for (int i = 0; i < zakres4; i++) cout << "x";
	cout << endl;
	
	return 0;
}

int tablica2d() {
	int tablica_losowa2d[4][100];
	int zakres1, zakres2, zakres3, zakres4;
	char tablica_znakow[4];
	cout << "Podaj znaki do wykresu: " << endl;
	for (int i = 0; i < 4;i++) cin >> tablica_znakow[i];
	
	for (int i = 0; i < 4; i++) {
		zakres1 = zakres2 = zakres3 = zakres4 = 0;
		for (int j = 0; j < 100; j++) {
			tablica_losowa2d[i][j] = (rand() % 101);
			//cout << tablica_losowa2d[i][j] << endl;
			if (tablica_losowa2d[i][j] < 25) zakres1++;
			else if (tablica_losowa2d[i][j] < 51) zakres2++;
			else if (tablica_losowa2d[i][j] < 76) zakres3++;
			else zakres4++;
		}
		char znak;
		if (i == 0) znak = tablica_znakow[i];
		else if (i == 1) znak = tablica_znakow[i];
		else if (i == 2) znak = tablica_znakow[i];
		else znak = tablica_znakow[i];

		for (int j = 0; j < zakres1; j++) cout << znak;
		cout << endl;
		for (int j = 0; j < zakres2; j++) cout << znak;
		cout << endl;
		for (int j = 0; j < zakres3; j++) cout << znak;
		cout << endl;
		for (int j = 0; j < zakres4; j++) cout << znak;
		cout << endl;
		cout << endl;
	}
	return 0;
}