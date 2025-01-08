#ifndef DATA_H
#define DATA_H
#include <iostream>

class Data {
private:
    int ora; //military format
    int zi;
    int luna;
    int an;
    friend class DataBuilder;

public:
    Data(int o_, int z_, int l_, int a_);

    friend std::ostream &operator<<(std::ostream &os, const Data &d);

    [[nodiscard]] bool VerificaAnBisect() const;

    void CalculeazaZileInLuna() const;

    ~Data();
};

class DataFactory {
public:
    static Data dataCurenta();

    static Data primaZiAn();

    static Data dataPredareProiecte();
};

#endif //DATA_H
