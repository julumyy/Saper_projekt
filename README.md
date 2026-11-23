# C++ Saper (Minesweeper)

Zaawansowany projekt gry Saper napisany w języku C++ z wykorzystaniem paradygmatu obiektowego (OOP). Projekt został stworzony z uwzględnieniem wymagań architektonicznych i dobrych praktyk programistycznych.

## Główne cechy projektu
* **Programowanie obiektowe (OOP):** Wykorzystanie klasy bazowej `Element_gry` oraz klas pochodnych `Plansza` i `Czas_gry`, z zastosowaniem metod wirtualnych (`virtual`) oraz specyfikatora `override`.
* **Przeciążanie operatorów:**
  * `operator<<` – intuicyjne wypisywanie stanu pól oraz całej planszy bezpośrednio do strumienia `std::cout`.
  * `operator[]` – bezpieczny, bezpośredni dostęp do wierszy siatki gry z poziomu kodu (np. `p[y][x]`), tutaj użyty jako podpowiedź, którą gracz może wybrać.
* **Obsługa wyjątków (`try-catch-throw`):** Ochrona przed błędami użytkownika, m.in. rzucanie wyjątku `std::out_of_range` przy próbie odczytu współrzędnych spoza zakresu planszy.
* **Bezpieczny start:** Pierwsze kliknięcie gracza gwarantuje bezpieczne odkrycie pola – miny losują się dopiero po wykonaniu pierwszego ruchu, omijając kliknięte pole oraz jego najbliższe otoczenie.
* **System podpowiedzi:** Dodatkowa opcja w menu pozwalająca na sprawdzenie liczby min w sąsiedztwie wskazanego pola z wykorzystaniem przeciążonego operatora indeksowania.

## Wymagania i kompilacja
Do skompilowania projektu potrzebny jest dowolny kompilator obsługujący standard C++11 lub nowszy (np. GCC / MinGW).

1. Sklonuj repozytorium lub pobierz pliki źródłowe.
2. Skompiluj projekt w terminalu (np. za pomocą polecenia):
   ```bash
   g++ main.cpp Plansza.cpp Pole.cpp -o output/saper.exe
3. Uruchom grę
   ./output/saper.exe