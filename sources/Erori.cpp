//
// Created by Munty on 03/12/2024.
//

#include "../headers/Erori.h"
#include <string>


VremeInvalida::VremeInvalida(const std::string &mesaj)
    : runtime_error(std::string("Eroare: date invalide pentru Vreme! >> ") + mesaj) {}
VremeInvalida::~VremeInvalida() = default;

VremeEroareClonare::VremeEroareClonare(const std::string &mesaj)
    : runtime_error(std::string("Eroare: clonare nereusita pentru Vreme! >> ") + mesaj) {}
VremeEroareClonare::~VremeEroareClonare() = default;

StatieVremeEroareOperatii::StatieVremeEroareOperatii(const std::string &mesaj)
    : runtime_error(std::string("Eroare: operatie pe obiectul de tip StatieVreme nereusita! >> ") + mesaj) {}
StatieVremeEroareOperatii::~StatieVremeEroareOperatii() = default;
