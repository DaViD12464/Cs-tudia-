//zad 2
#include <stdio.h>
//function that will double the given number
void modifyFloat(float *x)
{
 *x *=2;
 printf("Value of number after getting modified: %.2f\n", *x);
}

int main()
{
    float x = 5;
    printf("Value of number before function: %.2f\n", x);
    modifyFloat(&x);

    return 0;
}