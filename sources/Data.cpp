#include "../headers/Data.h"
#include <vector>

Data::Data(int o_, int z_, int l_, int a_) : ora(o_), zi(z_), luna(l_), an(a_) {
}

std::ostream &operator<<(std::ostream &os, const Data &d) {
    os << "Ora " << (d.ora) / 100 << ":" << (d.ora) % 100 << " ziua " << d.zi << " a lunii " << d.luna << " din anul "
            << d.an << "\n";
    return os;
}

bool Data::VerificaAnBisect() const {
    if (an % 4 == 0) return true;
    else return false;
}

void Data::CalculeazaZileInLuna() const {
    std::vector<int> luniCu31Zile = {1, 3, 5, 7, 8, 10, 12};
    if (luna == 2) {
        if (VerificaAnBisect() == true) std::cout << "Luna selectata are 29 de zile.\n";
        else std::cout << "Luna selectata are 28 de zile.\n";
    } else {
        bool lunaGasita = false;
        for (int i: luniCu31Zile) {
            if (luna == i) {
                std::cout << "Luna selectata are 31 de zile.\n";
                lunaGasita = true;
                break;
            }
        }
        if (lunaGasita == false) std::cout << "Luna selectata are 30 de zile.\n";
    }
}

Data::~Data() = default;
