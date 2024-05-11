#include <stdio.h>

union Dane {
    int calkowita;
    float zmiennoprzecinkowa;
    char znak;
};

int main() {
    union Dane dane;

    // Przechowywanie i wyświetlanie wartości typu int
    dane.calkowita = 10;
    printf("Value type int: %d\n", dane.calkowita);

    // Przechowywanie i wyświetlanie wartości typu float
    dane.zmiennoprzecinkowa = 3.14;
    printf("Value type float: %f\n", dane.zmiennoprzecinkowa);

    // Przechowywanie i wyświetlanie wartości typu char
    dane.znak = 'A';
    printf("Value type char: %c\n", dane.znak);

    return 0;
}
