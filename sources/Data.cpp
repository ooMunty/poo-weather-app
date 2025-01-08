#include "../headers/Data.h"
#include <vector>
#include <ctime>
#include <string>

Data::Data(int o_, int z_, int l_, int a_) : ora(o_), zi(z_), luna(l_), an(a_) {
}

std::ostream &operator<<(std::ostream &os, const Data &d) {
    //se converteste la string pentru a evita eroare in cazul orelor de tipul ab:0c, care sunt afisate incorect
    std::string oraAfisare = std::to_string(d.ora);
    os << "Ora " << oraAfisare << " ziua " << d.zi << " a lunii " << d.luna << " din anul "
            << d.an;
    return os;
}

bool Data::VerificaAnBisect() const {
    if (an % 4 == 0) return true;
    else return false;
}

void Data::CalculeazaZileInLuna() const {
    std::vector<int> luniCu31Zile = {1, 3, 5, 7, 8, 10, 12};
    if (luna == 2) {
        if (VerificaAnBisect() == true) std::cout << "\nLuna selectata are 29 de zile.\n";
        else std::cout << "\nLuna selectata are 28 de zile.\n";
    } else {
        bool lunaGasita = false;
        for (int i: luniCu31Zile) {
            if (luna == i) {
                std::cout << "\nLuna selectata are 31 de zile.\n";
                lunaGasita = true;
                break;
            }
        }
        if (lunaGasita == false) std::cout << "\nLuna selectata are 30 de zile.\n";
    }
}

Data::~Data() = default;


Data DataFactory::dataCurenta() {
    const std::time_t t = std::time(0); //get current time
    const std::tm *now = std::localtime(&t);

    return Data{(now->tm_hour) * 100 + now->tm_min, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900};
}

Data DataFactory::primaZiAn() {
    return Data{1111, 1, 1, 2000};
}

Data DataFactory::dataPredareProiecte() {
    return Data{2359, 9, 1, 2025};
}
