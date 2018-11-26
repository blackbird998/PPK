
//Demonstracja r�nych mechanizm�w w dostepie do plik�w, 
//przez co kod nie prezentuje konsekwentnie jednolitego stylu
//Materia�y pomocnicze do wyk�adu z Podstaw Programowania Komuter�w
//Przyk�ad opracowany na podstawie S.Prata, Szko�a Programowania, J�zyk C++

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int NAME_SIZE = 20;
using namespace std;

struct clientData
{
	unsigned int accNum;
	char lastName[NAME_SIZE];
	char firstname[NAME_SIZE];
	double balance;
};

int main()
{
	string fileName_ = "credit.dat";
	clientData client;
	unsigned int accountNum = 0;

	//========================================================================
	//wyswietlenie poczatkowej zawartosci
	cout << "Wyswietlenie poczatkowej zawartosci\n";

	ifstream inFile;
	//inFile.open(fileName_.c_str(), ios_base::binary | ios_base::in);
	inFile.open(fileName_, ios_base::binary | ios_base::in); //zadzia�a od C++11

	if (inFile.is_open())
	{
		cout << setw(5) << "Numer"
			<< setw(15) << "Nazwisko"
			<< setw(15) << "Imie"
			<< setw(10) << "Kwota" << '\n';
		while (inFile.read((char*)&client, sizeof client))
		{
			cout << setw(4) << client.accNum
				<< setw(15) << client.lastName
				<< setw(15) << client.firstname
				<< setw(10) << client.balance << "\n";
			accountNum++;
		}
		inFile.close();
	}
	else cout<<"error"; return 0;
		//return 0;
	

	//========================================================================
	//dodanie nowych danych
	cout << "Dodanie nowych danych\n";
	ofstream outFile;
	outFile.open(fileName_.c_str(), ios_base::out | ios_base::app | ios_base::binary);
	if (!outFile.is_open())
	{
		cout << "Nie mozna otworzyc pliku\n";
		exit(EXIT_FAILURE);
	}

	cout << "Wprowadz nazwisko, imie, kwote\n?";
	cin.get(client.lastName, NAME_SIZE);
	if (cin.fail())    //je�eli wyczytany zostanie pusty �a�cuch ustawiana jest flaga failbit
		cin.clear();   //kasowanie flagi failbit
	cin.get();

	while (client.lastName[0] != '\0')
	{
		cin.get(client.firstname, NAME_SIZE);
		cin.get();
		cin >> client.balance;
		cin.get();
		client.accNum = accountNum;
		accountNum++;
		outFile.write((char *)&client, sizeof client);

		cout << "Wprowadz nazwisko, imie, kwote\n?";
		cin.get(client.lastName, NAME_SIZE);
		if (cin.fail())	//je�eli wyczytany zostanie pusty �a�cuch ustawiana jest flaga failbit
			cin.clear(); //kasowanie flagi failbit
		cin.get();
	}

	outFile.close();

	//========================================================================
	//wyswietlenie zmienionego pliku
	cout << "Wyswietlenie zmienionego pliku\n";
	inFile.open(fileName_, ios_base::binary | ios_base::in);

	if (inFile.is_open())
	{
		cout << setw(5) << "Numer"
			<< setw(15) << "Nazwisko"
			<< setw(15) << "Imie"
			<< setw(10) << "Kwota" << '\n';
		while (inFile.read((char*)&client, sizeof client))
		{
			cout << setw(4) << client.accNum
				<< setw(15) << client.lastName
				<< setw(15) << client.firstname
				<< setw(10) << client.balance << "\n";
			accountNum++;
		}
		inFile.close();
	}
	else
		return 0;

	

	//========================================================================
	//Modyfikacja wybranego rekordu
	cout << "Modyfikacja wybranego rekordu\n";

	fstream inoutFile;    //strumienie do odczytu i zapisu

	inoutFile.open(fileName_, ios_base::in | ios_base::out | ios_base::binary);
	if (!inoutFile.is_open())
	{
		cout << "Nie mo�na otworzyc pliku\n";
		exit(EXIT_FAILURE);
	}

	unsigned int account;
	cout << "Wprowadz numer rekordu do modyfikacji: ";
	cin >> account;

	streampos place = account * sizeof(clientData);
	inoutFile.seekg(place);
	inoutFile.read((char *)&client, sizeof client);

	if (inoutFile.eof())
		inoutFile.clear();   //skasowanie znacznika ko�ca pliku

	if (client.accNum == 0)
	{
		cout << "Rekord " << account << " jest pusty\n";
	}
	else
	{
		cout << setw(4) << client.accNum
			<< setw(15) << client.lastName
			<< setw(15) << client.firstname
			<< setw(10) << client.balance << "\n";


		cout << "Wprowadz zasilenie (+) lub obciazenie (-): ";
		double transaction;
		cin >> transaction;
		client.balance += transaction;

		cout << setw(4) << client.accNum
			<< setw(15) << client.lastName
			<< setw(15) << client.firstname
			<< setw(10) << client.balance << "\n";

		inoutFile.seekp(place);
		inoutFile.write((char *)&client, sizeof client);
	}
	inoutFile.close();
	return 0;
}


/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>  //setw

const int NAME_SIZE = 20;
using namespace std;

struct clientData{
    unsigned int accNum;
    char lastName[NAME_SIZE];
    char firstName[NAME_SIZE];
    double balance;

};


int main(){
    
    string fileName_ = "credit.dat";
    clientData client;
    unsigned int accountNum = 0;


    cout<<"Wyświetlanie zawarotści"<<endl;

    ifstream inFile;
    inFile.open(fileName_, ios_base::binary | ios_base::in);
    if(inFile.is_open()){
        cout<<setw(5)<<"Numer"
        <<setw(15)<<"Nazwisko"
        <<setw(15)<<"Imie"
        <<setw(10)<<"Kwota"<<endl;
        while(inFile.read((char*)&client, sizeof client)){
            cout<<setw(4)<<client.accNum
            <<setw(15)<<client.firstName
            <<setw(15)<<client.lastName
            <<setw(10)<<client.balance<<endl;
        }
    }

    inFile.close();



    //dowawanie nowych danych
    cout<<"Dodawanie nowych danych"<<endl;
    ofstream outFile;
    outFile.open(fileName_.c_str(), ios_base::out | ios_base::app | ios_base::binary);

    if(!outFile.is_open()){
        cout<<"Nie mozna otworzc pliku!";
        exit(EXIT_FAILURE);
    }

    cout<<"Wprowadz nazwisko, imie, kwote"<<endl;
    if(cin.fail()) cin.clear();
    cin.get(); //czyszczenie buforu z entera

    while(client.lastName[0]!="\0"){
        cin.get(client.firstName, NAME_SIZE);
        cin.get();
        cin>>client.balance;
        cin.get();
        outFile.write((char *)&client, sizeof client);
        if(cin.fail()) cin.clear();
        cin.get()
;
    }
    outFile.close();



    //wyswietlenie nowego pliku



    fstream inoutFile //strumieniowanie odczytu i zapisu



}//end of main
*/