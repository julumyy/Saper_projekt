#include "Pole_h"

Pole::Pole() {
    czy_mina = false;
    czy_odkryte = false;
    czy_flaga = false;
    liczba_sasiadow = 0;
}

bool Pole::get_czy_mina() const { return czy_mina; }
bool Pole::get_czy_odkryte() const { return czy_odkryte; }
bool Pole::get_czy_flaga() const { return czy_flaga; }
int Pole::get_liczba_sasiadow() const { return liczba_sasiadow; }


void Pole::set_czy_Mina(bool mina) { czy_mina = mina; }
void Pole::set_odkrycie(bool odkrycie) { czy_odkrycie = odkrycie; }
void Pole::set_flaga(bool flaga) { czy_flaga = flaga; }
void Pole::set_liczba_sasiadow(int licznik) { licznik_sasiadow = licznik; }

