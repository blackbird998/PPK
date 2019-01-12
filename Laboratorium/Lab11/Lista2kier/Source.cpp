#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct dane {
	string jakis_tekst;
	int jakas_liczba;
};

struct el_listy {
	dane jakies_dane;
	el_listy * next;
	el_listy * prev;
};

struct list_info {
	int licznik = 0;
	el_listy *head = nullptr;
	el_listy *tail = nullptr;
};

void dodaj_do_listy(list_info &lista, dane dane_do_dodania);
void wypisz(list_info &lista);

int main(int argc, char *argv[]) {
	
	list_info lista;
	for (int i = 0; i < 5; i++) {
		dane dane_do_dodania;
		dane_do_dodania.jakas_liczba = i;
		dane_do_dodania.jakis_tekst = "etc";
		dodaj_do_listy(lista, dane_do_dodania);	
	}
	wypisz(lista);

	system("pause");
	return 0;
}

void dodaj_do_listy(list_info &lista, dane dane_do_dodania) {
	el_listy * nowy_el_listy;
	nowy_el_listy = new el_listy;
	nowy_el_listy->jakies_dane = dane_do_dodania;
		if (lista.licznik == 0) {
			nowy_el_listy->next = nullptr;
			nowy_el_listy->prev = nullptr;
			lista.head = nowy_el_listy;
			lista.tail = nowy_el_listy;
		}
		else {
			el_listy *temp = lista.tail;
			temp->next = nowy_el_listy;
			nowy_el_listy->next = nullptr;
			nowy_el_listy->prev = lista.tail;
			lista.tail = nowy_el_listy;
		}
		lista.licznik++;
}

void wypisz(list_info &lista) {
	el_listy *temp = lista.head;
	while (temp!=nullptr){
		cout << "Dane: " << temp->jakies_dane.jakas_liczba << " " << temp->jakies_dane.jakis_tekst << endl;
		cout << "next " << temp->next << endl;
		cout << "prev " << temp->prev << endl;
		temp = temp->next;
	} 
}
