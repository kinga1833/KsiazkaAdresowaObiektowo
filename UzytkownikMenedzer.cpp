#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    cout << " >>> REJESTRACJA <<< " << endl << endl;
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawID(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout <<"Podaj login: ";
        cin >>login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i< uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i = 0; i< uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzID() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}
int UzytkownikMenedzer::logowanieUzytkownika()
{
    string login = "", haslo = "";
    cout << ">>>  LOGOWANIE  <<<" << endl << endl;
    cout << "Podaj login: ";
    cin >> login;

    while (true)
    {
        for (int i=0; i<uzytkownicy.size(); i++)
        {
            if(uzytkownicy[i].pobierzLogin() == login)
            {
                for (int iloscProb = 3; iloscProb > 0; iloscProb--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                    cin >> haslo;

                    if (uzytkownicy[i].pobierzHaslo() == haslo)
                    {
                        idZalogowanegoUzytkownika = uzytkownicy[i].pobierzID();
                        cout << endl << "Zalogowales sie."<< endl << endl;
                        system("pause");
                        return idZalogowanegoUzytkownika;
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                return 0;
            }
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        return 0;
    }
}
void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzID() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");

        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}
bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
