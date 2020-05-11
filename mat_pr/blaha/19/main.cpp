#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

struct TPRACOVNIK {
  char jmeno[50];
  int plat;
  char funkce[30];
};

int main() {
  std::ifstream csvFile(
      "/home/hlina/Programming/School/maturita/mat_pr/blaha/19/text.csv");
  if (!csvFile.is_open())
    std::cerr << "Couldnt open csv file" << std::endl;
  std::ofstream binFile(
      "/home/hlina/Programming/School/maturita/mat_pr/blaha/19/output.bin",
      std::ios::binary | std::ios::out);
  if (!binFile.is_open())
    std::cerr << "Couldnt open bin file" << std::endl;

  int itemIndex = 0, itemStart = 0, itemEnd;
  std::string line, item;
  TPRACOVNIK pracovnik;

  while (std::getline(csvFile, line)) {
    while ((itemEnd = line.find(';', itemStart)) != std::string::npos) {
      item = line.substr(itemStart, itemEnd - itemStart);

      switch (itemIndex) {
      case 0:
        std::cout << "ID: " << item << " ";
        break;
      case 1:
        std::cout << "Jmeno: " << item << " ";
        strcpy(pracovnik.jmeno, item.c_str());
        break;
      case 2:
        std::cout << "Plat: " << item << " ";
        pracovnik.plat = std::stoi(item);
        break;
      }

      itemIndex++;
      itemStart = itemEnd + 1;
    }
    item = line.substr(itemStart);
    std::cout << "Funkce: " << item << std::endl;
    strcpy(pracovnik.funkce, item.c_str());

    binFile.write((char *)&pracovnik, sizeof(pracovnik));

    itemIndex = 0;
    itemStart = 0;
  }

  csvFile.close();
  binFile.close();
}
