//
// Created by Munty on 27/11/2024.
//

#include <utility>
#include "../headers/Vreme.h"



//CLASA VREME
Vreme::Vreme(const Locatie& locatie, double temperatura, double umiditate, std::string conditie, double presiune) : locatie(locatie), temperatura(temperatura), umiditate(umiditate), conditie(std::move(conditie)), presiune(presiune) {}

Vreme::Vreme(const Vreme &other) : locatie{other.locatie}, temperatura{other.temperatura}, umiditate{other.umiditate}, conditie{other.conditie}, presiune{other.presiune} {}

// const std::string &get_oras() const { return oras; }
// const std::string &get_tara() const { return tara; }
// double Vreme::GetVitezaVant() const { return vitezaVant; }
// double get_presiune() const { return presiune; }

double Vreme::getTemperatura() const { return temperatura; }
double Vreme::getUmiditate() const { return umiditate; }
std::string &Vreme::getConditie() { return conditie; }

Vreme& Vreme::operator=(const Vreme &other) {
    locatie=other.locatie;
    temperatura = other.temperatura;
    umiditate = other.umiditate;
    conditie = other.conditie;
    presiune = other.presiune;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vreme &v) {
    return os << v.locatie << "\nTemperatura: " << v.temperatura << " grade\nUmiditate: " << v.umiditate << "\nConditie: " << v.conditie << "\nPresiune: " << v.presiune << " Pa";
}

Vreme::~Vreme() = default;



//CLASA VREMECURENTA
VremeCurenta::VremeCurenta(const Vreme &other, double sansePp, double feelsLike) : Vreme(other), sansePp(sansePp), feelsLike(feelsLike) {}

std::ostream &operator<<(std::ostream &os, const VremeCurenta &vc) {
    return os << static_cast<const Vreme &>(vc) << "\nSanse precipitatii: " << vc.sansePp << "%\nFeels like: " << vc.feelsLike << " grade";
}

VremeCurenta::~VremeCurenta() = default;



//CLASA VREMEFORECAST
VremeForecast::VremeForecast(const Vreme &other, double maxTemp, double minTemp, double vitezaVant) : Vreme(other), maxTemp(maxTemp), minTemp(minTemp), vitezaVant(vitezaVant) {}

std::ostream & operator<<(std::ostream &os, const VremeForecast &vf) {
    return os << static_cast<const Vreme &>(vf) << "\nTemperatura maxima: " << vf.maxTemp << "\nTemperatura minima " << vf.minTemp << "\nViteza vantului: " << vf.vitezaVant << "kmph";
}

void VremeForecast::displayWarnings() const {
    std::cout << "Avertizari de vreme:\n";

    bool WarningIssued = false;

    if (temperatura > 40) {
        std::cout << "- Caldura extrema: Temperatura trece de 40 grade Celsius. Stai hidratat si minimizeaza iesitul afara!\n";
        WarningIssued = true;
    } else if (temperatura < -10) {
        std::cout << "- Frig extrem: Temperatura e sub -10 grade Celsius. Imbraca-te bine si nu uita sa porti manusi!\n";
        WarningIssued = true;
    }

    if (umiditate > 90) {
        std::cout << "- Umiditate foarte ridicata: peste 90%. Risc de dehidratare sever, bea cat mai multa apa!\n";
        WarningIssued = true;
    }

    if (vitezaVant > 70) {
        std::cout <<
                "- Vant extrem: Viteza vantului e mai mare de 70 kmph. Evita activitatile ce presupun iesitul afara si in cazuri extreme securizeaza obiectele periculoase!\n";
        WarningIssued = true;
    }

    if (conditie == "Thunderstorm" || conditie == "Tornado") {
        std::cout << "- Vreme extrema: " << conditie << ". Ia precautiile corespunzatoare si stai informat!\n";
        WarningIssued = true;
    }

    if (!WarningIssued) {
        std::cout << "Vreme normala. Bucura-te de o zi frumoasa!\n";
    }
}

VremeForecast::~VremeForecast() = default;




//CLASA VREMEPRECEDENTA
VremePrecedenta::VremePrecedenta(const Vreme &other, const Data &dateTime, std::string oras, std::string tara) : Vreme(other), dateTime(dateTime), oras(std::move(oras)), tara(std::move(tara)) {}

std::ostream & operator<<(std::ostream &os, const VremePrecedenta &vp) {
    return os << static_cast<const Vreme &>(vp) << "\nData: " << vp.dateTime << "\nOras: " << vp.oras << "\nTara: " << vp.tara;
}

VremePrecedenta::~VremePrecedenta() = default;