/*

Projekt Grupowy - III LO Wroclaw

Pawel Dietrich, Aleksandra Domagala, Oliwia Kropidlowska.

https://github.com/DietPawel/Cpp

Styczen 2017 (c)

*/

#include <iostream>
#include <algorithm> // funkcja sortujaca sort

const int arrSize = 35, dzielSize=20000;

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
    if(liczba>1)czynnik[next++]=liczba;
    czynnik[next]=-1;
}

int pow(int podstawa, int potega)
{
    int odp = 1;
    for(int i=0; i<potega; i++)odp = odp*podstawa;
    return odp;
}

bool czy_palindrom(int  n)
{
    int m=0, kopian = n;

    while (n>0)
    {
        m=m*10+n%10;
        n=n/10;
    }


    return m==kopian;
}

int dzielniki (int rozklad[], int odp[])
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
    for(int i=0; i<d; i++)
    {
        int dzielnik = 1, ii = i,wskaznik = 0;
        while(ii>0)
        {
            dzielnik = dzielnik * pow(skladniki[wskaznik], ii%(potega[wskaznik]+1));
            ii=ii/(potega[wskaznik]+1);
            wskaznik++;
        }
        dzielnikiLiczby[i]=dzielnik;
    }
    sort(dzielnikiLiczby,dzielnikiLiczby+d);
    dzielnikiLiczby[d]=-1;
    int wskaznik=0, suma=0;
    for(int i=0; i<=d; i++)
    {
        if(dzielnikiLiczby[i]!=dzielnikiLiczby[i+1])
        {
            odp[wskaznik]=dzielnikiLiczby[i];
            suma+=dzielnikiLiczby[i];
            wskaznik++;
        }
    }
    odp[wskaznik]=-1;
    return suma;
}

int main()
{
    int a,czynnikiLiczby[arrSize], dzielnikiLiczby[dzielSize];
    cout<<"Witam, podaj liczbe: ";
    cin >> a;
    while(a<=0)
    {
        cout<<"Twoja liczba nie jest dodatnia, podaj liczbe NATURALNA: ";
        cin >> a;
    }
    rozklad(a, czynnikiLiczby);
    // liczba pierwsza
    cout<<"\n""Liczba "<<a<<" jest ";
    if(czynnikiLiczby[1]==-1)cout<<"pierwsza.\n\n";
    else cout<<"zlozona.\n\n";
    int suma = dzielniki(czynnikiLiczby, dzielnikiLiczby);
    //liczba doskonala
    cout<<"Liczba "<<a<<(suma-a+1 == a?" ":" nie ")<<"jest doskonala.\n\n";
    //liczba palindromiczna
    cout<<"Liczba "<<a<<(czy_palindrom(a)?" ":" nie ")<<"jest palindromem.\n\n";
    //czynniki pierwsze liczby
    cout<<"Czynniki pierwsze liczby "<<a<<": "<<czynnikiLiczby[0];
    int iter=1;
    while(czynnikiLiczby[iter]!=-1)
    {
        cout<<", "<<czynnikiLiczby[iter];
        iter++;
    }
    cout<<".\n\n";
    //dzielniki naturlane liczby
    cout<<"Dzielniki "<<a<<": 1";
    iter=1;
    while(dzielnikiLiczby[iter]!=-1)
    {
        cout<<", "<<dzielnikiLiczby[iter];
        iter++;
    }
    cout<<".\n";

}
