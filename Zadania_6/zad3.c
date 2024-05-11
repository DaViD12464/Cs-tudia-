#include <stdio.h>

int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}

int main() {
    // Deklaracja wskaźnika do funkcji
    int (*wskaźnik_do_funkcji)(int, int);
    int wybor;

    printf("Wybierz operacje do wykonania:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnozenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &wybor);

    // Ustawienie wskaźnika do odpowiedniej funkcji
    switch (wybor) {
        case 1:
            wskaźnik_do_funkcji = &dodawanie;
            break;
        case 2:
            wskaźnik_do_funkcji = &mnozenie;
            break;
        case 3:
            wskaźnik_do_funkcji = &odejmowanie;
            break;
        default:
            printf("Niepoprawny wybor.\n");
            return 1;
    }

    int liczba1, liczba2;
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &liczba1, &liczba2);

    // Wywołanie odpowiedniej funkcji za pomocą wskaźnika
    printf("Wynik operacji: %d\n", (*wskaźnik_do_funkcji)(liczba1, liczba2));

    return 0;
}
