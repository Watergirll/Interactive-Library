#ifndef OOP_TASTE_H
#define OOP_TASTE_H

#include <iostream>
#include <vector>
#include <optional>
using std::string;

class Taste {
private:
    string genLit;
    std::optional <string> autor;
    string zodiacSign;
    int anMax;
    int anMin;
    int lenMin;
    int lenMax;
public:
    //Constructor
    Taste (string gL, string a, string zS, int anmin, int anmax, int lmin, int lmax);

    //getters
    auto getautor() const;
    [[nodiscard]] string getgenLit() const;
    string getzodiacSign() const;
    int getlenMin() const;
    int getlenMax() const;
    int getanMax() const;
    int getanMin() const;

    //output of Taste data
    friend std::ostream& operator<<(std::ostream& os, const Taste& t);
};

#endif //OOP_TASTE_H
