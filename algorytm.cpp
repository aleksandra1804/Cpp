/*

Projekt Grupowy - III LO Wroclaw

Pawel Dietrich, Aleksandra Domaga³a, Oliwia Kropidlowska.

https://github.com/DietPawel/Cpp

Styczen 2017 (c)

*/

#include <iostream>
#include <vector>

using namespace std;

int sumVectorElements(vector < int > input){
    int sum;
    for(int i=0;i<input.size();i++)
        sum += input[i];
    return sum;
}

//int roundSqrt(int liczba){
//    int upper=46341,lower=0; // upper to pierwiastek zaokraglony w gore od maksymalnej wartosci int.
//    while (upper != lower)
//    {
//        int m = (upper+lower)/2;
//        if (m*m >= liczba)
//          upper  = m;
//        else
//          lower = m+1;
//    }
//    return upper;
//}

vector < int > sitoEratostenesa(int maksimum){
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

vector <int> rozklad (int liczba)
{
    vector < int > czynniki;
    vector < int > pierwsze = sitoEratostenesa(liczba);
    int d=0;
    while(liczba>1){
        if (liczba%pierwsze[d]==0){
            czynniki.push_back(pierwsze[d]);
            liczba=liczba/pierwsze[d];
        }
        else
            d=d+1;
    }
    return czynniki;
}

vector <int> dzielniki (vector <int> rozklad)
{
    int s=0;
    vector < int > skladniki;
    vector < int > liczbaSkl;
    skladniki.push_back(rozklad[0]);
    liczbaSkl.push_back(1);
    for(int i=1;i<rozklad.size();i++){
        if(rozklad[i]==rozklad[i-1]){
                liczbaSkl[s]++;
        }else{
            skladniki.push_back(rozklad[i]);
            liczbaSkl.push_back(1);
            s++;
        }
    }
    vector < int > odp;
    //WIP
    return odp;
}

int main(){
    int a;
    cin >> a;
    dzielniki(rozklad(a));



}
