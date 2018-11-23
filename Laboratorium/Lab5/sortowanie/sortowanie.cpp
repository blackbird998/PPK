#include <iostream>
#include <time.h>


using namespace std;
const int n = 5;
int tab[n] = { 1, 12, 89, 5, 70 };

int main() {

	srand(time(NULL));
	int wartosc = 0;
	cout << "1. Wypelnij tablice 4 elementowa." << endl;
	cout << "2. Wylosuj tablice 1000 elementowa." << endl;
	cin >> wartosc;
	cout << endl;
	int tab1[4];
	int tab2[1000];
	float suma=0;
	switch (wartosc) {
		case 1:
			for (int i = 0; i < 4; i++) {
				cin >> tab1[i];
				suma += tab1[i];
			}
			for (int i = 0; i < 4; i++)
				for (int j = 1; j < 4 - i; j++) {
					if (tab1[j - 1]>tab1[j]) {
						swap(tab1[j - 1], tab1[j]);
					}
				}
			for (int i = 0; i < 4; i++) cout << tab1[i] << " ";
			cout << endl;
			cout << "Wartosc min: " << tab1[0] << endl;
			cout << "Wartosc max: " << tab1[3] << endl;
			cout << "Srednia: " << suma / 4.0;
		break;
		case 2:
			for (int i = 0; i < 1000; i++) {
				tab2[i]= (rand() % 100+1);
				suma += tab2[i];
				//cout << tab2[i] << " ";
			}
			for (int i = 0; i < 1000; i++)
				for (int j = 1; j < 1000 - i; j++) {
					if (tab2[j - 1]>tab2[j]) {
						swap(tab2[j - 1], tab2[j]);
					}
				}
			for (int i = 0; i < 1000; i++) cout << tab2[i] << " ";
			cout << endl;
			cout << "Wartosc min: " << tab2[0] << endl;
			cout << "Wartosc max: " << tab2[999] << endl;
			cout << "Srednia: "<< suma / 1000.0;
			cout << endl;

			//histogram poziomy
			int zakres1, zakres2, zakres3, zakres4;
			zakres1 = zakres2 = zakres3 = zakres4 = 0;
			for (int j = 0; j < 1000; j++) {
				if (tab2[j] <26) zakres1++;
				else if (tab2[j] < 51) zakres2++;
				else if (tab2[j] < 76) zakres3++;
				else zakres4++;
			}
			for (int j = 0; j < zakres1/10; j++) cout << "*";
			cout << endl;
			for (int j = 0; j < zakres2/10; j++) cout << "*";
			cout << endl;
			for (int j = 0; j < zakres3/10; j++) cout << "*";
			cout << endl;
			for (int j = 0; j < zakres4/10; j++) cout << "*";
			cout << endl;
			cout << endl;
			//int histogram[y][x];

			


		break;
		default: cout << "Bledna wartosc!";
	}
	cout << endl;
}
//switch zapelnainie tablicy 4 elementy, 1000 elementow losowych 1-100, sortowanie, min, max, srednia

