#ifndef POLE_H
#define POLE_H

class Pole {
private:
    bool czy_mina = false;
    bool czy_odkryte = false;
    bool czy_flaga = false;
    int liczba_sasiadow = 0;

public:
    Pole();

    bool get_czy_mina() const;
    bool get_czy_odkryte() const;
    bool get_czy_flaga() const;
    int get_liczba_sasiadow() const;
    //bool get_czy_flaga() const;


    void set_czy_mina(bool mina);
    void set_odkryte(bool odkrycie);
    void set_flaga(bool flaga);
    void set_liczba_sasiadow(int licznik);
};

#endif