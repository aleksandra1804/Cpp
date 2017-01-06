/*

Projekt Grupowy - III LO Wroclaw

Pawel Dietrich, Aleksandra Domaga³a, Oliwia Kropidlowska.

https://github.com/DietPawel/Cpp

Styczen 2017 (c)

*/

#include <iostream>
#include <vector>

using namespace std;

int round_sqrt(int liczba){
    int upper=46341,lower=0; // upper to pierwiastek zaokraglony w gore od maksymalnej wartosci int.
    while (upper != lower)
    {
        int m = (upper+lower)/2;
        if (m*m >= liczba)
          upper  = m; // szukaj od m+1 do b
        else
          lower = m+1;   // szukaj od a do m
    }
    return upper;
}

vector < int > sito_eratostenesa(int maksimum){
    vector < bool > liczby (maksimum+5);
    vector < int > odp;
    for(int i=2;i<=maksimum;i++){
        if(liczby[i])continue;
        odp.push_back(i);
        for(int y=2*i;y<=maksimum;y+=i){
            liczby[y]=true;
        }
    }
    return odp;
}




using namespace std;

int main(){
    int a;
    cin >> a;




}
