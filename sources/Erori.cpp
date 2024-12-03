//
// Created by Munty on 03/12/2024.
//

#include "../headers/Erori.h"

VremeInvalida::VremeInvalida(const std::string &mesaj) : runtime_error(
    "Eroare: date invalide pentru Vreme! >> " + mesaj) {
}

VremeEroareClonare::VremeEroareClonare(const std::string &mesaj) : runtime_error(
    "Eroare: clonare nereusita pentru Vreme! >> " + mesaj) {
}

StatieVremeEroareOperatii::StatieVremeEroareOperatii(const std::string &mesaj) : runtime_error(
    "Eroare: operatie pe obiectul de tip StatieVreme nereusita! >> " + mesaj) {
}
