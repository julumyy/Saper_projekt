#include "Plansza.h"
#include <iostream>

using namespace std;

Plansza::Plansza(int szer, int wys) {
    szerokosc = szer;
    wysokosc = wys;

    siatka.resize(wysokosc, vector<Pole>(szerokosc));
}

void Plansza::wyswietl() const {
    cout << "\n    ";
    for (int x = 0; x < szerokosc; ++x) {
        cout << x << " ";
    }

    cout << "\n   -----------\n";

    for (int y = 0; y < wysokosc; ++y) {
        cout << y << " | ";
        
        for (int x = 0; x < szerokosc; ++x) {
            //
            if (siatka[y][x].get_czy_odkryte()) {
                cout << siatka[y][x].get_liczba_sasiadow() << " ";
            } else {
                cout << ". ";
            }

        }
        cout << "|\n";
    }
    cout << "   -----------\n";
}