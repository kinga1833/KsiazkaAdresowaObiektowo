#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include "Adresat.h"
#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    UzytkownikMenedzer uzytkownikMenedzer;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    Adresat podajDaneNowegoAdresata(int &idZalogowanegoUzytkownika);
    string wczytajLinie();

public:
    AdresatMenedzer();
    int dodajAdresata(int &idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();

} ;

#endif
