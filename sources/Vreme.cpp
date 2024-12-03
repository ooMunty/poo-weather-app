//
// Created by Munty on 27/11/2024.
//

#include <utility>
#include <cmath>
#include <chrono>
#include "../headers/Vreme.h"


//CLASA VREME
Vreme::Vreme(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune) : locatie(locatie), temperatura(temperatura), umiditate(umiditate), conditie(std::move(conditie)), presiune(presiune) {}

Vreme::Vreme(const Vreme &other) : locatie{other.locatie}, temperatura{other.temperatura}, umiditate{other.umiditate}, conditie{other.conditie}, presiune{other.presiune} {}

double Vreme::getTemperatura() const { return temperatura; }
double Vreme::getUmiditate() const { return umiditate; }
std::string &Vreme::getConditie() { return conditie; }

Vreme &Vreme::operator=(const Vreme &other) {
    locatie = other.locatie;
    temperatura = other.temperatura;
    umiditate = other.umiditate;
    conditie = other.conditie;
    presiune = other.presiune;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vreme &v) {
    return os << v.locatie << "\nTemperatura: " << v.temperatura << " grade\nUmiditate: " << v.umiditate << "\nConditie: " << v.conditie << "\nPresiune: " << v.presiune << " Pa";
}

double Vreme::calculeazaIndexCaldura() const {
    const double e = 6.112 * exp((17.67 * temperatura) / (temperatura + 243.5));
    const double hi = temperatura + 0.5555 * (e * umiditate / 100 - 10);
    return hi;
}

Vreme::~Vreme() = default;


//CLASA VREMECURENTA
VremeCurenta::VremeCurenta(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, double sansePp, double feelsLike) : Vreme(locatie, temperatura, umiditate, std::move(conditie), presiune), sansePp(sansePp), feelsLike(feelsLike) {}

std::ostream &operator<<(std::ostream &os, const VremeCurenta &vc) {
    return os << static_cast<const Vreme &>(vc) << "\nSanse precipitatii: " << vc.sansePp << "%\nFeels like: " << vc.
           feelsLike << " grade";
}

void VremeCurenta::displayInfo() const  {
    using namespace std::chrono_literals;
    std::cout << "Index caldura: " << calculeazaIndexCaldura() << " grade Celsius\n";
}

std::unique_ptr<Vreme> VremeCurenta::clone() const {
    return std::make_unique<VremeCurenta>(*this);
}

VremeCurenta::~VremeCurenta() = default;


//CLASA VREMEFORECAST
VremeForecast::VremeForecast(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, double maxTemp, double minTemp, double vitezaVant) : Vreme(locatie, temperatura, umiditate, std::move(conditie), presiune), maxTemp(maxTemp), minTemp(minTemp), vitezaVant(vitezaVant) {}

std::ostream &operator<<(std::ostream &os, const VremeForecast &vf) {
    return os << static_cast<const Vreme &>(vf) << "\nTemperatura maxima: " << vf.maxTemp << "\nTemperatura minima " <<
           vf.minTemp << "\nViteza vantului: " << vf.vitezaVant << "kmph";
}

void VremeForecast::displayWarnings() const {
    std::cout << "Avertizari de vreme:\n";

    bool WarningIssued = false;

    if (temperatura > 40) {
        std::cout <<
                "- Caldura extrema: Temperatura trece de 40  grade Celsius. Stai hidratat si minimizeaza iesitul afara!\n";
        WarningIssued = true;
    } else if (temperatura < -10) {
        std::cout <<
                "- Frig extrem: Temperatura e sub -10  grade Celsius. Imbraca-te bine si nu uita sa porti manusi!\n";
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

void VremeForecast::displayInfo() const  {
    using namespace std::chrono_literals;
    std::cout << "Index caldura: " << calculeazaIndexCaldura() << " grade Celsius\n";
}

std::unique_ptr<Vreme> VremeForecast::clone() const {
    return std::make_unique<VremeForecast>(*this);
}

VremeForecast::~VremeForecast() = default;



//CLASA VREMEPRECEDENTA
VremePrecedenta::VremePrecedenta(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, const Data &dateTime, std::string oras, std::string tara) : Vreme(locatie, temperatura, umiditate, std::move(conditie), presiune), dateTime(dateTime), oras(std::move(oras)),tara(std::move(tara)) {}

std::ostream &operator<<(std::ostream &os, const VremePrecedenta &vp) {
    return os << static_cast<const Vreme &>(vp) << "\nData: " << vp.dateTime << "\nOras: " << vp.oras << "\nTara: " << vp.tara;
}

void VremePrecedenta::displayInfo() const  {
    using namespace std::chrono_literals;
    std::cout << "Index caldura: " << calculeazaIndexCaldura() << " grade Celsius\n";
}

std::unique_ptr<Vreme> VremePrecedenta::clone() const {
    return std::make_unique<VremePrecedenta>(*this);
}

VremePrecedenta::~VremePrecedenta() = default;
