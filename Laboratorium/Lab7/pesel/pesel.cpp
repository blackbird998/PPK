#include <iostream>
#include <string>
#include <fstream>
using namespace std;

short PESEL[11];
int valid = 0;

int getBirthYear();		// zwraca rok urodzenia z numeru PESEL
int getBirthMonth();	// zwraca miesi�c urodzenia z numeru PESEL
int getBirthDay();		// zwraca dzie� urodzenia z numeru PESEL
string getSex();		// zwraca p�e�
int checkSum();			// sprawdza sum� kontroln�

void PeselValidator(string PESELNumber); //funkcja sprawdzajaca czy pesel jest poprawny

int main()
{
	string PESEL;
	PESEL = "44100249422";
	//PESEL = "98011203073";

	PeselValidator(PESEL);
	if (valid == 1) {
		cout << "Numer PESEL " << PESEL << " jest prawidlowy\n" << endl;;
		cout << "Rok urodzenia: \t\t" << getBirthYear() << endl;
		cout << "Miesiac urodzenia: \t" << getBirthMonth() << endl;
		cout << "Dzien urodzenia: \t" << getBirthDay() << endl;
		cout << "Plec : \t\t\t" << getSex() << endl;
		cout << "=========================================" << endl << endl;
	}
	else {
		cout << "Numer PESEL " << PESEL << " jest nieprawidlowy" << endl;
		cout << "=========================================" << endl << endl;
	}






	ifstream plik_wejsciowy; //utworzenie obiektu klasy ifstream
	plik_wejsciowy.open("NumeryPESEL.txt"); //skojarzenie obiektu plik_wejsciowy z plikiem




	if (!plik_wejsciowy.is_open())		  //sprawdzenie czy plik zosta� otwarty
		return 0;
	
	string linia;
	int prawidlowe = 0;
	int nieprawidlowe = 0;
	while (!plik_wejsciowy.eof())
	{
		
		getline(plik_wejsciowy, linia);
		PESEL = linia;
		//cout << linia << endl;
		PeselValidator(PESEL);
		if (valid == 1) {
			cout << "Numer PESEL " << PESEL << " jest prawidlowy\n" << endl;;
			cout << "Rok urodzenia: \t\t" << getBirthYear() << endl;
			cout << "Miesiac urodzenia: \t" << getBirthMonth() << endl;
			cout << "Dzien urodzenia: \t" << getBirthDay() << endl;
			cout << "Plec : \t\t\t" << getSex() << endl;
			cout << "=========================================" << endl << endl;
			prawidlowe++;
		}
		else {
			cout << "Numer PESEL " << PESEL << " jest nieprawidlowy" << endl;
			cout << "=========================================" << endl << endl;
			nieprawidlowe++;
		}
	}
	cout << "Liczba prawidlowych nr: " << prawidlowe << endl;
	cout << "Liczba nieprawidlowych nr: " << nieprawidlowe << endl;

	plik_wejsciowy.close();
	system("pause");
	return 0;
}







int getBirthYear() {
	//funkcja ma zwr�ci� rok urodzenia wynikaj�cy z numeru PESEL
	//dwie pierwsze cyfry to rok urodzenia%100
	//do miesi�ca urodzenia zosta�a dodana liczba w zale�no�ci od roku urodzenia:
	//	dla lat 1800 - 1899 - 80
	//	dla lat 1900 - 1999 - 0
	//	dla lat 2000 - 2099 - 20
	//	dla lat 2100 - 2199 - 40
	//	dla lat 2200 - 2299 - 60
	// nale�y pobra� rok urodzenia (jego warto�� dziesi�tn� i jedno�ci) i nast�pnie na podstawie warro�ci liczby oznaczaj�cych miesi�ce ustali� kt�re to setlecie.
	/*
	tutaj wstaw sw�j kod
	*/
	int rok;
	int miesiac = PESEL[2] * 10 + PESEL[3];
	if(miesiac>80) rok = 1800 + PESEL[0] * 10 + PESEL[1];
	else if(miesiac>60) rok = 2200 + PESEL[0] * 10 + PESEL[1];
	else if(miesiac>40) rok = 2100 + PESEL[0] * 10 + PESEL[1];
	else if(miesiac>20) rok = 2000 + PESEL[0] * 10 + PESEL[1];
	else rok = 1900 + PESEL[0] * 10 + PESEL[1];
	return rok;
}

int getBirthMonth() {
	// funkcja ma zwr�ci� numer miesi�ca urodzenia wynikaj�cy z numeru PESEL 
	//w zale�no�ci od przedzia�u, w kt�rym jest liczba, nale�y od niej odj�� odpowiedni� warto��

	/*
	tutaj wstaw sw�j kod
	*/
	int miesiac = PESEL[2] * 10 + PESEL[3];
	if (miesiac>80) miesiac = PESEL[2] * 10 + PESEL[3]-80;
	else if (miesiac>60) miesiac = PESEL[2] * 10 + PESEL[3]-60;
	else if (miesiac>40) miesiac = PESEL[2] * 10 + PESEL[3]-40;
	else if (miesiac>20) miesiac = PESEL[2] * 10 + PESEL[3]-20;
	else miesiac = PESEL[2] * 10 + PESEL[3];

	return miesiac;
}

int getBirthDay() {
	// funkcja ma zwr�ci� numer dnia urodzenia wynikaj�cy z numeru PESEL 
	//nale�y pobra� odpowiednie warto�ci z numeru pesel i potraktowa� je jako dziesiatki i jedno�ci


	/*
	tutaj wstaw sw�j kod
	*/
	return PESEL[4]+PESEL[5];
}

string getSex() {
	// 1 oznacza m�czyzn�, 0 oznacza kobiet�
	/*
	tutaj wstaw sw�j kod
	*/
	bool sex=PESEL[10]%2;
	if (sex == 0) return "Kobieta";
	else return "Mezczyzna";
}

int checkSum() {
	//dodajemy do siebie kolejne pozycje nr pesel pomno�one przez wagi
	// 1 3 7 9 1 3 7 9 1 3
	// nast�pnie uzyskujemy reszt� z dzielenia przez 10
	// nast�pnie t� reszt� odejmujemy od 10
	// z uzyskanej r�nicy liczymy reszt� z dzielenia przez 10
	// je�eli uzyskana liczba jest r�wna 11 cyfrze numeru pesel, weryfikacja przebieg�a 
	// pomy�lnie to funkcja zwraca 1,			w przeciwnym wypadku 0
	//long long sum = PESEL[10] + PESEL[9] * 10 + PESEL[8] * 100 + PESEL[7] * 1000 + PESEL[6] * 10000 + PESEL[5] * 100000 + PESEL[4] * 1000000 + PESEL[3] * 10000000 + PESEL[2] * 100000000
	int sum = PESEL[0] * 1 + PESEL[1] * 3 + PESEL[2] * 7 + PESEL[3]*9+ PESEL[4]*1+ PESEL[5]*3+ PESEL[6]*7+ PESEL[7]*9+ PESEL[8]*1+PESEL[9]*3+PESEL[10];
	if(sum%10==0) return 1;
	//if ((10 - sum % 10) % 10 == 11) return 1;
	else return 0;
}


void PeselValidator(string PESELNumber) {
	int i;

	if (int(PESELNumber.length()) != int(11)) {
		valid = 0;
	}
	else {
		for (i = 0; i < 11; i++) {
			PESEL[i] = PESELNumber[i] - 48;
		}
		if (checkSum()) {
			valid = 1;
		}
		else {
			valid = 0;
		}
	}
}