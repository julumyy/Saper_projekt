#ifndef PLANSZA_H
#define PLANSZA_H

#include <vector>
#include "Pole.h"
#include <iostream>
#pragma once
#include <ctime>

using namespace std;

class Element_gry {
public:
    virtual void wyswietl() const = 0; 
    virtual ~Element_gry() {} //destruktor
};


class Plansza : public Element_gry {
private:
    int wysokosc, szerokosc;
    int liczba_min;
    bool czy_pierwszy_ruch = true;
    vector<vector<Pole>> siatka;

public:
    Plansza(int szer, int wys, int miny);
    void wyswietl() const override;
    void losuj_miny();
    void oblicz_sasiadow();
    void wyswietl_debug() const;
    bool odkryj_pole(int x, int y);
    void oznacz_pole(int x, int y);
    bool czy_wygrana() const;

    int get_szerokosc() const { return szerokosc; }
    int get_wysokosc() const { return wysokosc; }

    int get_liczba_min() const { return liczba_min; }
    int get_liczba_postawionych_flag() const;

    void losuj_miny_z_wyjatkiem(int bezpieczny_x, int bezpieczny_y);

    friend ostream& operator<<(ostream& os, const Plansza& plansza);

    vector<Pole>& operator[](int y);
    const vector<Pole>& operator[](int y) const;
};

class Czas_gry : public Element_gry {
private:
    time_t czas_startu;
public:
    Czas_gry() {
        czas_startu = time(nullptr);
    }

    void wyswietl() const override {
        time_t teraz = time(nullptr);
        long minuty = (teraz - czas_startu) / 60;
        long sekundy = (teraz - czas_startu) % 60;
        cout << "Czas gry: " << minuty << "m " << sekundy << "s " << endl;
    }
};


#endif