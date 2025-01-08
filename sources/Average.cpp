//
// Created by Munty on 08/01/2025.
//

#include <iostream>

template<typename T>
void calculeazaAverage(T v1, T v2, T v3) {
    double average = (v1.getTemperatura() + v2.getTemperatura() + v3.getTemperatura()) / 3;
    std::cout << "Temperatura medie pentru obiectele date, cu temperaturile t1: " << v1.getTemperatura() <<
            " grade, temperatura t2: "
            << v2.getTemperatura() << " grade si temperatura t3: " << v3.getTemperatura() << " grade este: " << average
            << "\n";
}
