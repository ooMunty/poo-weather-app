//
// Created by Munty on 08/01/2025.
//

#ifndef AVERAGE_H
#define AVERAGE_H

template<typename T>
class Average {
public:
    void calculeazaAverage(T ob1, T ob2, T ob3) {
        double average = (ob1.getTemperatura() + ob2.getTemperatura() + ob3.getTemperatura()) / 3;
        std::cout << "Temperatura medie pentru obiectele date, cu temperaturile t1: " << ob1.getTemperatura() <<
                " grade, temperatura t2: "
                << ob2.getTemperatura() << " grade si temperatura t3: " << ob3.getTemperatura() << " grade este: " <<
                average
                << "\n";
    }
};

#endif //AVERAGE_H
