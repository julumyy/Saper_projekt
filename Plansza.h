#ifndef PLANSZA_H
#define PLANSZA_H

#include <vector>
#include "Pole.h"
#include <iostream>

using namespace std;

class Plansza {
private:
    int wysokosc, szerokosc;
    int liczba_min;
    vector<vector<Pole>>siatka;

public:
    Plansza(int szer, int wys, int miny);
    //void wyswietl() const;
    void losuj_miny();
    void oblicz_sasiadow();
    void wyswietl_debug() const;
    bool odkryj_pole(int x, int y);
    void oznacz_pole(int x, int y);
    bool czy_wygrana() const;

    int get_szerokosc() const { return szerokosc; }
    int get_wysokosc() const { return wysokosc; }


    friend ostream& operator<<(ostream& os, const Plansza& plansza);
};

#endif