//
// Created by Munty on 02/12/2024.
//

#ifndef STATIEVREME_H
#define STATIEVREME_H

#include "Vreme.h"

class StatieVreme {
private:
    std::unique_ptr<Vreme> vreme;

public:
    //implicit
    StatieVreme();

    explicit StatieVreme(std::unique_ptr<Vreme> v);

    StatieVreme(const StatieVreme& other);

    //copy-swap
    StatieVreme& operator=(StatieVreme other);

    //swap
    friend void schimba(StatieVreme& unu, StatieVreme& doi) noexcept;

    void seteazaVreme(std::unique_ptr<Vreme> v);

    void display() const;
};

#endif //STATIEVREME_H
