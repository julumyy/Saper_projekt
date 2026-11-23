# Diagram UML - Projekt Saper (C++)

Poniższy schemat przedstawia strukturę obiektową projektu, uwzględniając relacje dziedziczenia oraz najważniejsze pola i metody klas.

```text
+-------------------------------------------------------+
|                     Element_gry                       |
+-------------------------------------------------------+
| (klasa abstrakcyjna)                                  |
+-------------------------------------------------------+
| + virtual void wyswietl() const = 0                   |
| + virtual ~Element_gry()                              |
+-------------------------------------------------------+
                           ^
                           | (polimorfizm / dziedziczenie)
          +---------------------------------+
          |                                 |
+---------------------+           +---------------------+
|       Plansza       |           |      Czas_gry       |
+---------------------+           +---------------------+
| - wysokosc: int     |           | - czas_startu: time_t|
| - szerokosc: int    |           +---------------------+
| - liczba_min: int   |           | + wyswietl() const  |
| - siatka: vector    |           +---------------------+
| - czy_pierwszy_ruch |                   |
+---------------------+                   | (zawiera się w planszy/grze)
| + wyswietl() const  |                   v
| + losuj_miny()      |         +---------------------+
| + odkryj_pole()     |         |        Pole         |
| + operator[](int y) |         +---------------------+
| + operator<<        |         | - czy_mina: bool    |
+---------------------+         | - czy_odkryte: bool |
                                | - czy_flaga: bool   |
                                | - liczba_sasiadow   |
                                +---------------------+
                                | + operator<<        |
                                +---------------------+