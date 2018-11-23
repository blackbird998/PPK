#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>


using namespace std;


int main() {

	srand(time(NULL));

	string tekst = "Ala ma kota, kot ma Ale";
	int dlTekstu = tekst.length();
	int losowa = (rand() % dlTekstu + 1);
	cout << losowa << endl;
	//cout << dlTekstu;
	string podtekst1;
	string podtekst2;
	for (int i = 0; i < losowa; i++) {
		podtekst1 += tekst[i];
		//cout<< tekst[i];
	}
	for (int i = losowa; i < dlTekstu; i++) {
		podtekst2 += tekst[i];
	}
	cout << podtekst1 << endl;
	cout << podtekst2 << endl;

	char zmienianyZnak;
	cout << "Podaj znak do zmiany: ";
	cin >> zmienianyZnak;
	/*
	char zmiana = 'ABC';
	for (int i = 0; i < dlTekstu; i++) {
		if (tekst[i] == zmienianyZnak) 	tekst[i] = zmiana;
	}
	cout << tekst << endl;
	*/

	string zmiana = "ABC";
	for (int i = 0; i < dlTekstu; i++) {
		if (tekst[i] == zmienianyZnak) cout<<zmiana;
		else cout << tekst[i];
	}
	cout << endl;

	char zm = 'G';

	replace(tekst.begin(), tekst.end(), zmienianyZnak, zm);
	cout << tekst << endl;


}
