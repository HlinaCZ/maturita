#include <cmath>
#include <fstream>
#include <iostream>

struct SoustavaRovnic {
  int pocetRovnic;
  double nezname[10];
  double Matice[10][10];
};

SoustavaRovnic *nacti_matici(std::string filename);
void tiskni_matici(SoustavaRovnic s);
void iteracni_metoda(SoustavaRovnic s);

int main() {
  SoustavaRovnic *s = nacti_matici("../16-iter/Matice.txt");
  tiskni_matici(*s);
  iteracni_metoda(*s);

  return 0;
}

void iteracni_metoda(SoustavaRovnic s) {
  // osamostatnit si Xs
  for (int i = 0; i < s.pocetRovnic; ++i) {
    for (int j = 0; j < s.pocetRovnic + 1; ++j) {
      if (j != i)
        s.Matice[i][j] /= s.Matice[i][i];
    }
    s.Matice[i][i] = 0;
  }

  // Xs = 1
  for (int i = 0; i < s.pocetRovnic; ++i) {
    s.nezname[i] = 1;
  }

  // zpetny chod
  double x;
  do {
    x = s.nezname[0];
    for (int i = 0; i < s.pocetRovnic; ++i) {
      double vysledek = s.Matice[i][s.pocetRovnic];
      for (int j = 0; j < s.pocetRovnic + 1; ++j) {
        vysledek -= s.Matice[i][j] * s.nezname[j];
      }
      s.nezname[i] = vysledek;
    }
  } while (fabs(x - s.nezname[0]) > 0.0001);

  for (int i = 0; i < s.pocetRovnic; ++i) {
    std::cout << "x" << i << ": " << s.nezname[i] << ", ";
  }
  std::cout << std::endl;
}

SoustavaRovnic *nacti_matici(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return nullptr;
  }

  SoustavaRovnic *s = new SoustavaRovnic;

  file >> s->pocetRovnic;

  for (int rovnice = 0; rovnice < s->pocetRovnic; ++rovnice) {
    for (int prvek = 0; prvek < s->pocetRovnic + 1; ++prvek) {
      file >> s->Matice[rovnice][prvek];
    }
  }

  return s;
}

void tiskni_matici(SoustavaRovnic s) {
  for (int radek = 0; radek < s.pocetRovnic; ++radek) {
    for (int prvek = 0; prvek < s.pocetRovnic + 1; ++prvek) {
      std::cout << s.Matice[radek][prvek] << ' ';
    }
    std::cout << std::endl;
  }
}
