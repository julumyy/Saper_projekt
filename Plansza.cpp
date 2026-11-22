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
            // pomin jesli mina
            if (siatka[y][x].get_czy_mina()) continue;
            
            int liczniki = 0;
            // sprawdza sasiadow
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


ostream& operator<<(ostream& os, const Plansza& plansza) { //"." dla zakrytych, 'F' dla oznaczonych flag
    os << "\n    ";
    for (int x = 0; x < plansza.get_szerokosc(); ++x) {
        os << x << " ";
    }

    os << "\n    ";
    for(int x = 0; x < plansza.get_szerokosc(); ++x) {
        os << "--";
    }
    os << "-\n";
    
    //cout << "\n   -----------\n";

    for (int y = 0; y < plansza.get_wysokosc(); ++y) {
        os << y << " | ";
        
        for (int x = 0; x < plansza.get_szerokosc(); ++x) {
            //
            if (!plansza.siatka[y][x].get_czy_odkryte()) {
                if (plansza.siatka[y][x].get_czy_odkryte()) {
                    os << "F ";
                } else {
                    os << ". ";
                }

            } else if (plansza.siatka[y][x].get_czy_mina()) {
                os << "* ";
            } else {
                int sasiedzi = plansza.siatka[y][x].get_liczba_sasiadow();
                if (sasiedzi == 0) {
                    os << "0 ";
                } else {
                    os << sasiedzi << " ";
                }
            }
        }
        os << "|\n";
    }
    
    os << "   ";
    for(int x = 0; x < plansza.get_szerokosc(); ++x) {
        os << "--";
    }
    os << "-\n";
    return os;
    //os << "   -----------\n";
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

void Plansza::oznacz_pole(int x, int y) {
    
    if(x < 0 || x >= szerokosc || y < 0 || y >= wysokosc) {
        cout << "Niepoprawne wspolrzedne\n";
        return ;
    }

    if(siatka[y][x].get_czy_odkryte()) {
        cout << "Nie mozna oznaczyc juz odkrytego pola\n";
        return ;
    }

    bool obecny_stan = siatka[y][x].get_czy_flaga();
    siatka[y][x].set_flaga(!obecny_stan);
}

bool Plansza::odkryj_pole(int x, int y) {

    Pole domyslne;
    if(siatka[y][x] == domyslne) {}

    if (x < 0 || x >= szerokosc || y < 0 || y >= wysokosc) {
        throw out_of_range("Niepoprawne wspolrzedne");
    }

    if (siatka[y][x].get_czy_odkryte() || siatka[y][x].get_czy_flaga()) {
        return true;
    }


    siatka[y][x].set_odkryte(true);
    
    // odkryta mina = przegrana
    if (siatka[y][x].get_czy_mina()) {
        return false; 
    }

    //jesli odkryte 0, to odkrywa sasiadow
    if(siatka[y][x].get_liczba_sasiadow() == 0) {
        for(int dy = -1; dy <= 1; ++dy) {
            for(int dx = -1; dx <= 1; ++dx) {
                if(dy != 0 || dx != 0) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx >= 0 && nx < szerokosc && ny >= 0 && ny < wysokosc) {
                        odkryj_pole(nx, ny);
                    }
                    
                }
            }
        }
    }
    
    return true;
}

bool Plansza::czy_wygrana() const {
    for(int y = 0; y < wysokosc; ++y) {
        for(int x = 0; x < szerokosc; ++x) {
            if(!siatka[y][x].get_czy_mina() && !siatka[y][x].get_czy_odkryte()) {
                return false;
            }
        }
    }
    return true;
}
