#include <iostream>
#include <time.h>

using namespace std;

int piramida(int A, int B);
int prostokat(int A, int B);
int losowanie(); //a<b while()

int main() {

/*	int A = 0;
	int B = 0;
	cout << "Podaj A i B: " << endl;
	cin >> A;
	cin >> B;
*/
	//piramida(A, B);
	//prostokat(A, B);
	losowanie();



	cout << endl;
	return 0;
}

int piramida(int A, int B) {
	int n = B - A;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i ; j++)
			cout << A;
		++A;
		cout<<endl;
	}
	return 0;
}

int prostokat(int A, int B) {
	

	//pierwsza linia
	for (int i = 1; i <= A+2;i++) {
		if (i == 1 || i == A+2) cout << "C";
		else cout << "A";
	}
	cout << endl;

	//srodkowe linie
	for (int j = 1; j <= B; j++) {
		for (int i = 1; i <= A + 2; i++) {
			if (i == 1 || i == A + 2) cout << "B";
			else cout << " ";
		}
		cout << endl;
	}

	//ostatnia linia
	for (int i = 1; i <= A + 2;i++) {
		if (i == 1 || i == A + 2) cout << "C";
		else cout << "A";
	}

	return 0;
}

int losowanie() {
	int A = 0;
	int B = 0;
	int r;
	double nasza_liczba;
	cout << "Podaj A i B: " << endl;
	cin >> A;
	cin >> B;
	//polowa przedzialu A + (B - A) / 2 nasza_liczba<(A+(B-A)/2

	srand(time(NULL));
	while(1){
	r = rand();
	nasza_liczba = double(r) / double(RAND_MAX);
	nasza_liczba = nasza_liczba* double(B - A);
	nasza_liczba = nasza_liczba + double(A);
	cout << nasza_liczba << endl;
	system("pause");
	}
	return 0;
}