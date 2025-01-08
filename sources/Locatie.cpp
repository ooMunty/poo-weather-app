//
// Created by Munty on 27/11/2024.
//

#include "../headers/Locatie.h"

Locatie::Locatie(double lat_, double long_) : latitudine(lat_), longitudine(long_) {}

double Locatie::getLatitudine() const {
    return latitudine;
}

double Locatie::getLongitudine() const {
    return longitudine;
}

std::ostream &operator<<(std::ostream &os, const Locatie &l) {
    os << "Latitudine: " << l.latitudine << "\nLongitudine: " << l.longitudine;
    return os;
}

Locatie::~Locatie() = default;


LocatieBuilder &LocatieBuilder::seteazaLatitudine(double nr) {
    l.latitudine = nr;
    return *this;
}

LocatieBuilder &LocatieBuilder::seteazaLongitudine(double nr) {
    l.longitudine = nr;
    return *this;
}

Locatie LocatieBuilder::build() {
    return l;
}
