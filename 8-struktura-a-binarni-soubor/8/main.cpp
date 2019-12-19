#include <fstream>
#include <iostream>

const char filename[] = "data.bin";

/* Struktura je zadana */
struct TCLOVEK {
  char jmeno[30], prijmeni[30];
  char rodneCislo[11];
};

//*****************************************

void empty_bin_file();
void app_cin();
void print_from_bin();

//*****************************************

int main() {
  // empty_bin_file();
  app_cin();
  print_from_bin();

  return 0;
}

//*****************************************

void empty_bin_file() {
  std::ofstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    std::cout << "Neco se pokazilo pri otevirani souboru";
    return;
  }
  file.close();
}

void app_cin() {
  TCLOVEK human;
  std::cout << "Pridejte cloveka" << std::endl << "Jmeno:" << std::endl;
  std::cin >> human.jmeno;
  std::cout << "Prijmeni" << std::endl;
  std::cin >> human.prijmeni;
  std::cout << "Rodne cislo:" << std::endl;
  std::cin >> human.rodneCislo;

  // musi byt fstream, protoze ofstream by soubor smazal !!
  std::fstream file(filename, std::ios::binary | std::ios::out | std::ios::app);
  if (!file.is_open()) {
    std::cout << "Neco se pokazilo pri otevirani souboru";
    return;
  }

  file.write((char *)&human, sizeof(human));

  file.close();

  std::cout << "Udaje zapsany do souboru";
}

void print_from_bin() {
  TCLOVEK human;

  std::ifstream file(filename, std::ios::binary | std::ios::in | std::ios::app);
  if (!file.is_open()) {
    std::cout << "Neco se pokazilo pri otevirani souboru";
    return;
  }

  while (file.read((char *)&human, sizeof(human))) {
    std::cout << "Jmeno: " << human.jmeno << " Prijmeni: " << human.prijmeni
              << " Rodne cislo: " << human.rodneCislo << std::endl;
  }

  file.close();
}
