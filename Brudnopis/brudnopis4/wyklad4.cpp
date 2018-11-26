#include <iostream>
#include <string>

using namespace std;

int test(int &a);

int main(){

    string hw ="Hello\"-\"World!"; //<-KOLOKWIUM wyprowadzanie symboli specjalnych z backslashem
    cout<<hw<<endl;

    //cin.get(); pobranie ostatniego znaku z buforu
    //cout<<imie.size()<<endl; rozmiar zmiennej imie
    int a = 10;
    //test(a);
    //cout<<a;

    for(int i=0; i<10; i++){
        if(i==5) continue;
        cout<<i<<endl;
    }

    int c;
    switch(c=cin.get()){
        case '+': cout<<"plus"<<endl;
        break;
        case '-': cout<<"minus"<<endl;
        break;
        default : cout<<"inny znak"<<endl;
    }


    return 0;
}


int test(int &a){
    a=20;
    cout<<a;
    return 0;
}


