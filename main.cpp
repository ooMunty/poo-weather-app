#include <iostream>

#include "headers/Locatie.h"
#include "headers/Data.h"
#include "headers/Vreme.h"
#include "headers/StatieVreme.h"

using namespace std;

int main() {
    Locatie l;
    cout << l << "\n";

    Data d(1114, 5, 11, 2024);
    cout << d;
    d.CalculeazaZileInLuna();
    cout << "\n";

    Data d2(2030, 29, 2, 2020);
    d2.CalculeazaZileInLuna();
    bool val=d2.VerificaAnBisect();
    cout << "An bisect valoare booleana: " << val << "\n\n\n";

    // Vreme v(l, 42, 93, "Thunderstorm", 3.5);
    // cout << "OBIECT DE TIP VREME\n" << v << "\n\n";

    VremeCurenta v2(l, 42, 93, "Thunderstorm", 3.5, 90, 45);
    cout << "OBIECT DE TIP VREMECURENTA\n" << v2 << "\n\n";
    v2.displayInfo();

    VremeForecast v3(l, 42, 93, "Thunderstorm", 3.5, 45, 35, 90);
    cout << "OBIECT DE TIP VREMEFORECAST\n" << v3 << "\n\nWARNINGS PENTRU OBIECTUL VREMEFORECAST\n";
    v3.displayWarnings();
    v3.displayInfo();
    cout << "\n\n";

    VremePrecedenta v4(l, 42, 93, "Thunderstorm", 3.5, d, "Bucharest", "RO");
    cout << "OBIECT DE TIP VREMEPRECEDENTA\n" << v4 << "\n";
    v4.displayInfo();


    unique_ptr<Vreme> obiect = make_unique<VremeCurenta>(v2);
    unique_ptr<Vreme> obiectClonat = obiect->clone();

    cout << "\nObiect original apelare functie de Heat Index: \n";
    obiect->displayInfo();
    cout << "Obiect clonat apelare functie de Heat Index: \n";
    obiectClonat->displayInfo();

    StatieVreme statie(make_unique<VremeCurenta>(l, 10, 10, "Cloudy", 2, 5, 12));
    cout << "\nInformatii initiale:\n";
    statie.display();

    statie.seteazaVreme(make_unique<VremeForecast>(l, 42, 93, "Thunderstorm", 3.5, 45, 35, 90));
    cout << "Informatii actualizate:\n";
    statie.display();

    StatieVreme statie2;
    statie2 = statie;

    cout << "\nInformatii statie2 (identice ca la statia1):\n";
    statie2.display();

    return 0;
}