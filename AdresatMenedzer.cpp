#include "AdresatMenedzer.h"

/*AdresatMenedzer::AdresatMenedzer()
{
    idZalogUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
}*/

int AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawID(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogUzytkownika);

    cout << idOstatniegoAdresata << " " << endl;
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
