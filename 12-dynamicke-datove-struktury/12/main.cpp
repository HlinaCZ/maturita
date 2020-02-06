#include <fstream>
#include <iostream>

using namespace std;

struct Prvek {
  string slovo;
  unsigned int pocet;
  Prvek *dalsi;
};

int main() {
  string nacteneSlovo;
  Prvek *prvni = nullptr;

  ifstream soubor("/home/hlina/Programming/School/maturita/"
                  "12-dynamicke-datove-struktury/12/zprava.txt");
  if (!soubor.is_open())
    return 1;

  while (soubor >> nacteneSlovo) {
    // cout << nacteneSlovo << endl;

    Prvek *pom = prvni;
    // Hledej nacteneSlovo v linearnim listu
    while (pom != nullptr && pom->slovo != nacteneSlovo) {
      pom = pom->dalsi;
    }

    if (pom == nullptr) {
      // Pokud jsme slovo nenasli pridej ho do listu
      pom = new Prvek;
      pom->slovo = nacteneSlovo;
      pom->dalsi = prvni;
      prvni = pom;
    } else {
      // Prvek jsme nasli, zvys pocet o 1
      pom->pocet += 1;
    }
  }

  // Tiskni list
  Prvek *pom = prvni;
  do {
    cout << pom->slovo << ": " << pom->pocet << endl;
  } while (pom != nullptr && (pom = pom->dalsi));

  soubor.close();

  return 0;
}
