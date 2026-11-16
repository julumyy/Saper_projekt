#include <iostream>
#include "Plansza.h"

using namespace std;

int main() {
    cout << "Testowanie planszy Sapera:\n";
    
    // Tworzymy planszę 5x5
    Plansza p(5, 5);
    p.wyswietl();

    return 0;
}