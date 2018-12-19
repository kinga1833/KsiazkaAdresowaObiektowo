#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer()
{
    //plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, uzytkownikMenedzer.idZalogowanegoUzytkownika);
}

int AdresatMenedzer::dodajAdresata(int &idZalogowanegoUzytkownika)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int &idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawID(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << idOstatniegoAdresata << "idOstatniegoAdresata " << endl;
    cout << "Podaj imie: ";
    adresat.ustawImie(wczytajLinie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(wczytajLinie());

    return adresat;
}

string AdresatMenedzer::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, uzytkownikMenedzer.idZalogowanegoUzytkownika);
}
void AdresatMenedzer::wypiszWszystkichAdresatow()
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
}
