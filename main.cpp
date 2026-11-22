#include <iostream>
#include "Plansza.h"

using namespace std;

int main() {
    cout << "Testowa plansza Sapera:\n";
    
    //tworzenie planszy
    Plansza p(5, 5, 3);
    bool gra_trwa = true;
    int akcja, x, y;

    cout << "=== SAPER ===\n";

    while(gra_trwa) {
        p.wyswietl();

        if(p.czy_wygrana()) {
            cout << "\nGRATULACJE, wygrales!\n";
            p.wyswietl_debug();
            break;
        }

        cout << "Wybierz akcje (1, 2 lub 3):\n";
        cout << "1. Odkryj pole\n";
        cout << "2. Postaw/usun flage (F)\n";
        cout << "3. Poddaj sie\n";
        cin >> akcja;

        if (akcja == 3) {
            cout << "\n Poddales sie. Odkryta plansza: ";
            p.wyswietl_debug();
            break;
        }


        cout << "\nPodaj wspolrzedne (x y): ";
        cin >> x >> y;
    
        
        if(akcja == 1) {
            gra_trwa = p.odkryj_pole(x, y);
            if(!gra_trwa) {
            cout <<"\n Trafiles na mine. Koniec gry.\n";
            p.wyswietl_debug();
            }
        } else if (akcja == 2) {
            p.oznacz_pole(x, y);
        } else {
            cout << "Niepoprawna akcja";
        }
        
    }


    return 0;
}