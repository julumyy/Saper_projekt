#ifndef PLANSZA_H
#define PLANSZA_H

#include <vector>
#include "Pole.h"
#include <iostream>

using namespace std;

class Plansza {
private:
    int wysokosc, szerokosc;
    vector<vector<Pole>>siatka;

public:
    Plansza(int szer, int wys);
    void wyswietl() const;

};

#endif