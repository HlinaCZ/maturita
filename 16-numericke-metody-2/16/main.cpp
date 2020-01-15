#include <fstream>
#include <iostream>

struct SoustavaRovnic {
  double Matice[10][10];
  int pocetRovnic;
  double nezname[10];
};

SoustavaRovnic *nactiMatici(std::string filename);
void tiskni_matici(SoustavaRovnic s);
void eliminacni_metoda(SoustavaRovnic s);

int main() {
  SoustavaRovnic *soustava =
      nactiMatici("/home/hlina/Programming/School/maturita/"
                  "16-numericke-metody-2/16/matrix.txt");
  tiskni_matici(*soustava);
  eliminacni_metoda(*soustava);

  return 0;
}

SoustavaRovnic *nactiMatici(std::string filename) {
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
  for (int rovnice = 0; rovnice < s.pocetRovnic; ++rovnice) {
    for (int prvek = 0; prvek < s.pocetRovnic + 1; ++prvek) {
      std::cout << s.Matice[rovnice][prvek] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void eliminacni_metoda(SoustavaRovnic s) {
  // Stupnovity tvar

  // Pro vsechny rovnice krome posledni
  for (int i = 0; i < s.pocetRovnic - 1; ++i) {
    // Upravime nasledujici rovnici
    for (int j = i + 1; j < s.pocetRovnic; ++j) {
      double nasobek = s.Matice[j][i] / s.Matice[i][i];

      // pro vsechny prvky od indexu [j][i]
      for (int k = i + 1; k < s.pocetRovnic + 1; ++k) {
        s.Matice[j][k] -= nasobek * s.Matice[i][k];
      }
    }
  }

  tiskni_matici(s);

  // Diskuze
  // 0*x = ?
  if (s.Matice[s.pocetRovnic - 1][s.pocetRovnic - 1] == 0.0) {
    // 0*x = 0
    if (s.Matice[s.pocetRovnic - 1][s.pocetRovnic] == 0.0) {
      std::cout << "Nekonecne mnoho reseni" << std::endl;
      return;
    } else {
      std::cout << "Nema reseni" << std::endl;
      return;
    }
  } else {
    // Zpetny chod
    s.nezname[s.pocetRovnic - 1] =
        s.Matice[s.pocetRovnic - 1][s.pocetRovnic] /
        s.Matice[s.pocetRovnic - 1][s.pocetRovnic - 1];

    for (int neznama = s.pocetRovnic - 2; neznama >= 0; --neznama) {
      double vysledek = s.Matice[neznama][s.pocetRovnic];
      for (int i = s.pocetRovnic - 1; i >= neznama + 1; --i) {
        vysledek -= s.Matice[neznama][i] * s.nezname[i];
      }

      s.nezname[neznama] = vysledek / s.Matice[neznama][neznama];
    }
  }

  for (int i = 0; i < s.pocetRovnic; ++i)
    std::cout << 'x' << i << ": " << s.nezname[i] << ", ";
  std::cout << std::endl;
}
