#include <iostream>

using namespace std;

void suma(int &a, int b) {
	cout << &a << endl;
	int *adr_a = &a;

	cout << *adr_a << endl;
	*adr_a = a + b;
	cout << *adr_a << endl;
}

void zam(int &a, int &b) {
	cout << a << b << endl;
	int pom;
	int *wa = &a;
	int *wb = &b;
	pom = *wa;
	*wa = *wb;
	*wb = pom;
	cout << a << b << endl;
}

void tabDym(int n) {
	int tab[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		tab[i] = 1;
		cout << tab[i];
	}
	cout << endl;

	int x;
	cout << &x << " " << &x + 1 << endl;
	int min;
	int *wsk_na_p_tab;
	new int[n];
	wsk_na_p_tab = new int[n];
	for (int i = 0; i < n; i++) {

		wsk_na_p_tab[i] = 1;
		cout << new int[i]<<endl;
		cout << wsk_na_p_tab[i] << endl;
		//wyszukanie adresu o najmniejszej wartosci
		if (new int[i] < min) min = new int[i];
	}
	delete[] wsk_na_p_tab;
}

int main() {
	int zm1 = 9;
	int zm2 = 15;
	int zm3 = 0;
	int *adres_zm3 = &zm3;
	//cout << *adres_zm3 << endl;
	//zam(zm1, zm2);
	tabDym(10);
	/*
	
	cout << "Adr zm1: " << &zm1 << endl;
	cout << "Adr zm2: " << &zm2 << endl;
	*adres_zm3 = 2;
	cout << zm3 << endl;
	cout << &zm3 << endl;
	
	*/
	//suma(zm1, zm2);
	
	return 0;
}

