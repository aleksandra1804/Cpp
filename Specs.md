##Specyfikacja programu
```C++
int roundSqrt(int liczba);
```
#####Wejście: _liczba_ typu int.
#####Wyjście: _upper_ typu int będąca zaokrąglonym w górę pierwiastkiem z _liczba_.
#####Złożoność: O(_1_).

```C++
int pow(int podstawa, int potega)
```
##### Wejście: _podstawa_ typu int - podstawa potęgi, _wykladnik_ typu int - wykładnik potęgi. Obie liczby całkowite.
#####Wyjście: _odp_ typu int będąca wynikiem operacji _podstawa<sup>wykladnik</sup>_.
#####Złożoność: O(_wykladnik_).

```C++
bool czy_palindrom(int  n)
```
#####Wejście: _n_ typu int - całkowita liczba, którą sprawdza algorytm.
#####Wyjście: warunek typu bool prawdziwy gdy liczba jest palindromem.
#####Złożoność: O(_n_), gdzie n jest ilością cyfr liczby.

```C++
void rozklad (int liczba, int czynnik[])
```
#####Wejście: _liczba_ typu int - całkowita liczba, którą sprawdza algorytm, tablica _czynnik_ typu int do której program wpisuje czynniki zakończone -1.
#####Wyjście: _brak_.
#####Złożoność: O(_√liczba_).

```C++
int dzielniki (int rozklad[], int odp[])
```
#####Wejście: tablica _rozklad[]_ typu int zawierajaca czynniki pierwsze zakończone -1, tablica _czynnik[]_ typu int do której program wpisuje dzielniki liczby zakończone -1.
#####Wyjście: _suma_ będąca sumą wszystkich dzielników liczby.
#####Złożoność: O(_n<sup>2</sup>_), gdzie n to liczba czynników


```C++
int main ()
```
#####Wejście: _brak_.
#####Cin: _liczba naturlna mieszczaca się w typie int_.
#####Wyjście: _zgodnie z zadaniem_.
#####Złożoność: O(_1_).
