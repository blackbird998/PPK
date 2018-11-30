#include <iostream>
#include <string>

using namespace std;

int PI1();
int f(int n, int m);
void fraktal_trojkatny(double x);

int main(){
    PI1();

    return 0;
}


int PI1(){
//kart z rekurencji i gramatyki 

    /*
        f(n,m)
        f(1,m)=1
        f(n,1)=1
        gdy n=<m: f(n,m)=f(n,n)=1+f(n,n-1)
        gdy n>m: f(n,m)=f(n-m,m)+f(n,m-1)
    */

    int n=5;
    int m=5;

    cout<<f(n,m);


    return 0;
}

//funkcja wyliczająca na ile sposobów można przedstawić liczbę n liczbami mniejszymi od m
int f(int n, int m){
       if(n==1||m==1) return 1;
       else if(n<=m) return 1+f(n,n-1);
       else return f(n-m,m)+f(n,m-1);
   }



void fraktal_trojkatny(double x){
    //if(x<min) return;
    for(int i=0; i<3; i++){
        fraktal_trojkatny(x/2);
        //rysuj(x);
        //obrot(120);
    }

void drzewo(double x){
    //if(x<min) return;

    rysuj(x);
    obrot(45);
    drzewo(x/2);
    obrot(-90);
    drzewo(x/2);
    obrot(-135);
    rysuj(-x);
}


//szkoczek ma odwiedzić wszystkie pola na szachownicy tylko jeden raz
int szachownica[8][8];
bool skoczek(int x0, int y0, int nr_ruchu){
    const int dx[8]={1,2,2,1,-1,-2,-2,-1};
    const int dy[8]={2,1,-1,-2,-2,-1,1,2};
    if(nr_ruchu==8*8) return true;
    szachownica[x0][y0]=nr;
    for(int i=0; i<8; i++){
        if(x0+dx[i]>=0&&x0+dx[i]<n&&y0=dy[i]>=0&&y0+dy[i]<n)
            if(szachownica[x0+dx[i]][y0+dy[i]]==0)
                if(skoczek(x0+dx[i][y0+dy[i]],nr_ruchu+1)) return true;
                szachownica[x0][y0]=0;
                return false;
    }

void minmax(int l, int p, int &m, int &M){ //przekazanie przez referencję
    if(l==p) m=M=l;
    else if(l+1==p){
        if(a[l]<a[p]) {m=l; M=p;}
        else {m=p; M=l;}
    }
    else{
        int m1,m2,M1,M2;
        minmax(l,(l+p)/2+1,m1,M1);
        minmax((l+p)/2+1,p,m2,M2);
        if(a[m2]<a[m1]) m=m2;
        else m=m1;
        if(a[M2]>a[M1]) M=M2;
        else M=M1;
    }
}

}





} //end of main

/*
//PPK
    string hw ="Hello\"-\"World!"; //<-KOLOKWIUM wyprowadzanie symboli specjalnych z backslashem
    cout<<hw<<endl;

    //cin.get(); pobranie ostatniego znaku z buforu
    //cout<<imie.size()<<endl; rozmiar zmiennej imie
*/