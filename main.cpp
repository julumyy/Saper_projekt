#include <iostream>
#include "Plansza.h"

using namespace std;

int main() {
    // cout << "Testowa plansza Sapera:\n";
    
    //wybor poziomu trudnosci
    int wybor;
    cout << "Wybierz poziom trudnosci:\n";
    cout << "1. Latwy (5x5, 3 miny)\n";
    cout << "2. Sredni (8x8, 10 min)\n";
    cout << "3. Trudny (10x10, 20 min)\n";
    cin >> wybor;

    //tworzenie planszy
    int szer = 5, wys = 5, miny = 3;
    if (wybor == 2) {
        szer = 8; wys = 8; miny = 10; 
    } else if (wybor == 3) {
        szer = 10; wys = 10; miny = 20;
    }
    
    
    Plansza p(szer, wys, miny);
    bool gra_trwa = true;
    int akcja, x, y;
    Czas_gry czas;


    cout << "=== SAPER ===\n";

    while(gra_trwa) {
        
        czas.wyswietl();

        int pozostale_miny = p.get_liczba_min() - p.get_liczba_postawionych_flag();
        cout << "Pozostale miny: " << pozostale_miny << " / " << p.get_liczba_min() << "\n";

        cout << p; //p.wyswietl();

        if(p.czy_wygrana()) {
            cout << "\nGRATULACJE, wygrales!\n";
            czas.wyswietl();
            p.wyswietl_debug();
            break;
        }

        cout << "Wybierz akcje (1, 2 lub 3):\n";
        cout << "1. Odkryj pole\n";
        cout << "2. Postaw/usun flage (F)\n";
        cout << "3. Poddaj sie\n";
        cout << "4. Podpowiedz - sprawdz liczbe min wokol pola (x, y)\n";
        cin >> akcja;

        if (akcja == 3) {
            cout << "\n Poddales sie. Odkryta plansza: \n";
            czas.wyswietl();
            p.wyswietl_debug();
            break;
        } else if (akcja == 4) {
            cout << "Podaj wspolrzedne x i y do sprawdzenia: ";
            cin >> x >> y;
            try {
                // operator []
                int sasiadom = p[y][x].get_liczba_sasiadow();
                bool czy_mina = p[y][x].get_czy_mina();
        
                cout << "\n[PODPOWIEDZ] Pole (" << x << ", " << y << "): ";
                if (czy_mina) {
                    cout << "To pole ukrywa MINE! (Uwaga!)\n";
                } else {
                    cout << "Liczba min w sasiedztwie: " << sasiadom << "\n";
                }
            } catch (...) {
                cout << "Blad: Podano wspolrzedne poza zakresem planszy!\n";
            }
        }


        cout << "\nPodaj wspolrzedne (x y): ";
        cin >> x >> y;
    
        try {
            if(akcja == 1) {
                cout << "Podaj wspolrzedne (x y): ";
                cin >> x >> y;

                gra_trwa = p.odkryj_pole(x, y);
                if(!gra_trwa) {
                    cout <<"\n Trafiles na mine. Koniec gry.\n";
                    czas.wyswietl();
                    p.wyswietl_debug();
                }
            } else if (akcja == 2) {
                p.oznacz_pole(x, y);
            }
            
        }
        catch (const out_of_range& e) {
            cout << "Blad wyjatku: " << e.what() << "\n";
        }
        
    }


    return 0;
}