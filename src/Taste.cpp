
#include "../include/Taste.h"

Taste::Taste(string gL, string a, string zS, int anmin, int anmax, int lmin, int lmax) : genLit(gL), autor(a), zodiacSign(zS), anMin(anmin), anMax(anmax), lenMin(lmin), lenMax(lmax) {}

auto Taste::getautor() const { return autor; }

string Taste::getgenLit() const { return genLit; }

string Taste::getzodiacSign() const {return zodiacSign;}

int Taste::getlenMin() const {return lenMin;}

int Taste::getlenMax() const { return lenMax; }

int Taste::getanMax() const { return anMax; }

int Taste::getanMin() const { return anMin; }

std::ostream &operator<<(std::ostream &os, const Taste &t) {
    os << t.genLit << " " << t.zodiacSign<< std::endl;
    //INTREBARE: cum pot afisa ceva care e optional cum e aici "autor"????? vezi has_value()
    return os;
}



