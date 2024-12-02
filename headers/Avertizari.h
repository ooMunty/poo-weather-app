//
// Created by Munty on 27/11/2024.
//

#ifndef AVERTIZARI_H
#define AVERTIZARI_H

#include "../headers/Vreme.h"

class Avertizari {
private:
    Vreme v;

public:
    explicit Avertizari(const Vreme &v_);
    void DisplayWarnings();
    ~Avertizari();
};

#endif //AVERTIZARI_H
