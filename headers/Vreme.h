//
// Created by Munty on 27/11/2024.
//

#ifndef VREME_H
#define VREME_H
#include <string>
#include "Data.h"
#include "Locatie.h"

class Vreme {
protected:
    Locatie locatie;
    double temperatura;
    double umiditate;
    std::string conditie;
    double presiune;

public:
    Vreme(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune);
    Vreme(const Vreme &other);

    [[nodiscard]] double getTemperatura() const;
    [[nodiscard]] double getUmiditate() const;
    [[nodiscard]] std::string &getConditie();

    Vreme &operator=(const Vreme &other);
    friend std::ostream &operator<<(std::ostream &os, const Vreme &v);
    virtual ~Vreme();
};

class VremeCurenta: public Vreme {
private:
    double sansePp;
    double feelsLike;
public:
    VremeCurenta(const Vreme &other, double sansePp, double feelsLike);
    friend std::ostream & operator<<(std::ostream &os, const VremeCurenta &vc);
    ~VremeCurenta() override;
};

class VremeForecast : public Vreme {
private:
    double maxTemp;
    double minTemp;
    double vitezaVant;
public:
    VremeForecast(const Vreme &other, double maxTemp, double minTemp, double vitezaVant);
    friend std::ostream & operator<<(std::ostream &os, const VremeForecast &vf);
    void displayWarnings() const;
    ~VremeForecast() override;
};

class VremePrecedenta : public Vreme {
private:
    Data dateTime;
    std::string oras;
    std::string tara;
public:
    VremePrecedenta(const Vreme &other, const Data &dateTime, std::string oras, std::string tara);
    friend std::ostream & operator<<(std::ostream &os, const VremePrecedenta &vp);
    ~VremePrecedenta() override;
};

#endif //VREME_H
