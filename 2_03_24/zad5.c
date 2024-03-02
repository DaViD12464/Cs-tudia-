#include <stdio.h>

int main()
{   int number=0, sum=0;
    printf("Podaj liczbe: \n");
    scanf("%d", &number);

    if (number<=0)
    {
        printf("Suma wynosi: \n %d\t poniewaz liczba była ujemna, lub rowna zeru.", sum);
        return 0;
    }

    for (int i=1; i < number; i++)
    {
        if(i%3==0 || i%5==0)
        {
            sum += i;
        }
    }
    printf("Suma wynosi:\t %d", sum);
    return 0;
}