//
// Created by Munty on 27/11/2024.
//

#include "../headers/Locatie.h"

Locatie::Locatie(double lat_, double long_) : latitudine(lat_), longitudine(long_) {
}

std::ostream &operator<<(std::ostream &os, const Locatie &l) {
    os << "Latitudine: " << l.latitudine << "\nLongitudine: " << l.longitudine;
    return os;
}

Locatie::~Locatie() = default;
