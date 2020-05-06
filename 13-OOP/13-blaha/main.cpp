#include <cstdlib> // rand()
#include <ctime>
#include <iostream>

class SetridenePole {
private:
  int *polePrvku;
  int pocetPrvku = 0;
  int maxPocet;

public:
  SetridenePole(int max);
  ~SetridenePole();
  int vlozDoPole(int cislo);
  void tiskniPole();
};

SetridenePole::SetridenePole(int max) { /* : maxPocet(max), pocetPrvku(0) { */
  polePrvku = new int[max];
  maxPocet = max;
}

SetridenePole::~SetridenePole() {
  delete[] polePrvku;
  std::cout << "dying...";
}

int SetridenePole::vlozDoPole(int cislo) {
  if (maxPocet == pocetPrvku) {
    return 0;
  }

  polePrvku[pocetPrvku] = cislo;
  pocetPrvku++;

  int kdeJeNovyPrvek = pocetPrvku - 1;

  while (kdeJeNovyPrvek > 0 &&
         polePrvku[kdeJeNovyPrvek] < polePrvku[kdeJeNovyPrvek - 1]) {
    polePrvku[kdeJeNovyPrvek] = polePrvku[kdeJeNovyPrvek - 1];
    polePrvku[kdeJeNovyPrvek - 1] = cislo;

    kdeJeNovyPrvek--;
  }

  return 1;
}

void SetridenePole::tiskniPole() {
  for (int i = 0; i < pocetPrvku; ++i) {
    std::cout << polePrvku[i] << ' ';
  }
  std::cout << std::endl;
}

int main() {
  srand(time(nullptr));

  SetridenePole pole(10);

  for (int i = 0; i < 15; ++i) {
    if (pole.vlozDoPole(rand() % 500) == 1)
      std::cout << "Uspesne vlozeno" << std::endl;
    else
      std::cout << "Neuspesne vlozeni" << std::endl;

    pole.tiskniPole();
  }

  return 0;
}
