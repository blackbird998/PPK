#include <iostream>
//#include <string>

using namespace std;



int main(){


    int n = 255;
    cout<<dec<<n<<endl;
    cout.fill('x');
    cout.width(10);
    cout<<left<<100<<endl;
    
    cout<<hex<<n<<endl;
    //cout<<std::setw(10);
    cout<<100<<endl;
    cout<<dec<<n<<endl;

    char zmienna_znakowa;
    zmienna_znakowa = cin.get(); //zwraca znak z wejścia (śmieci z buforu)
    cin.get(zmienna_znakowa); //zwraca obiekt klasy istream
    cin.get(zmienna_znakowa);


    const int rozmiar = 10;
    char imie[rozmiar];
    cin.getline(imie, rozmiar); //wczytuje do imie iczbę znaków odpowiadających rozmiar, lub do białego znaku. Odrzuca znak nowej lini.
    cin.get(imie, rozmiar); //Jw. ale znak nowej lini zostaje w buforze
    cin.get(zmienna_znakowa); //pozbywamy się entera
    //po wprowadzeniu pustego łańcucha znaków ustawia się fail bit, blokujący wpisywanie kolejnych znaków
    if(cin.fail()) cin.clear(); //rozwiązuje ten problem




    struct das{
        int b;
        int c;
    } a;

    struct s_data{
        unsigned int dzien;
        unsigned int miesiac;
        unsigned int rok;
    };

    s_data dzisiejsza_data {2, 11, 2015};

    cout<<dzisiejsza_data.dzien<<"-"<<dzisiejsza_data.miesiac<<"-"<<dzisiejsza_data.rok;


    struct dane_karty_visa{
        s_data data_waznosci;
        long long stan_konta;
    };

    struct dane_personalne{
        string imie;
        
    };

    union{
        dane_karty_visa dane_karty;
        long long wysokosc_pensji;
    };



    //dni_tygodnia weekend;

    return 0;
}