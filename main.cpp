#include <iostream>

#include "headers/Data.h"
#include "headers/Locatie.h"
#include "headers/StatieVreme.h"
#include "headers/Vreme.h"
#include "headers/Average.h"

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
    bool val = d2.VerificaAnBisect();
    cout << "An bisect valoare booleana: " << val << "\n\n\n";

    VremeCurenta v2(l, 42, 93, "Thunderstorm", 1080, 90, 45);
    cout << "OBIECT DE TIP VREMECURENTA\n" << v2 << "\n\n";
    v2.displayInfo();

    VremeForecast v3(l, 42, 93, "Thunderstorm", 1020, 45, 35, 90);
    cout << "OBIECT DE TIP VREMEFORECAST\n" << v3 << "\n\nAVERTIZARI PENTRU OBIECTUL VREMEFORECAST\n";
    v3.displayWarnings();
    v3.displayInfo();
    cout << "\n\n";

    VremePrecedenta v4(l, 42, 93, "Thunderstorm", 1070, d, "Bucharest", "RO");
    cout << "OBIECT DE TIP VREMEPRECEDENTA\n" << v4 << "\n";
    v4.displayInfo();

    unique_ptr<Vreme> obiect = make_unique<VremeCurenta>(v2);
    unique_ptr<Vreme> obiectClonat = obiect->clone();

    cout << "\nObiect original apelare functie de Heat Index: \n";
    obiect->displayInfo();
    cout << "Obiect clonat apelare functie de Heat Index: \n";
    obiectClonat->displayInfo();

    StatieVreme statie(make_unique<VremeCurenta>(l, 10, 10, "Cloudy", 1080, 5, 12));
    cout << "\nInformatii initiale:\n" << statie << "\n";

    statie.seteazaVreme(make_unique<VremeForecast>(l, 42, 93, "Thunderstorm", 1075, 45, 35, 90));
    cout << "\nInformatii actualizate:\n" << statie << "\n";

    StatieVreme statie2;
    statie2 = statie;

    cout << "\nInformatii statie2 (identice ca la statia1):\n" << statie2 << "\n";

    statie2.seteazaVreme(make_unique<VremePrecedenta>(l, 25, 15, "Rainy", 1060, d, "Bucharest", "RO"));

    cout << "\n<< Inainte de schimbare >>\nInformatii statie 1: \n" << statie << "\n\nInformatii statie 2: \n" <<
            statie2 << "\n";
    schimba(statie, statie2);
    cout << "\n<< Dupa schimbare >>\nInformatii statie 1: \n" << statie << "\n\nInformatii statie 2: \n" << statie2 <<
            "\n\n";

    Data dc = DataFactory::dataCurenta();
    cout << "Data curenta: " << dc << "\n";

    Data pz = DataFactory::primaZiAn();
    cout << "Data test pentru prima zi din anul 2000: " << pz << "\n";

    Data pp = DataFactory::dataPredareProiecte();
    cout << "Termenul limita al predarii proiectelor: " << pp << "\n\n\n";

    //este initializata doar longitudinea pentru obiectul de tip locatie, restul este lasat default
    LocatieBuilder b1;
    Locatie locatie1 = b1.seteazaLongitudine(10).build();

    cout << "Locatie1:\n" << locatie1 << "\n\n";

    //este initializata doar latitudinea pentru obiectul de tip locatie, restul este lasat default
    LocatieBuilder b2;
    Locatie locatie2 = b2.seteazaLatitudine(30).build();

    cout << "Locatie2:\n" << locatie2 << "\n\n\n";

    //se asteapta un output de 15, deoarece media temperaturii celor 3 obiecte de
    //tip vreme este de (10+15+20)/3=15
    VremeCurenta vc1(l, 10, 93, "Thunderstorm", 1080, 90, 45);
    VremeCurenta vc2(l, 15, 93, "Thunderstorm", 1080, 90, 45);
    VremeCurenta vc3(l, 20, 93, "Thunderstorm", 1080, 90, 45);
    Average<VremeCurenta> ob1;
    ob1.calculeazaAverage(vc1, vc2, vc3);


    //se asteapta un output de 25.4
    VremeForecast vf1(l, 20, 93, "Thunderstorm", 1020, 45, 35, 90);
    VremeForecast vf2(l, 25.5, 93, "Thunderstorm", 1020, 45, 35, 90);
    VremeForecast vf3(l, 30.7, 93, "Thunderstorm", 1020, 45, 35, 90);
    Average<VremeForecast> ob2;
    ob2.calculeazaAverage(vf1, vf2, vf3);

    cout << "\n\n";

    try {
        // valid, se afiseaza
        StatieVreme testStation1;
        testStation1.seteazaVreme(make_unique<VremeCurenta>(l, 42, 93, "Thunderstorm", 1080, 90, 45));
        testStation1.display();

        cout << endl;

        // eroare: temperatura invalida
        StatieVreme testStation2;
        testStation2.seteazaVreme(make_unique<VremeCurenta>(l, 150, 93, "Thunderstorm", 1080, 90, 45));
        testStation2.display();
    } catch (const std::runtime_error &e) {
        cout << "\n\t" << e.what() << "\n";
    }

    try {
        // eroare: maxTemp < minTemp
        StatieVreme testStation3;
        testStation3.seteazaVreme(make_unique<VremeForecast>(l, 42, 93, "Thunderstorm", 1075, 20, 35, 90));
        testStation3.display();
    } catch (const std::runtime_error &e) {
        cout << "\n\t" << e.what() << "\n";
    }

    try {
        // eroare : statie goala
        StatieVreme statieGoala;
        statieGoala.display();
    } catch (const std::runtime_error &err) {
        cout << "\n\t" << err.what() << endl;
    }

    return 0;
}