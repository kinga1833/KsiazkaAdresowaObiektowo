#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    cout << "Id zalogowanego uzytkowika " << idZalogowanegoUzytkownika << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawID(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Id zalogowanego uzytkowika " << adresat.pobierzIdUzytkownika() << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, numerTelefonu);

    cout << "Podaj email: ";
    cin >> email;

    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

/*void AdresatMenedzer::wypiszWszystkichAdresatow()
{
    for (int i = 0; i< adresaci.size(); i++)
    {
        cout << adresaci[i].pobierzID() << endl;
        cout << adresaci[i].pobierzIdUzytkownika() << endl;
        cout << adresaci[i].pobierzImie() << endl;
        cout << adresaci[i].pobierzNazwisko() << endl;
        cout << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << adresaci[i].pobierzEmail() << endl;
        cout << adresaci[i].pobierzAdres() << endl;
    }
}*/
void AdresatMenedzer::wypiszWszystkichAdresatow()
{
    system ("cls");
    if (!adresaci.empty())
    {
        cout << "           >>> ADRESACI <<< " << endl;
        cout << "---------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
}
void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << adresat.pobierzID() << endl;
    cout << adresat.pobierzIdUzytkownika() << endl;
    cout << adresat.pobierzImie() << endl;
    cout << adresat.pobierzNazwisko() << endl;
    cout << adresat.pobierzNumerTelefonu() << endl;
    cout << adresat.pobierzEmail() << endl;
    cout << adresat.pobierzAdres() << endl;
}
