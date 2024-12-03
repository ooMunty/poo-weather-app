//
// Created by Munty on 02/12/2024.
//

#include "../headers/StatieVreme.h"

StatieVreme::StatieVreme() : vreme(nullptr) {}

StatieVreme::StatieVreme(std::unique_ptr<Vreme> v) : vreme(std::move(v)) {}

StatieVreme::StatieVreme(const StatieVreme& other) : vreme(other.vreme ? other.vreme->clone() : nullptr) {}

//copy-swap
StatieVreme &StatieVreme::operator=(StatieVreme other) {
    swap(vreme, other.vreme);
    return *this;
}

//swap
void schimba(StatieVreme& unu, StatieVreme& doi) noexcept{
    using std::swap;
    swap(unu.vreme, doi.vreme);
}

void StatieVreme::seteazaVreme(std::unique_ptr<Vreme> v) {
    vreme = std::move(v);
}

void StatieVreme::display() const {
    if (vreme) {
        vreme->displayInfo();
    } else {
        std::cout << "Nu exista informatii.\n";
    }
}