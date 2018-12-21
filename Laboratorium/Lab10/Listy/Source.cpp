#include <iostream>
#include <string>

// https://www.p-programowanie.pl/cpp/lista-jednokierunkowa-c/

using namespace std;

struct DANE {
	int jakas_liczba;
	string jakis_napis;
};

struct ELListy {
	DANE pole_danych;
	ELListy * next;
};

struct ListInfo {
	int Licznik;
	ELListy *h;
};

void add_beg(DANE dane_do_dodania, ListInfo &info) {
	ELListy *element_listy;
	element_listy = new ELListy;
	element_listy->pole_danych = dane_do_dodania;
	if (info.Licznik == 0) {
		element_listy->next = NULL;
		info.h = element_listy;
	}
	else {
		ELListy * temp = info.h;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = element_listy;
		element_listy->next = NULL;
	}
	info.Licznik++;
}

void wypiszListe(ListInfo *MojaLista) {
	ELListy *temp = MojaLista->h;
	while (temp) {
		cout << "Zawartosc jakas_liczba: "<<temp->pole_danych.jakas_liczba << endl;
		cout << "Adres obecnego elementu: "<<temp << endl;
		temp = temp->next;
		cout << "Adres nastepnego elementu: " << temp << endl;
	}
}

int main() {

	ListInfo *MojaLista;
	MojaLista = new ListInfo;
	MojaLista->Licznik = 0;
	MojaLista->h = NULL;
	DANE pDane;

	pDane.jakas_liczba = 10;
	pDane.jakis_napis = "przykladowy napis";
	
	for (int i = 0; i < 5; i++) {
		pDane.jakas_liczba = i;
		add_beg(pDane, *MojaLista);
	}
	wypiszListe(MojaLista);

	delete(MojaLista);

	return 0;
}