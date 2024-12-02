//
// Created by Munty on 28/11/2024.
//

#ifndef FORECAST_H
#define FORECAST_H
#include <vector>

#include "Vreme.h"

class Forecast {
private:
    std::vector<Vreme *> forecast;

public:
    explicit Forecast(const std::vector<Vreme *> &v);
    void CalculeazaAverage();
    ~Forecast();
};

#endif //FORECAST_H
