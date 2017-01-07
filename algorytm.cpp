/*

Projekt Grupowy - III LO Wroclaw

Pawel Dietrich, Aleksandra Domagala, Oliwia Kropidlowska.

https://github.com/DietPawel/Cpp

Styczen 2017 (c)

*/

#include <iostream>
#include <algorithm>

const int arrSize = 35;



using namespace std;

int sumTableElements(int input[], int size)
{
    int sum;
    for(int i=0; i<size; i++)
        sum += input[i];
    return sum;
}

int roundSqrt(int liczba)
{
    int upper=46341,lower=0; // upper to pierwiastek zaokraglony w gore od maksymalnej wartosci int.
    while (upper != lower)
    {
        int m = (upper+lower)/2;
        if (m*m >= liczba)
            upper  = m;
        else
            lower = m+1;
    }
    return upper;
}

void rozklad (int liczba, int czynnik[])
{
    int next = 0;
    int pierwiastek=roundSqrt(liczba);
    for(int i=2; i<pierwiastek; i++)
    {
        while (liczba%i==0)
        {
            czynnik[next]=i;
            liczba=liczba/i;
            next++;
        }
    }
    czynnik[next++]=liczba;
    czynnik[next]=-1;
}

int pow(int podstawa, int potega){
    int odp = 1;
    for(int i=0;i<potega;i++)odp = odp*podstawa;
    return odp;
}

void dzielniki (int rozklad[])
{
    int s=0,i=0,d=1;
    int skladniki[arrSize];
    int potega[arrSize];
    skladniki[0]=rozklad[0];
    potega[0]=1;
    while(rozklad[++i]>0)
    {
        if(rozklad[i]==rozklad[i-1])
        {
            potega[s]++;
        }
        else
        {
            d=d*(potega[s]+1);
            s++;
            skladniki[s]=rozklad[i];
            potega[s]=1;
        }
    }
    d=d*(potega[s]+1);
    int dzielnikiLiczby[d+2];
    for(int i=0;i<d;i++){
        int dzielnik = 1, ii = i,wskaznik = 0;
        while(ii>0){
            dzielnik = dzielnik * pow(skladniki[wskaznik], ii%(potega[wskaznik]+1));
            wskaznik++;
            ii=ii/(potega[wskaznik]+1);
        }
        dzielnikiLiczby[i]=dzielnik;
    }
    sort(dzielnikiLiczby,dzielnikiLiczby+d);
    dzielnikiLiczby[d]=-1;
    for(int i=0;i<d;i++){
        if(dzielnikiLiczby[i]!=dzielnikiLiczby[i+1])
            cout<<" "<<dzielnikiLiczby[i];
    }
}

int main()
{
    int a,czynnikiLiczby[arrSize];;
    cout<<"Hello, pass number: ";
    cin >> a;
    while(a<=0){
        cout<<"Your number is not positive, pass NATURAL number: ";
        cin >> a;
    }
    rozklad(a, czynnikiLiczby);
    cout<<"\n"<<a<<" jest ";
    if(czynnikiLiczby[1]==-1)cout<<"pierwsza.\n";
    else cout<<"zlozona.\n";
    cout<<"Dzielniki "<<a<<":";
    dzielniki(czynnikiLiczby);
    cout<<"."<<endl;

}
