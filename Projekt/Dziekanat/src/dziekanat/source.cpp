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
	student_z_listy *prev;
};
struct list_info {
	int licznik_elementow = 0;
	student_z_listy *head = nullptr;
	student_z_listy *tail = nullptr;
};

bool dodajDoListyStudentow(const string& file_name, list_info &lista_studentow);//funkcja dodająca elementy z plików do listy
bool sortujDoListy(list_info &lista_studentow, list_info &posortowana_lista);//funkcja tworząca nową, posortowaną listę
void wypiszDoPliku(list_info &posortowana_lista);//funkcja wypisujaca zawartość posortowanej listy do plików
void usunListe(list_info &lista);//funkcja usuwająca listę

int main(int argc, char *argv[]) {
	
	if (argc < 3 || (string)argv[1] != "-i") {
		if ((string)argv[1] != "-h") cout << "Podano za malo lub bledne argumenty wywolania programu!!!" << endl;
		cout << "Pomoc programu Dziekanat." << endl;
		cout << "Program generuje pliki z ocenami studenta na podstawie podanych protokolow." << endl;
		cout << "Program mozna uruchomic wpisujac do lini polecen: dziekanat.exe -i nazwa_protokolu.txt" << endl;
		cout << "Mozna podac dowolna ilosc protokolow w dowolnej kolejnosci." << endl;
	}
	else {
		int liczba_przetworzonych_protokolow = 0;
		string file_name;
		list_info lista_studentow, posortowana_lista; 
		for (int i = 0; i < argc - 2; i++) {
			file_name = argv[i + 2];
			if(!dodajDoListyStudentow(file_name, lista_studentow)) liczba_przetworzonych_protokolow++;
		}
		sortujDoListy(lista_studentow, posortowana_lista);
		usunListe(lista_studentow);
		wypiszDoPliku(posortowana_lista);
		usunListe(posortowana_lista);
		cout << "Poprawnie przetworzono: " << liczba_przetworzonych_protokolow << " protokolow." << endl;
	}
	system("pause");
	return 0;
}

bool dodajDoListyStudentow(const string& file_name, list_info &lista_studentow) {
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
	do {
		getline(plik_wejscia, linia);
	} while (linia == "");
	informacje_o_przedmiocie.nazwa_przedmiotu = linia;
	do {
		getline(plik_wejscia, linia);
	} while (linia == "");
	informacje_o_przedmiocie.prowadzacy = linia;
	//utworzenie nowego studenta
	while (!plik_wejscia.eof()) {
		getline(plik_wejscia, linia);//pobranie lini z danymi studenta
		if (linia != "") {
			//dodanie nowego studenta
			student_z_listy *student;
			student = new student_z_listy;
			//dodanie wspólnych informacji o przedmiocie
			student->informacje_o_przedmiocie = informacje_o_przedmiocie;
			//rozbicie "linia" na osobne zmienne
			stringstream ss;
			ss << linia;
			ss >> student->imie;
			ss >> student->nazwisko;
			ss >> student->nr_albumu;
			ss >> student->ocena;
			ss >> student->data;
			//=======================================
			if (lista_studentow.licznik_elementow == 0) {
				student->next = nullptr;
				student->prev = nullptr;
				lista_studentow.head = student;
				lista_studentow.tail = student;
			}
			else {
				student_z_listy *temp = lista_studentow.tail;

				temp->next = student;
				student->next = nullptr;
				student->prev = lista_studentow.tail;
				lista_studentow.tail = student;
			}
			lista_studentow.licznik_elementow++;
		}
	}
	plik_wejscia.close();
	return 0;
}

bool sortujDoListy(list_info &lista_studentow, list_info &posortowana_lista) {
	if (lista_studentow.licznik_elementow == 0) {
		cout << "Lista jest pusta! Nie mozna sotrowac!";
		return 1;
	}
	student_z_listy *temp = lista_studentow.head;
	student_z_listy *posortowany_student;
	for (int i = 65; i <= 90; i++) {
		while (temp) {
			if (temp->informacje_o_przedmiocie.nazwa_przedmiotu[0] == i) {
				posortowany_student = new student_z_listy;
				if (posortowana_lista.licznik_elementow == 0) {//dla pierwszego elementu listy
					//wskaźniki w elemencie
					posortowany_student->next = nullptr;
					posortowany_student->prev = nullptr;
					//dane
					posortowany_student->imie = temp->imie;
					posortowany_student->nazwisko = temp->nazwisko;
					posortowany_student->nr_albumu = temp->nr_albumu;
					posortowany_student->informacje_o_przedmiocie = temp->informacje_o_przedmiocie;
					posortowany_student->ocena = temp->ocena;
					posortowany_student->data = temp->data;
					//wskaźniki w liście
					posortowana_lista.head = posortowany_student;
					posortowana_lista.tail = posortowany_student;
				}
				else {//dla kolejnych elementów listy
					student_z_listy *temp_at_end = posortowana_lista.tail;//skok do ostatniego elementu
					//nowy wskaźnik w dotychczasowym, ostatnim elemencie
					temp_at_end->next = posortowany_student;
					//wskaźniki w nowym elemencie
					posortowany_student->next = nullptr;
					posortowany_student->prev = posortowana_lista.tail;
					//dane
					posortowany_student->imie = temp->imie;
					posortowany_student->nazwisko = temp->nazwisko;
					posortowany_student->nr_albumu = temp->nr_albumu;
					posortowany_student->informacje_o_przedmiocie = temp->informacje_o_przedmiocie;
					posortowany_student->ocena = temp->ocena;
					posortowany_student->data = temp->data;
					//wskaźniki w liście - nowy ogon
					posortowana_lista.tail = posortowany_student;
				}
				posortowana_lista.licznik_elementow++;
			}
			temp = temp->next;//skok do następnego elementu
		}
		temp = lista_studentow.head;//"reset" wskaźnika temp
	}
	return 0;
}

void usunListe(list_info &lista) {
	student_z_listy *temp = lista.tail;//skok do ostatniego elementu
	while (temp) {
		if(temp->prev)temp->prev->next = nullptr;//odpięcie ostatniego elementu od poprzedniego jeśli ten istnieje
		lista.tail = temp->prev;//ustawienie nowego ogona
		delete(temp);//usunięcie odpiętego elementu
		temp = lista.tail;//skok do nowego ostatniego elementu
	}
}

void wypiszDoPliku(list_info &posortowana_lista) {
	student_z_listy *temp = posortowana_lista.head;
	while (temp) {
		fstream wewy;
		wewy.open(temp->nr_albumu + ".txt", ios::in);
		if (!wewy.is_open()) {
			wewy.open(temp->nr_albumu + ".txt", ios::out);
			wewy << temp->imie << "\t" << temp->nazwisko << "\n" << "nr albumu: " << temp->nr_albumu << "\n\n" << temp->informacje_o_przedmiocie.prowadzacy << "\t" << temp->informacje_o_przedmiocie.nazwa_przedmiotu << "\t" << temp->ocena << "\t" << temp->data << endl;
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
	}
}