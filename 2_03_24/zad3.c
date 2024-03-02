#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < 10; i++) {
        int n = array[i];
        float outcome = 1;

        for (int j = 1; j <= n; j++) {
            outcome *= (float)j;
        }

        printf("Wynik dla n: %d: \n %.2f\n", array[i], outcome);
    }

    return 0;
}
