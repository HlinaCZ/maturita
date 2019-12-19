#include <fstream>
#include <iostream>

int main() {
  std::string line;

  std::ifstream original("/home/hlina/Programming/School/maturita/"
                         "10-txt-soubory/vrahova_vypoved/vypoved.txt");
  std::ofstream result("/home/hlina/Programming/School/maturita/"
                       "10-txt-soubory/vrahova_vypoved/skutecnost.txt");

  if (!original.is_open()) {
    std::cout << "Vypoved.txt se nepodarilo nacist" << std::endl;
    return 0;
  }

  if (!result.is_open()) {
    std::cout << "Skutecnost.txt se nepodarilo nacist" << std::endl;
    return 0;
  }

  while (getline(original, line)) {
    // odstraneni ne na zacatku vsech slov
    std::string::size_type pos;
    do {
      // pozice nalezeneneho " ne"
      pos = line.find(" ne");
      if (pos != std::string::npos)
        line.erase(pos + 1, 2);
    } while (pos != std::string::npos);

    result << line << std::endl;
  }

  original.close();
  result.close();
  return 0;
}
