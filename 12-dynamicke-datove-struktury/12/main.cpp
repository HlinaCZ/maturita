#include <fstream>
#include <iostream>

struct Prvek {
  int cislo;
  Prvek *dalsi;
};

Prvek *start = nullptr;

void pridej(int hodnota);
void tisk();

int main() {
  pridej(3);
  tisk();
  pridej(1);
  tisk();
  pridej(2);
  tisk();
  pridej(6);
  tisk();
  pridej(5);
  tisk();

  return 0;
}

void pridej(int hodnota) {
  if ((start == nullptr) || (start->cislo > hodnota)) {
    // Musim pridat prvek na zacatek
    Prvek *pom = new Prvek;
    pom->cislo = hodnota;
    pom->dalsi = start;
    start = pom;
  } else {
    // musim najit ukazatel na prvek,
    // za ktery novy prvek umistim
    Prvek *pom = start;

    while ((pom->dalsi != nullptr) && (pom->dalsi->cislo < hodnota)) {
      pom = pom->dalsi;
    }

    Prvek *pom2 = new Prvek;
    pom2->cislo = hodnota;
    pom2->dalsi = pom->dalsi;
    pom->dalsi = pom2;
  }
}

void tisk() {
  Prvek *pom = start;

  while (pom != nullptr) {
    std::cout << pom->cislo << " ";
    pom = pom->dalsi;
  }
  std::cout << std::endl << std::endl;
}
