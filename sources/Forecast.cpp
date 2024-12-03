// //
// // Created by Munty on 28/11/2024.
// //
//
// #include "../headers/Forecast.h"
//
// Forecast::Forecast(const std::vector<Vreme *> &v) : forecast{v} {}
//
// void Forecast::CalculeazaAverage(){
//     int i = 0;
//     double sum = 0;
//     for (Vreme *v: forecast) {
//         sum += v->getTemperatura();
//         i++;
//     }
//     std::cout << "Temperatura medie pentru perioada data este de: " << sum / i << " grade Celsius\n";
// }
//
// Forecast::~Forecast() = default;