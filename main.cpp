#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std;

struct daneOsoby
{
 int idOsoba;
 string nazwisko, imie, nr_telefonu, mail, adres;
};

int wczytajDaneZPliku (daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
   fstream plik;
    plik.open("ksiazka adresowa.txt", ios:: out | ios::app);
    plik.close();
    plik.open("ksiazka adresowa.txt", ios:: in);

        if (plik.good()==false)
        {
            cout << "Brak pliku";
            exit(0);
        }

        else if (plik.good()==true)
        {
            string trescWiersza;
            int liczbaZapisanychtrescWierszayPliku=0;

            while (getline(plik, trescWiersza))
                {
                    liczbaZapisanychtrescWierszayPliku ++;
                }

            aktualnaLiczbaZapisanychOsob = liczbaZapisanychtrescWierszayPliku/6;

            plik.clear();
            plik.seekg(0, ios::beg);

            for (int i=1; i <= aktualnaLiczbaZapisanychOsob ;i++)
                {
                plik >> mojaKsiazka[i].idOsoba;
                plik >> mojaKsiazka[i].imie;
                plik >> mojaKsiazka[i].nazwisko;
                getline(plik, trescWiersza);
                getline(plik, mojaKsiazka[i].nr_telefonu);
                plik >> mojaKsiazka[i].mail;
                getline(plik, trescWiersza);
                getline(plik, mojaKsiazka[i].adres);
                }
        }
    plik.close();
    return aktualnaLiczbaZapisanychOsob;
}
w
int dodajOsobeDoKsiazki (daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
    string nazwisko, imie, nr_telefonu, mail, adres;


    system ("cls");
    cout << "Dodawanie osoby do kontaktow."<< endl;
    cout << "Podaj nazwisko: "<<endl;
    cin  >> nazwisko;
    cout << "Podaj imie: "<<endl;
    cin  >> imie;
    cout << "Podaj nr telefonu: "<<endl;
    cin.sync();
    getline(cin, nr_telefonu);
    cout << "Podaj mail: "<<endl;
    cin  >> mail;
    cout << "Podaj adres zamieszkania: "<<endl;
    cin.sync();
    getline(cin, adres);

    int idOsoba = aktualnaLiczbaZapisanychOsob+1;
    aktualnaLiczbaZapisanychOsob++;

    mojaKsiazka[aktualnaLiczbaZapisanychOsob].idOsoba = idOsoba;
    mojaKsiazka[aktualnaLiczbaZapisanychOsob].imie = imie;
    mojaKsiazka[aktualnaLiczbaZapisanychOsob].nazwisko = nazwisko;
    mojaKsiazka[aktualnaLiczbaZapisanychOsob].nr_telefonu = nr_telefonu;
    mojaKsiazka[aktualnaLiczbaZapisanychOsob].mail = mail;
    mojaKsiazka[aktualnaLiczbaZapisanychOsob].adres = adres;

    fstream plik;
    plik.open("ksiazka adresowa.txt", ios::out | ios::app);
    if (plik.good()==false)
    {
        cout << "Brak pliku";
        exit(0);
    }
    else if  (plik.good()==true)
    {
        plik << idOsoba << endl;
        plik << imie << endl;
        plik << nazwisko << endl;
        plik << nr_telefonu << endl;
        plik << mail << endl;
        plik << adres << endl;

        plik.close();
        cout << "Osoba zostala dodana!"<<endl;
        Sleep(1000);
    }

    return aktualnaLiczbaZapisanychOsob;
}

void wyswietlCalaKsiazke(daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
     system("cls");
     cout << "KONTAKTY"<< endl;
     cout << "==========================================================================================="<<endl;
     for (int i=1; i <= aktualnaLiczbaZapisanychOsob ;i++)
                {
                cout << mojaKsiazka[i].idOsoba << "  ";
                cout << mojaKsiazka[i].imie << "  ";
                cout << mojaKsiazka[i].nazwisko << "  ";
                cout << mojaKsiazka[i].nr_telefonu << "  ";
                cout << mojaKsiazka[i].mail << "  ";
                cout << mojaKsiazka[i].adres << endl;
                }
    getchar();getchar();
}

void wyswietlOsobyWgNazwiska(daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
     string nazwisko;
     system("cls");

     cout << "Podaj nazwisko do wyszukania: "<<endl;
     cin >> nazwisko;

     const char * c = nazwisko.c_str();

     system("cls");

     cout << "KONTAKTY"<< endl;
     cout << "============================================================================================"<<endl;
     for (int i=1; i <= aktualnaLiczbaZapisanychOsob ;i++)
                {
                const char * c2 = mojaKsiazka[i].nazwisko.c_str();
                if (stricmp(c, c2 )==0)
                    {
                        cout << mojaKsiazka[i].idOsoba << "  ";
                        cout << mojaKsiazka[i].imie << "  ";
                        cout << mojaKsiazka[i].nazwisko << "  ";
                        cout << mojaKsiazka[i].nr_telefonu << "  ";
                        cout << mojaKsiazka[i].mail << "  ";
                        cout << mojaKsiazka[i].adres << endl;
                    }
                }
    getchar();getchar();
}

void wyswietlOsobyWgImienia(daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
     string imie;
     system("cls");

     cout << "Podaj imie do wyszukania: "<<endl;
     cin >> imie;

     const char * c = imie.c_str();

     system("cls");

     cout << "KONTAKTY"<< endl;
     cout << "========================================================================"<<endl;
     for (int i=1; i <= aktualnaLiczbaZapisanychOsob ;i++)
                {
                const char * c2 = mojaKsiazka[i].imie.c_str();
                if (stricmp(c, c2)==0)
                    {
                        cout << mojaKsiazka[i].idOsoba << "  ";
                        cout << mojaKsiazka[i].imie << "  ";
                        cout << mojaKsiazka[i].nazwisko << "  ";
                        cout << mojaKsiazka[i].nr_telefonu << "  ";
                        cout << mojaKsiazka[i].mail << "  ";
                        cout << mojaKsiazka[i].adres << endl;
                    }
                }
    getchar();getchar();
}

int zmienDaneOsoby(daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
    int idOsoba, wybraneDaneDoEdycji, potwierdzenieEdycjiKontaktu;
    string noweDaneDoZapisu;
    system("cls");

    cout << "Podaj numer kontaktu do edycji: "<< endl;
    cin >> idOsoba;
    if (mojaKsiazka[idOsoba].idOsoba==idOsoba)
       {
        cout << mojaKsiazka[idOsoba].nazwisko <<' '<< mojaKsiazka[idOsoba].imie <<' '<< mojaKsiazka[idOsoba].nr_telefonu <<' ';
        cout << mojaKsiazka[idOsoba].mail <<' '<< mojaKsiazka[idOsoba].adres << endl;
        Sleep(1000);
        cout << "Potwierdzasz edycje tego kontaktu?"<<endl;
        Sleep(1000);
        cout << "1.Tak\n2.Nie"<<endl;
        cin >> potwierdzenieEdycjiKontaktu;
        system("cls");
       }
    else
        {
        cout << "Brak kontaktu o takim numerze!";
        Sleep(1000);
        system("cls");
        }

if (potwierdzenieEdycjiKontaktu == 1)
   {
        do
        {
        cout << "Wybierz dane do edycji: "<<endl;
        cout << "1. Nazwisko\n2. Imie\n3. Numer telefonu\n4. Adres email\n5. Adres zamieszkania" <<endl;
        cin >> wybraneDaneDoEdycji;
        system("cls");


            switch(wybraneDaneDoEdycji)
            {
                case 1:
                    {
                        cout << "Podaj nowe nazwisko: "<< endl;
                        cin >> noweDaneDoZapisu;
                        mojaKsiazka[idOsoba].nazwisko = noweDaneDoZapisu;
                        break;
                    }
                case 2:
                    {
                        cout << "Podaj nowe imie: "<< endl;
                        cin >> noweDaneDoZapisu;
                        mojaKsiazka[idOsoba].imie = noweDaneDoZapisu;
                        break;
                    }
                case 3:
                    {
                        cout << "Podaj nowy nr telefonu: "<< endl;
                        cin >> noweDaneDoZapisu;
                        mojaKsiazka[idOsoba].nr_telefonu = noweDaneDoZapisu;
                        break;
                    }
                case 4:
                    {
                        cout << "Podaj nowy adres email: "<< endl;
                        cin >> noweDaneDoZapisu;
                        mojaKsiazka[idOsoba].mail = noweDaneDoZapisu;
                        break;
                    }
                case 5:
                    {
                        cout << "Podaj nowy adres zamieszkania: "<< endl;
                        cin >> noweDaneDoZapisu;
                        mojaKsiazka[idOsoba].adres = noweDaneDoZapisu;
                        break;
                    }
                default:
                    {
                        cout << "Wybrano niepoprawna opcje!"<<endl;
                        Sleep(1000);
                        system("cls");
                        continue;
                    }
            }
            break;
        }while(1);
    fstream plik;
    plik.open("ksiazka adresowa.txt", ios::out);

        if (plik.good()==false)
        {
            cout << "Brak pliku";
            exit(0);
        }

   for (int i=1; i<=aktualnaLiczbaZapisanychOsob; i++)
    {
        plik << mojaKsiazka[i].idOsoba<<endl;
        plik << mojaKsiazka[i].imie<<endl;
        plik << mojaKsiazka[i].nazwisko<<endl;
        plik << mojaKsiazka[i].nr_telefonu<<endl;
        plik << mojaKsiazka[i].mail<<endl;
        plik << mojaKsiazka[i].adres<<endl;
    }
   plik.close();
   }


}

int usunWybranaOsobeZKsiazki(daneOsoby mojaKsiazka[], int aktualnaLiczbaZapisanychOsob)
{
    int idOsoba, potwierdzenieUsunieciaKontaktu;

    system("cls");

    cout << "Podaj numer kontaktu do usuniecia: "<<endl;
    cin >> idOsoba;

    system("cls");
    if (idOsoba==mojaKsiazka[idOsoba].idOsoba)
    {
        cout << mojaKsiazka[idOsoba].nazwisko <<' '<< mojaKsiazka[idOsoba].imie <<' '<< mojaKsiazka[idOsoba].nr_telefonu <<' ';
        cout << mojaKsiazka[idOsoba].mail <<' '<< mojaKsiazka[idOsoba].adres << endl;
        Sleep(1000);

        cout << "Potwierdzasz usuniecie tego kontaktu?"<<endl;
        Sleep(1000);
        cout << "1.Tak\n2.Nie"<<endl;
        cin >> potwierdzenieUsunieciaKontaktu;
        system("cls");
    }
    else
    {
        cout << "Brak kontaktu o takim numerze!";
        Sleep(1000);
        system("cls");
    }


if (potwierdzenieUsunieciaKontaktu == 1)
  {
    while(idOsoba<aktualnaLiczbaZapisanychOsob)
    {

      mojaKsiazka[idOsoba].idOsoba = (mojaKsiazka[idOsoba+1].idOsoba);
      mojaKsiazka[idOsoba].idOsoba = mojaKsiazka[idOsoba].idOsoba - 1;
      mojaKsiazka[idOsoba].imie = mojaKsiazka[idOsoba+1].imie;
      mojaKsiazka[idOsoba].nazwisko = mojaKsiazka[idOsoba+1].nazwisko;
      mojaKsiazka[idOsoba].nr_telefonu = mojaKsiazka[idOsoba+1].nr_telefonu;
      mojaKsiazka[idOsoba].mail = mojaKsiazka[idOsoba+1].mail;
      mojaKsiazka[idOsoba].adres = mojaKsiazka[idOsoba+1].adres;
      idOsoba++;
    }

    if (idOsoba==aktualnaLiczbaZapisanychOsob)
    {
      mojaKsiazka[idOsoba].idOsoba = 0;
      mojaKsiazka[idOsoba].imie = ' ';
      mojaKsiazka[idOsoba].nazwisko = ' ';
      mojaKsiazka[idOsoba].nr_telefonu = ' ';
      mojaKsiazka[idOsoba].mail = ' ';
      mojaKsiazka[idOsoba].adres = ' ';
    }


    Sleep(500);
    cout << "Kontakt usunieto!"<<endl;
    Sleep(1000);
    aktualnaLiczbaZapisanychOsob--;

    fstream plik;
    plik.open("ksiazka adresowa.txt", ios::out);

        if (plik.good()==false)
        {
            cout << "Brak pliku";
            exit(0);
        }

    for (int i=1; i<=aktualnaLiczbaZapisanychOsob; i++)
    {
        plik << mojaKsiazka[i].idOsoba<<endl;
        plik << mojaKsiazka[i].imie<<endl;
        plik << mojaKsiazka[i].nazwisko<<endl;
        plik << mojaKsiazka[i].nr_telefonu<<endl;
        plik << mojaKsiazka[i].mail<<endl;
        plik << mojaKsiazka[i].adres<<endl;
    }

    plik.close();
  }
    return aktualnaLiczbaZapisanychOsob;
}

int main()
{
    int aktualnaLiczbaZapisanychOsob=0;
    char wybranaPozycjaMenu;
    daneOsoby mojaKsiazka[1000];

    aktualnaLiczbaZapisanychOsob = wczytajDaneZPliku(mojaKsiazka, aktualnaLiczbaZapisanychOsob);

    while(1)
    {

                system("cls");
                cout << "KSIAZKA ADRESOWA"                   << endl;
                cout << "==================================="<< endl;
                cout << "1. Dodaj kontakt"                   << endl;
                cout << "2. Wyswietl wszystkie kontakty"     << endl;
                cout << "3. Wyszukaj kontakt"                << endl;
                cout << "4. Edytuj kontakt"                  << endl;
                cout << "5. Usun kontakt"               << endl;
                cout << "9. Zakoncz"                         << endl;
                cin  >> wybranaPozycjaMenu;

                if (wybranaPozycjaMenu == '1')
                {
                   aktualnaLiczbaZapisanychOsob = dodajOsobeDoKsiazki(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                }

                else if (wybranaPozycjaMenu == '2')
                {
                    wyswietlCalaKsiazke(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                }

                else if (wybranaPozycjaMenu== '3')
                {

                   system("cls");
                    cout << "Przeszukiwanie kontaktow"<< endl;
                    cout << "================================"<<endl;
                    cout << "1. Wg nazwiska"                 << endl;
                    cout << "2. Wg imienia"   << endl;
                    cout << "9. Powrot"                          << endl;
                    cin  >> wybranaPozycjaMenu;

                        if (wybranaPozycjaMenu == '1')
                            {
                                wyswietlOsobyWgNazwiska(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                            }
                        else if (wybranaPozycjaMenu == '2')
                            {
                                wyswietlOsobyWgImienia(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                            }

                        else if (wybranaPozycjaMenu == '9')
                            {
                                continue;
                            }

                }

                 else if (wybranaPozycjaMenu == '4')
                {
                    zmienDaneOsoby(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                }

                 else if (wybranaPozycjaMenu == '5')
                {
                    aktualnaLiczbaZapisanychOsob = usunWybranaOsobeZKsiazki(mojaKsiazka, aktualnaLiczbaZapisanychOsob);
                }

                else if (wybranaPozycjaMenu == '9')
                {
                    exit(0);
                }
    }
    return 0;
}
