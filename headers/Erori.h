//
// Created by Munty on 03/12/2024.
//

#ifndef ERORI_H
#define ERORI_H
#include <stdexcept>

class VremeInvalida : public std::runtime_error {
public:
    explicit VremeInvalida(const std::string &mesaj);

    ~VremeInvalida() override;
};

class VremeEroareClonare : public std::runtime_error {
public:
    explicit VremeEroareClonare(const std::string &mesaj);

    ~VremeEroareClonare() override;
};

class StatieVremeEroareOperatii : public std::runtime_error {
public:
    explicit StatieVremeEroareOperatii(const std::string &mesaj);

    ~StatieVremeEroareOperatii() override;
};

#endif //ERORI_H
