#include <iostream>
// #include <vector>

#include "headers/Locatie.h"
#include "headers/Data.h"
#include "headers/Vreme.h"

using namespace std;

int main() {
    Locatie l;
    cout << l << "\n";

    Data d(1114, 5, 11, 2024);
    cout << d;
    d.CalculeazaZileInLuna();
    cout<<"\n";

    Data d2(2030, 29, 2, 2020);
    d2.CalculeazaZileInLuna();
    bool val=d2.VerificaAnBisect();
    cout << "An bisect valoare booleana: " << val << "\n\n\n";

    Vreme v(l, 42, 93, "Thunderstorm", 3.5);
    cout << "OBIECT DE TIP VREME\n" << v << "\n\n";

    VremeCurenta v2(v, 90, 45);
    cout << "OBIECT DE TIP VREMECURENTA\n" << v2 << "\n\n";

    VremeForecast v3(v, 45, 35, 90);
    cout << "OBIECT DE TIP VREMEFORECAST\n" << v3 << "\n\nWARNINGS PENTRU OBIECTUL VREMEFORECAST\n";
    v3.displayWarnings();
    cout << "\n\n";

    VremePrecedenta v4(v, d, "Bucharest", "RO");
    cout << "OBIECT DE TIP VREMEPRECEDENTA\n" << v4 << "\n";


    return 0;
}