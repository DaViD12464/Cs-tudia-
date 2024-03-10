// zad 1
//function will declare int value and later change it using pointers
#include <stdio.h>

int main() {
//declared int x
    int x = 1;
//created pointer to integer
    int *pX = &x;
//changed value of x using pointer
    *pX += 1;
    // printed by pointer & directly
    printf("Printed with pointer: %d\n", *pX);
    printf("Printed directly: %d\n", x);
    return 0;
}