#include <iostream>
#include <string>

class BankovniUcet {
protected:
    std::string cisloUctu;
    int hotovost;

public:
    BankovniUcet(std::string ucet, int pocatecniCastka);

    void vypisUdaje();

    void vklad(int castkaVkladu);

    virtual int vyber(int castkaVyberu);

    virtual void prevod(int suma, BankovniUcet *ucet2);
};

class UcetsPoplatkem : public BankovniUcet {
    int Poplatek;

public:
    UcetsPoplatkem(std::string ucet, int pocatecniCastka, int poplatek);

    virtual int vyber(int castkaVyberu);

    virtual void prevod(int suma, BankovniUcet *ucet2);
};

int main() {
    BankovniUcet *ucet1, *ucet2;
    ucet1 = new UcetsPoplatkem("123456789", 10000, 3);
    ucet2 = new BankovniUcet("55555555", 10000);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    ucet1->vyber(100);
    ucet2->vyber(5000);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    ucet1->prevod(9000, ucet2);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    delete ucet1;
    delete ucet2;

    return 0;
}

UcetsPoplatkem::UcetsPoplatkem(std::string ucet, int pocatecniCastka, int poplatek) : BankovniUcet(ucet, pocatecniCastka), Poplatek(poplatek) {
}

int UcetsPoplatkem::vyber(int castkaVyberu) {
    if (hotovost > castkaVyberu + Poplatek) {
        hotovost -= castkaVyberu + Poplatek;
    } else {
        std::cout << "Neni dostatek penez" << std::endl;
    }
}

void UcetsPoplatkem::prevod(int suma, BankovniUcet *ucet2) {

    if (suma + Poplatek > hotovost) {
        std::cout << "Neni dostatek penez" << std::endl;
        return;
    }
    hotovost -= suma + Poplatek;
    ucet2->vklad(suma);
}

BankovniUcet::BankovniUcet(std::string ucet, int pocatecniCastka) : cisloUctu(ucet), hotovost(pocatecniCastka) {
}

void BankovniUcet::vypisUdaje() {
    std::cout << "Ucet: " << cisloUctu << "\nHotovost: " << hotovost << std::endl;
}

void BankovniUcet::vklad(int castkaVkladu) {
    if (castkaVkladu > 0) {
        hotovost += castkaVkladu;
    } else {
        std::cout << "Neni dostatek penez" << std::endl;
    }
}

int BankovniUcet::vyber(int castkaVyberu) {
    if (castkaVyberu > 0 && hotovost > castkaVyberu) {
        hotovost -= castkaVyberu;
        return castkaVyberu;
    }
    return -1;
}

void BankovniUcet::prevod(int suma, BankovniUcet *ucet2) {
    if (suma > hotovost) {
        return;
    }
    hotovost -= suma;
    ucet2->vklad(suma);
}
