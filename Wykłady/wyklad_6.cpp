#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;



int main(){
    ofstream plik_wyjsciowy;
    plik_wyjsciowy.open("przyklad1.txt");

    if(!plik_wyjsciowy.is_open())
        return 0;

    plik_wyjsciowy << "hello world";

    plik_wyjsciowy.close();

    ifstream plik_wejsciowy;
    plik_wejsciowy.open("przyklad1.txt");

    if(!plik_wejsciowy.is_open())
       return 0;

    string linia;
    getline(plik_wejsciowy, linia);
    cout<<linia<<endl;

    plik_wejsciowy.close();
//podawanie nazwy pliku
    cout<<"Podaj nazwe pliku: ";
    string nazwa_pliku;
    cin >>nazwa_pliku;
    cin.get();

    plik_wejsciowy.open(nazwa_pliku);

    if(!plik_wejsciowy.is_open())
        return 0;

    
    getline(plik_wejsciowy, linia);
    cout<<"Zawartość pliku "<<nazwa_pliku<<endl;
    char ch;
    while(plik_wejsciowy.get(ch))
    cout << "ch";

    plik_wejsciowy.close();


    


    return 0;
}