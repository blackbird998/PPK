#include <iostream>
#include <math.h>
using namespace std;



int main(){
	int wartosc = 0;
	cout << "Podaj liczbe calkowita" << endl;
	cin >> wartosc;
	int max= wartosc;
	int min= wartosc;
	

	do {
		cout << "Podaj liczbe calkowita" << endl;
		cin >> wartosc;
		if (wartosc > max) max = wartosc;
		if (wartosc < min) min = wartosc;
		


		
	} while (wartosc !=  pow(2, 15));
	cout << "Min="<< min << ", " << "Max="<< max << endl;

/*
//r�wnanie kwadratowe
	cout << "Podaj a: ";
	float a = 0;
	cin >> a;
	cout << "Podaj b: ";
	float b = 0;
	cin >> b;
	cout << "Podaj c: ";
	float c = 0;
	cin >> c;

	float delta = b*b - 4 * a*c;
	//cout << "Delta jest rowna: " << delta << endl;
	cout << a << "x^2+" << b << "x" << "+" << c << endl;
	if (a == 0) {
		cout << "Rownanie nie jest rownaniem kwadratowym!" << endl;
	}	
	else {
		if (delta < 0) {
			cout << "Delta jest ujemna, brak pierwiastkow" << endl;
		}
		else {
			if (delta == 0) {
				float x0 = -b / (2 * a);
				cout << "x0 = " << x0 << endl;
			}
			else {
				float x1 = (-b - sqrt(delta)) / (2 * a);
				float x2 = (-b + sqrt(delta)) / (2 * a);
				cout << "x1=" << x1 <<", "<< "x2=" << x2 << endl;
			}
			
		}
	}

*/

/*
//kalkulator
	cout << "Suma a i b to: " << a + b << endl;
	cout << "Roznica a i b to: " << a - b << endl;
	cout << "Iloczyn a i b to: " << a * b << endl;
	if (b != 0)
		cout << "Iloraz a i b to: " << a / b << endl;
	else
		cout << "Nie mo�na dzieli� przez zero!" << endl;
*/
	

	return 0;
}

