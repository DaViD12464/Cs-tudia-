#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocateMatrixMemory(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Rows memory allocation error.\n");
        exit(1);
    }

    for(int i=0; i<rows;i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Columns memory allocation error.\n");
            exit(1);
        }
    }
    return matrix;
}

void fillRandFillMatrix(int **matrix, int rows, int cols)
{
    srand(time(NULL));
    for (int i=0; i<rows;i++)    {
        for (int j=0; j<cols;j++)   {
            matrix[i][j] = rand() % 100;
        }}}
void displayMatrix(int **matrix, int rows, int cols)
{
    printf("Printing matrix:\n");
    for (int i=0; i<rows;i++)    {
        for (int j=0; j<cols;j++)   {
            printf(" %d ", matrix[i][j]);
        }
            printf("\n");   }}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);    }
    free(matrix);   }

int main() {
    int rows, cols;

    printf("Number of matrix rows: ");
    scanf("%d", &rows);
    printf("Number of matrix columns: ");
    scanf("%d", &cols);

    int **matrix = allocateMatrixMemory(rows, cols);
    fillRandFillMatrix(matrix, rows, cols);
    displayMatrix(matrix, rows, cols);
    freeMatrix(matrix, rows);
    return 0;
}