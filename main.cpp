#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
    ksiazkaAdresowa.edytujAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
}
