#include <stdio.h>

int calculatePascal(int row, int col)
{
    if (col ==0 || col ==row)
        return 1;
    else
        return calculatePascal(row-1,col-1) + calculatePascal(row-1,col);
}


void displayPT(int height)
{ int i,j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < height - i - 1; j++)
        {printf(" ");}
        for (j = 0; j <= i; j++)
        {printf("%d ", calculatePascal(i, j));}
        printf("\n");
    }
}

int main(){
    int x =0;
    printf("How high you want the Pascal's triangle to be?\n");
    scanf_s("%d", &x);

    displayPT(x);
    return 0;
}