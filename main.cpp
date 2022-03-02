#include <iostream>
#include <ctime> // do losowania
#include <iomanip>
#include <conio.h>
#include <cstdlib> // czyszczenie

using namespace std;
int t1w,t1k,t2w,t2k; // wymiary macierzy
int losOd,losDo,wyborMenu,wyborStat; // zmienne potrzebne do zakresu losowania oraz do menu
int a,b,c; //zmienne pomocnicze
int suma,ie,srednia; // zmienne statystyczne, ie= ilosc elementow
int tab3[100][100]; // tablica wynikowa
int tab1[100][100]; //wprowadzenie duzej tabeli statycznej aby pomiescila dane macierzy
int tab2[100][100];
char poczatek; // zmienna dajaca mozliwosc ponownego wykonania programu
double czas; // czas dzialania programu
time_t start, koniec;
int main()
{
start = clock();
    srand(time(0));
    cout << "Witam w programie zaliczeniowym v4 Grzegorza Witka z grupy 1BZI" << endl << endl;
    do{
    cout << "Prosze podac ilosc wierszy pierwszej macierzy i zatwierdzic enterem" << endl;
    cin >> t1w;
    cout << "Prosze podac ilosc kolumn pierwszej macierzy i zatwierdzic enterem" << endl;
    cin >> t1k;
    cout << "Prosze podac ilosc wierszy drugiej macierzy i zatwierdzic enterem" << endl;
    cin >> t2w;
    while(t2w!=t1k)
    {
        cout << "Druga macierz musi miec tyle wierszy co pierwsza kolumn" << endl;
        cin >> t2w;
    }

    cout << "Prosze podac ilosc kolumn drugiej macierzy i zatwierdzic enterem" << endl;
    cin >> t2k;
    cout << "Od jakiejliczby maja byc generowane losowo liczby w macierzach" << endl;
    cin >> losOd;
    cout << "Do jakiej liczby maja byc generowane losowo liczby w macierzach"<< endl;
    cin >> losDo;

system("cls");
cout << " Macierze: " << endl;

        for(a=0; a<t1w; a++) // losowanie pierwszej macierzy
        for(b=0; b<t1k; b++)
            tab1[a][b]=(rand()%(losDo-losOd+1))+losOd; // losowanie w taki sposob aby losowalo z podanego zakresu

    for(a=0; a<t2w; a++)  // losowanie drugiej macierzy
        for(b=0; b<t2k; b++)
            tab2[a][b]=(rand()%(losDo-losOd+1))+losOd;

if(t1w>t2w) // jako pierwsza ma wyswietlac sie wieksza macierz aby byla wyswietlana w calosci po wierszach, jednoczesnie druga skonczy sie w miejscu zer
{
    for(a=0; a<t1w; a++)
    {
        for(b=0; b<t1k; b++)
            cout << setw(5) << tab1[a][b];

    cout << "           ";
        for(c=0; c<t2k; c++)
            cout << setw(5) << tab2[a][c];

        cout << endl;
    }
}
else
{
   for(a=0; a<t2w; a++)
    {
        for(b=0; b<t2k; b++)
            cout << setw(5) << tab2[a][b];

    cout << "           ";
        for(c=0; c<t1k; c++)
            cout << setw(5) << tab1[a][c];

        cout << endl;
    }
}
/*
    cout << "Macierz pierwsza: "<< endl; // macierze wyswietlajace sie poprawnie bez zer

    for(a=0; a<t1w; a++)
        {
            for(b=0; b<t1k; b++)
            {
                cout << setw(5) << tab1[a][b];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Macierz druga: " << endl;

    for(a=0; a<t2w; a++)
        {
            for(b=0; b<t2k; b++)
            {
                cout << setw(5) << tab2[a][b] ;
            }
            cout << endl;
        }
*/
    cout << endl;
    cout << "-------------MENU-------------" << endl;
    cout <<" 1. Odwrocenie macierzy pierwszej" << endl;
    cout <<" 2. Odwrocenie macierzy drugiej" << endl;
    cout <<" 3. Pomnozenie obu macierzy"<< endl;
    cout <<" 4. Wyliczenie wyznacznika macierzy pierwszej "<< endl;
    cout <<" 5. Wyliczenie wyznacznika macierzy drugiej"<< endl;
    cout <<" 6. Podanie statystyk"<< endl;
    cin>> wyborMenu;
system("cls");
    switch(wyborMenu)
    {
    case 1:
        cout << "Niestety program nie ma jeszcze mozliwosci wykonania podanej operacji" << endl;
        break;
    case 2:
        cout << "Niestety program nie ma jeszcze mozliwosci wykonania podanej operacji" << endl;
        break;
    case 3:
        for(a=0; a<t1w; a++)
        for(b=0;b<t2k; b++)
        {
            tab3[a][b]=0; // zerujemy tablice wynikowa
            for(c=0;c<t2w; c++)
                tab3[a][b]= tab3[a][b] + tab1[a][c]*tab2[c][b];
        }
        cout << "Wynik mnozenia: " << endl;
            for(a=0; a<t1w; a++)
        {
            for(b=0; b<t2k; b++)
                cout << setw(5) << tab3[a][b];
                cout << endl;
            }
        break;
    case 4:
        cout << "Niestety program nie ma jeszcze mozliwosci wykonania podanej operacji" << endl;
        break;
    case 5:
        cout << "Niestety program nie ma jeszcze mozliwosci wykonania podanej operacji" << endl;
        break;
    case 6:
            cout <<"-------------STATYSTYKI-------------"<< endl;
            cout <<" 1. Suma wartosci"<< endl;
            cout <<" 2. Srednia wartosc"<< endl;
            cout <<" 3. Wartosc maksymalna i minimalna"<< endl;
            cout <<" 4. Suma wartosci na lewej przekatnej"<< endl;
            cout <<" 5. Ustawienie jedynek na prawej przekatnej"<< endl;
            cin >> wyborStat;
            system("cls");

            switch(wyborStat)
            {
            case 1:{
                int suma=0,ie=0,srednia=0;
                for( a=0; a<t1w; a++)
                    for( b=0; b< t1k; b++)
                    {

                        suma += tab1[a][b];
                        ie+=1;
                    }
                for(a=0; a<t2w; a++)
                    for( b=0; b<t2k; b++)
                    {
                        suma+= tab2[a][b];
                        ie+=1;
                    }
                        cout << "Suma wartosci obu macierzy wynosi: " << suma << endl;
                }break;
            case 2:{
                int suma=0,ie=0,srednia=0;
                for( a=0; a<t1w; a++)
                    for( b=0; b< t1k; b++)
                    {

                        suma += tab1[a][b];
                        ie+=1;
                    }
                for(a=0; a<t2w; a++)
                    for( b=0; b<t2k; b++)
                    {
                        suma+= tab2[a][b];
                        ie+=1;
                    }
                    srednia=suma/ie;
                    cout << "Srednia wartosci obu macierzy wynosi: " << srednia << endl;
                }break;
            case 3:{
                int maks=-99999,minimum=99999; // dosyc spore wartosci aby losowane mozliwie prawdopodobnie znalazly sie w przedziale
                for( a=0; a<t1w; a++) //1 macierz
                    for( b=0; b< t1k; b++)
                    {
                        if(tab1[a][b]>maks)
                            maks=tab1[a][b];

                        if(tab1[a][b]<minimum)
                            minimum=tab1[a][b];
                    }

                for(a=0; a<t2w; a++) // 2 macierz
                    for( b=0; b<t2k; b++)
                    {
                        if(tab2[a][b]>maks)
                            maks=tab2[a][b];
                        if(tab2[a][b]<minimum)
                            minimum=tab2[a][b];
                    }
                    cout << "Wastosc minimalna oraz maksymalna obu macierzy to kolejno: " << minimum << " oraz " << maks << endl;
                }break;
            case 4:{
                for (a=0;a<t1w;a++) // suma na przekatnej 1 macierzy
                    for(b=0;b<t1k;b++)
                    if(a==b)
                    suma+=tab1[a][b];

                for (a=0;a<t2w;a++) // suma na przekatnej 2 macierzy
                    for(b=0;b<t2k;b++)
                    if(a==b)
                    suma+=tab2[a][b];
                    cout << "Suma wartosci na lewych przekatnych obu macierzy wynosi: " << suma << endl;
                }break;
            case 5:{
                for (a=0;a<t1w;a++) // 1 na przekatnej 1 macierzy
                    for(b=0;b<t1k;b++)
                    if((a+b)==(t1k-1))
                    tab1[a][b]=1;
                cout << "Jedynki na lewej przekatnej macierzy 1" << endl;
                for (a=0;a<t1w;a++) // wyswietlenie 2 macierzy
                {
                    for(b=0;b<t1k;b++)
                        cout << setw(5) << tab1[a][b];
                        cout << endl;
                }

                for (a=0;a<t2w;a++) // 1 przekatnej 2 macierzy
                    for(b=0;b<t2k;b++)
                    if((a+b)==(t2k-1))
                    tab2[a][b]=1;

                    cout << "Jedynki na lewej przekatnej macierzy 2" << endl;
                for (a=0;a<t2w;a++) // wyswietlenie 2 macierzy
                {
                    for(b=0;b<t2k;b++)
                        cout << setw(5) << tab2[a][b];
                    cout << endl;
                }
                }break;
            }
        break;
    }
    cout << endl;
    cout << "Czy chcesz generowac macierze ponownie? t/n" << endl;
    cin >> poczatek;
    system("cls");
    }while(poczatek=='t');

    koniec = clock();
    czas=(koniec-start)/(double)CLOCKS_PER_SEC;
    cout << "Program wykonywal sie " << czas << "sekund" << endl;
    return 0;
}
