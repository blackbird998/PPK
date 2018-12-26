#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct przedmiot {
	string nazwa_przedmiotu;
	string prowadzacy;
};
struct student_z_listy {
	string imie;
	string nazwisko;
	string nr_albumu;
	string ocena;
	string data;
	przedmiot informacje_o_przedmiocie;

	student_z_listy *next;
};
struct list_info {
	int licznik=0;
	student_z_listy *head=nullptr;
};

bool dodaj_do_listy(string file_name, list_info &lista);//funkcja dodająca elementy z plików do listy
void wypiszDoPliku(list_info &lista);//funkcja wypisujaca zawartość listy do plików

int main(int argc, char *argv[]) {
	int licznik_kontrolny = 0;
	
	if (argc<3||(string)argv[1] != "-i") {
		cout << "Podano za malo lub bledne argumenty wywolania programu!!!" << endl;
		cout << "Pomoc programu Dziekanat." << endl;
		cout << "Program generuje pliki z ocenami studenta na podstawie podanych protokolow." << endl;
		cout << "Program mozna uruchomic wpisujac do lini polecen: dziekanat.exe -i nazwa_protokolu.txt" << endl;
		cout << "Mozna podac dowolna ilosc protokolow." << endl;
	}
	else {
		for (int i = 0; i < argc - 2; i++) {
			string file_name = argv[i+2];
			list_info lista;
			dodaj_do_listy(file_name, lista);
			wypiszDoPliku(lista);
			licznik_kontrolny++;
		}
	}
	cout << licznik_kontrolny << endl;
	system("pause");
	return 0;
}

bool dodaj_do_listy(string file_name, list_info &lista) {
	//otworzenie pliku
	ifstream plik_wejscia;
	plik_wejscia.open(file_name);
	//obsługa błędów
	if (!plik_wejscia.is_open()) {
		cout << "Blad otwarcia pliku!!!" << endl;
		return 1;
	}
	//========================================
	//pobranie wspólnych dla wszystkich studentów informacji o przedmiocie
	przedmiot informacje_o_przedmiocie;
	string linia;
	getline(plik_wejscia, linia);
	informacje_o_przedmiocie.nazwa_przedmiotu = linia;
	getline(plik_wejscia, linia);
	informacje_o_przedmiocie.prowadzacy = linia;
	//utworzenie nowego studenta
	while (!plik_wejscia.eof()) {
		//dodanie nowego studenta
		student_z_listy *student;
		student = new student_z_listy;
			//dodanie wspólnych informacji o przedmiocie
			student->informacje_o_przedmiocie = informacje_o_przedmiocie;
			//pobranie lini z danymi studenta
			getline(plik_wejscia, linia);
			//rozbicie "linia" na osobne zmienne
			stringstream ss;
			ss << linia;
			ss >> student->imie;
			ss >> student->nazwisko;
			ss >> student->nr_albumu;
			ss >> student->ocena;
			ss >> student->data;
			//=======================================
		if (lista.licznik == 0) {
			student->next = nullptr;
			lista.head = student;
		}
		else {
			student_z_listy *temp = lista.head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = student;
			student->next = nullptr;	
		}
		lista.licznik++;
	}
	plik_wejscia.close();
	return 0;
}

void wypiszDoPliku(list_info &lista) {
	student_z_listy *temp = lista.head;

	while (temp) {
		fstream wewy;
		wewy.open(temp->nr_albumu + ".txt", ios::in);
		if (!wewy.is_open()) {
			wewy.open(temp->nr_albumu+".txt", ios::out);
			wewy << temp->imie << "\t" << temp->nazwisko << "\n" <<"nr albumu: "<< temp->nr_albumu << "\n\n"<< temp->informacje_o_przedmiocie.prowadzacy << "\t" << temp->informacje_o_przedmiocie.nazwa_przedmiotu << "\t" << temp->ocena << "\t" << temp->data << endl;
			temp = temp->next;
			wewy.close();
		}
		else {
			wewy.close();
			wewy.open(temp->nr_albumu + ".txt", ios::out | ios::app);
			wewy << temp->informacje_o_przedmiocie.prowadzacy << "\t" << temp->informacje_o_przedmiocie.nazwa_przedmiotu << "\t" << temp->ocena << "\t" << temp->data << endl;
			temp = temp->next;
			wewy.close();
		}


//		cout << temp->imie << "\t" << temp->nazwisko << "\t" << temp->nr_albumu << endl;
//		cout << temp->informacje_o_przedmiocie.nazwa_przedmiotu << temp->informacje_o_przedmiocie.prowadzacy << "\t" << temp->ocena << "\t" << temp->data << endl;
//		temp = temp->next;
	}
}