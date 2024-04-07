#include <stdio.h>
#include <stdlib.h>

void calculatePascalTriangle(int **triangle, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                triangle[i][j] = 1;
            else
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }}}

void displayPascalTriangle(int **triangle, int height) {
    int i, j;
    for (i = 0; i < height; i++)
    {for (j = 0; j < height - i - 1; j++)
        {printf(" ");}
        for (j = 0; j <= i; j++)
        {printf("%d ", triangle[i][j]);}
        printf("\n");
    }}

void freePascalTriangle(int **triangle, int height) {
    int i;
    for (i = 0; i < height; i++)
    {free(triangle[i]); }
    free(triangle);}

int main() {
    int height;
    printf("Input height of Pascal Triangle: ");
    scanf("%d", &height);

    int **triangle = (int **)malloc(height * sizeof(int *));
    if (triangle == NULL) {
        printf("Memory allocation error.\n");
        return 1;   }

    calculatePascalTriangle(triangle, height);
    displayPascalTriangle(triangle, height);
    freePascalTriangle(triangle, height);
    return 0;
}
