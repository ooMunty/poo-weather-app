//
// Created by Munty on 02/12/2024.
//

#include "../headers/StatieVreme.h"
#include "../headers/Erori.h"

StatieVreme::StatieVreme() : vreme(nullptr) {}

StatieVreme::StatieVreme(std::unique_ptr<Vreme> v) : vreme(std::move(v)) {}

StatieVreme::StatieVreme(const StatieVreme &other) : vreme(other.vreme ? other.vreme->clone() : nullptr) {
}

//copy-swap
StatieVreme &StatieVreme::operator=(StatieVreme other) {
    swap(vreme, other.vreme);
    return *this;
}

//swap
void schimba(StatieVreme &unu, StatieVreme &doi) noexcept {
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
        throw StatieVremeEroareOperatii("Nu exista informatii de afisat!");
    }
}

std::ostream &operator<<(std::ostream &os, const StatieVreme &sv) {
    if (sv.vreme) {
        os << *sv.vreme;

        if (auto const *curenta = dynamic_cast<VremeCurenta *>(sv.vreme.get())) {
            std::cout << "\nInformatii aditionale:\nSanse de precipitatii: " << curenta->getSansePp() <<
                    "%, feels like: " << curenta->getFeelsLike()
                    << " grade Celsius\n";
        } else if (auto const *forecast = dynamic_cast<VremeForecast *>(sv.vreme.get())) {
            std::cout << "\nInformatii aditionale:\nTemperatura maxima: " << forecast->getMaxTemp() <<
                    " grade Celsius, temperatura minima: "
                    << forecast->getMinTemp() << " grade Celsius, viteza vantului: " << forecast->getVitezaVant() <<
                    " kmph\n";
        } else if (auto const *precedenta = dynamic_cast<VremePrecedenta *>(sv.vreme.get())) {
            std::cout << "\nInformatii aditionale:\nData: " << precedenta->getDateTime() << ", oras: " << precedenta->
                    getOras() << ", tara: "
                    << precedenta->getTara() << "\n";
        } else {
            std::cout << "Tip de vreme necunoscut!\n";
        }
    } else {
        os << "Nu exista informatii despre vreme\n";
    }
    return os;
}

StatieVreme::~StatieVreme() = default;
