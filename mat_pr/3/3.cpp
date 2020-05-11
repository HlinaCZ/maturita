#include <iostream>
#include <fstream>

struct zavodnik{
    std::string jmeno;
    int hodnoceni;
};

int main()
{
    zavodnik zavodnici[100];

    std::ifstream file("/home/hlina/Programming/School/maturita/mat_pr/3/ZAVOD.txt");
    if(!file.is_open()) {
        std::cerr << "Coulnd't open file" << std::endl;
    }

    int pocet = 0;

    while (file >> zavodnici[pocet].jmeno) {
        file >> zavodnici[pocet].hodnoceni;
        pocet++;
    }

    for (int i = 0; i < pocet-1; ++i) {
        for (int j = i; j < pocet-1; ++j) {
            if (zavodnici[j].hodnoceni > zavodnici[j + 1].hodnoceni) {
                zavodnik tmp = zavodnici[j + 1];
                zavodnici[j + 1] = zavodnici[j];
                zavodnici[j] = tmp;
            }
        }
    }

    for (int i = 0; i < pocet; ++i) {
        std::cout << zavodnici[i].jmeno << ' ' << zavodnici[i].hodnoceni << std::endl;
    }

    file.close();

    return 0;
}