//
// Created by Munty on 27/11/2024.
//

#include "../headers/Avertizari.h"

Avertizari::Avertizari(const Vreme &v_) : v{v_}{}

void Avertizari::DisplayWarnings() {
    std::cout << "Avertizari de vreme:\n";

    bool warningIssued = false;

    if (v.getTemperatura() > 40) {
        std::cout << "- Caldura extrema: Temperatura trece de 40 grade Celsius. Stai hidratat si minimizeaza iesitul afara!\n";
        warningIssued = true;
    } else if (v.getTemperatura() < -10) {
        std::cout << "- Frig extrem: Temperatura e sub -10 grade Celsius. Imbraca-te bine si nu uita sa porti manusi!\n";
        warningIssued = true;
    }

    if (v.getUmiditate() > 90) {
        std::cout << "- Umiditate foarte ridicata: peste 90%. Risc de dehidratare sever, bea cat mai multa apa!\n";
        warningIssued = true;
    }

    // if (v.getVitezaVant() > 70) {
    //     std::cout <<
    //             "- Vant extrem: Viteza vantului e mai mare de 70 kmph. Evita activitatile ce presupun iesitul afara si in cazuri extreme securizeaza obiectele periculoase!\n";
    //     warningIssued = true;
    // }

    if (v.getConditie() == "Thunderstorm" || v.getConditie() == "Tornado") {
        std::cout << "- Vreme extrema: " << v.getConditie() << ". Ia precautiile corespunzatoare si stai informat!\n";
        warningIssued = true;
    }

    if (!warningIssued) {
        std::cout << "Vreme normala. Bucura-te de o zi frumoasa!\n";
    }
}

Avertizari::~Avertizari() = default;
