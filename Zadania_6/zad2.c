#include <stdio.h>

int main() {
    int tablica[10]; // Deklaracja tablicy
    int *wskaznik;   // Deklaracja wskaźnika

    // Inicjalizacja tablicy i wyświetlenie jej zawartości (wskaźnik i arytmetyka wskaźników)
    for (int i = 0; i < 10; i++) {
        tablica[i] = i; // Inicjalizacja wartości tablicy
    }

    wskaznik = tablica; // Przypisanie adresu początkowego tablicy do wskaźnika

    // Wyświetlanie zawartości tablicy za pomocą wskaźnika i arytmetyki wskaźników
    for (int i = 0; i < 10; i++) {
        printf("Value #%d: %d\n", i, *wskaznik); // Wyświetlanie aktualnego elementu
        wskaznik++; // Przesunięcie wskaźnika na następny element
    }

    return 0;
}
