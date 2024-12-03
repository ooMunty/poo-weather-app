//
// Created by Munty on 27/11/2024.
//

#ifndef LOCATIE_H
#define LOCATIE_H

#include <iostream>

class Locatie {
private:
    double latitudine{44.4};
    double longitudine{26.1};

public:
    Locatie() = default;

    Locatie(double lat_, double long_);

    [[nodiscard]] double getLatitudine() const;

    [[nodiscard]] double getLongitudine() const;

    friend std::ostream &operator<<(std::ostream &os, const Locatie &l);

    ~Locatie();
};

#endif //LOCATIE_H
