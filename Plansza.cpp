#include "Plansza.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Plansza::Plansza(int szer, int wys, int miny) {
    szerokosc = szer;
    wysokosc = wys;
    liczba_min = miny;

    siatka.resize(wysokosc, vector<Pole>(szerokosc));

    srand(time(NULL));
    losuj_miny();
    oblicz_sasiadow();
}

void Plansza::losuj_miny() {
    int umieszczone_miny = 0;
    while(umieszczone_miny < liczba_min) {
        int x = rand() % szerokosc;
        int y = rand() % wysokosc;


        if (!siatka[y][x].get_czy_mina()) {
            siatka[y][x].set_czy_mina(true);
            umieszczone_miny++;
        }
    }
}


void Plansza::oblicz_sasiadow() {
    for (int y = 0; y < wysokosc; ++y) {
        for (int x = 0; x < szerokosc; ++x) {
            // Jeśli to pole samo jest miną, pomijamy
            if (siatka[y][x].get_czy_mina()) continue;
            
            int liczniki = 0;
            // Sprawdzamy sąsiadów w promieniu 1 pola (pętla 3x3)
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int ny = y + dy;
                    int nx = x + dx;
                    
                    // Sprawdzamy, czy sąsiad mieści się na planszy
                    if (ny >= 0 && ny < wysokosc && nx >= 0 && nx < szerokosc) {
                        if (siatka[ny][nx].get_czy_mina()) {
                            liczniki++;
                        }
                    }
                }
            }
            siatka[y][x].set_liczba_sasiadow(liczniki);
        }
    }
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

// debugowanie - pokazuje miny '*' i cyfry od razu
void Plansza::wyswietl_debug() const {
    cout << "\n--- PODGLAD DEBUG ---\n   ";
    for (int x = 0; x < szerokosc; ++x) {
        cout << x << " ";
    }
    cout << "\n   -----------\n";

    for (int y = 0; y < wysokosc; ++y) {
        cout << y << " | ";
        for (int x = 0; x < szerokosc; ++x) {
            if (siatka[y][x].get_czy_mina()) {
                cout << "* ";
            } else {
                cout << siatka[y][x].get_liczba_sasiadow() << " ";
            }
        }
        cout << "|\n";
    }
    cout << "   -----------\n";
}