//
// Created by Munty on 27/11/2024.
//

#ifndef VREME_H
#define VREME_H
#include <string>
#include <memory>
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

    Vreme &operator=(const Vreme &other);

    friend std::ostream &operator<<(std::ostream &os, const Vreme &v);

    [[nodiscard]] virtual double calculeazaIndexCaldura() const;

    virtual void displayInfo() const = 0;

    [[nodiscard]] virtual std::unique_ptr<Vreme> clone() const;

    virtual ~Vreme();
};

class VremeCurenta : public Vreme {
private:
    double sansePp;
    double feelsLike;

public:
    VremeCurenta(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, double sansePp, double feelsLike);

    friend std::ostream &operator<<(std::ostream &os, const VremeCurenta &vc);

    void displayInfo() const override;

    [[nodiscard]] std::unique_ptr<Vreme> clone() const override;

    [[nodiscard]] double getSansePp() const;

    [[nodiscard]] double getFeelsLike() const;

    ~VremeCurenta() override;
};

class VremeForecast : public Vreme {
private:
    double maxTemp;
    double minTemp;
    double vitezaVant;

public:
    VremeForecast(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, double maxTemp, double minTemp, double vitezaVant);

    friend std::ostream &operator<<(std::ostream &os, const VremeForecast &vf);

    void displayInfo() const override;

    void displayWarnings() const;

    [[nodiscard]] std::unique_ptr<Vreme> clone() const override;

    [[nodiscard]] double getMaxTemp() const;

    [[nodiscard]] double getMinTemp() const;

    [[nodiscard]] double getVitezaVant() const;

    ~VremeForecast() override;
};

class VremePrecedenta : public Vreme {
private:
    Data dateTime;
    std::string oras;
    std::string tara;

public:
    VremePrecedenta(const Locatie &locatie, double temperatura, double umiditate, std::string conditie, double presiune, const Data &dateTime, std::string oras, std::string tara);

    friend std::ostream &operator<<(std::ostream &os, const VremePrecedenta &vp);

    void displayInfo() const override;

    [[nodiscard]] std::unique_ptr<Vreme> clone() const override;

    [[nodiscard]] Data getDateTime() const;

    [[nodiscard]] const std::string &getOras() const;

    [[nodiscard]] const std::string &getTara() const;

    ~VremePrecedenta() override;
};

#endif //VREME_H
