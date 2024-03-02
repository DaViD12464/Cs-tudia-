
// zad 2

#include <stdio.h>

int main() {
    int grades[2][5];
    printf("Podaj oceny dla uczniów z matematyki i fizyki dla kazdego ucznia:\n");
    for (int i = 0; i <5;i++)
    {
        printf("Uczen %d:\n", i+1);
        printf("Matematyka: ");
        scanf("%d", &grades[0][i]);
        printf("Fizyka: ");
        scanf("%d", &grades[1][i]);
    }

    float avgMath = 0, avgPhysics =0;

    for (int i=0;i<5;i++)
    {
        avgMath += grades[0][i];
        avgPhysics += grades[1][i];
    }

    avgMath /= 5;
    avgPhysics /=5;

    printf("Srednia ocena z matematyki: %.2f\n", avgMath);
    printf("Srednia ocena z fizyki: %.2f\n", avgPhysics);

    return 0;
}



