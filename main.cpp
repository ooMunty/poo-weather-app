#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
private:
    int ora; //military format
    int zi;
    int luna;
    int an;

public:
    Data(int o_, int z_, int l_, int a_) : ora{o_}, zi{z_}, luna{l_}, an{a_} {
        // cout<<"\t\t***Constructor de INITIALIZARE pentru Data***"<<endl;
    }

    friend ostream &operator<<(ostream &os, const Data &d) {
        os << "Ora: " << d.ora << " ziua: " << d.zi << " a lunii: " << d.luna << " din anul: " << d.an << endl;
        return os;
    }

    bool VerificaAnBisect() {
        if (an % 4 == 0) return true;
        else return false;
    }

    void CalculeazaZileInLuna() {
        vector<int> luni_cu_31_zile = {1, 3, 5, 7, 8, 10, 12};
        if (luna == 2) {
            if (VerificaAnBisect() == true) cout << "Luna selectata are 29 de zile" << endl;
            else cout << "Luna selectata are 28 de zile" << endl;
        } else {
            bool luna_gasita = false;
            for (int i: luni_cu_31_zile) {
                if (luna == i) {
                    cout << "Luna selectata are 31 de zile" << endl;
                    luna_gasita = true;
                    break;
                }
            }
            if (luna_gasita == false) cout << "Luna selectata are 30 de zile" << endl;
        }
    }

    ~Data() {
        // cout<<"\t\t***Destructor pentru Data***"<<endl;
    }
};

class Vreme {
private:
    Data datetime;
    string oras;
    string tara;
    double temperatura;
    double umiditate;
    double viteza_vant;
    double presiune;
    string conditie;

public:
    Vreme(Data d_, const string &o_, const string &ta_, double te_, double u_, double vv_, double p_,
          const string &c_) : datetime{d_}, oras{o_}, tara{ta_}, temperatura{te_}, umiditate{u_}, viteza_vant{vv_},
                              presiune{p_}, conditie{c_} {
        // cout<<"\t\t***Constructor de INITIALIZARE Vreme***"<<endl;
    }

    Vreme(const Vreme &other) : datetime{other.datetime}, oras{other.oras}, tara{other.tara},
                                temperatura{other.temperatura}, umiditate{other.umiditate},
                                viteza_vant{other.viteza_vant}, presiune{other.presiune}, conditie{other.conditie} {
        // cout<<"\t\t***Constructor de COPIERE Vreme***"<<endl;
    }

    // const string &get_oras() const { return oras; }
    // const string &get_tara() const { return tara; }
    double get_temperatura() const { return temperatura; }
    double get_umiditate() const { return umiditate; }
    double get_viteza_vant() const { return viteza_vant; }
    // double get_presiune() const { return presiune; }
    const string &get_conditie() const { return conditie; }

    Vreme &operator=(const Vreme &other) {
        datetime = other.datetime;
        oras = other.oras;
        tara = other.tara;
        temperatura = other.temperatura;
        umiditate = other.umiditate;
        viteza_vant = other.viteza_vant;
        presiune = other.presiune;
        conditie = other.conditie;
        // cout<<"\t\t***operator= copiere pentru Vreme***"<<endl;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Vreme &v) {
        os << "Data>>" << v.datetime << "Oras: " << v.oras << "\nTara: " << v.tara << "\nTemperatura: " << v.temperatura
                << " grade\nUmiditate: " << v.umiditate << "%\nViteza vantului: " << v.viteza_vant <<
                " kmph\nPresiune: " << v.presiune << " Pa\nConditie: " << v.conditie << endl;
        return os;
    }

    ~Vreme() {
        // cout<<"\t\t***Destructor pentru Vreme***"<<endl;
    }
};

class Locatie {
private:
    double latitudine;
    double longitudine;

public:
    explicit Locatie(double lat_ = 44.4, double long_ = 26.1) : latitudine{lat_}, longitudine{long_} {
        // cout<<"\t\t***Constructor de INITIALIZARE pentru Locatie***"<<endl;
    }

    // double get_latitudine() const { return latitudine; }
    // double get_longitudine() const { return longitudine; }

    friend ostream &operator<<(ostream &os, const Locatie &d) {
        os << "Latitudine: " << d.latitudine << "\nLongitudine: " << d.longitudine << endl;
        return os;
    }

    ~Locatie() {
        // cout<<"\t\t***Destructor pentru Locatie***"<<endl;
    }
};

class Avertizari {
private:
    Vreme v;

public:
    explicit Avertizari(const Vreme& v_) : v{v_} {
        // cout<<"\t\t***Constructor de INITIALIZARE pentru Avertizari***"<<endl;
    }

    void displayWarnings() {
        cout << "Avertizari de vreme:\n";

        bool warning_issued = false;

        if (v.get_temperatura() > 40) {
            cout <<
                    "- Caldura extrema: Temperatura trece de 40 grade Celsius. Stai hidratat si minimizeaza iesitul afara!\n";
            warning_issued = true;
        } else if (v.get_temperatura() < -10) {
            cout << "- Frig extrem: Temperatura e sub -10 grade Celsius. Imbraca-te bine si nu uita sa porti manusi!\n";
            warning_issued = true;
        }

        if (v.get_umiditate() > 90) {
            cout << "- Umiditate foarte ridicata: peste 90%. Risc de dehidratare sever, bea cat mai multa apa!\n";
            warning_issued = true;
        }

        if (v.get_viteza_vant() > 70) {
            cout <<
                    "- Vant extrem: Viteza vantului e mai mare de 70 kmph. Evita activitatile ce presupun iesitul afara si in cazuri extreme securizeaza obiectele periculoase!\n";
            warning_issued = true;
        }

        if (v.get_conditie() == "Thunderstorm" || v.get_conditie() == "Tornado") {
            cout << "- Vreme extrema: " << v.get_conditie() << ". Ia precautiile corespunzatoare si stai informat!\n";
            warning_issued = true;
        }

        if (!warning_issued) {
            cout << "Vreme normala. Bucura-te de o zi frumoasa!\n";
        }
    }

    ~Avertizari() {
        // cout<<"\t\t***Destructor pentru Avertizari***"<<endl;
    }
};

class Forecast {
private:
    vector<Vreme *> forecast;

public:
    explicit Forecast(vector<Vreme *> v) : forecast{move(v)} {
        // cout<<"\t\t***Constructor de INITIALIZARE pentru Forecast***"<<endl;
    }

    void CalculeazaAverage() {
        int i = 0;
        double sum = 0;
        for (const Vreme *v: forecast) {
            sum += v->get_temperatura();
            i++;
        }
        cout << "Temperatura medie pentru perioada data este de: " << sum / i << " grade Celsius" << endl;
    }

    ~Forecast() {
        // cout<<"\t\t***Destructor pentru Forecast***"<<endl;
    }
};


int main() {
    Locatie locatie;
    cout << locatie;

    Data d(1114, 5, 11, 2024);
    cout << d;
    // d.CalculeazaZileInLuna();

    Vreme v(d, "Bucharest", "RO", 35.3, 45, 5.15, 1.5, "Cloudy");
    cout << v;

    Data d2(2030, 29, 2, 2020);
    d2.CalculeazaZileInLuna();
    Vreme v2(d2, "Cluj", "RO", 42, 93, 76, 3.5, "Thunderstorm");

    bool val=d2.VerificaAnBisect();
    cout<<val<<endl;

    Avertizari a(v2);
    a.displayWarnings();

    vector <Vreme *> vreme={&v, &v2};
    Forecast f(vreme);
    f.CalculeazaAverage();


    return 0;
}