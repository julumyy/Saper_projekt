#include <iostream>
#include "Plansza.h"

using namespace std;

int main() {
    cout << "Testowanie planszy Sapera:\n";
    
    //tworzenie planszy
    Plansza p(5, 5, 3);

    p.wyswietl();
    p.wyswietl_debug();

    return 0;
}