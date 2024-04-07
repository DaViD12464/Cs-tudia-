#include <stdio.h>
//will read user input as number to check
int main()
{   int number=0, sum=0;
    printf("Podaj liczbe: \n");
    scanf("%d", &number);

    if (number<=0) //if number is >=0 it will display result as 0
    {
        printf("Suma wynosi: \n %d\t poniewaz liczba była ujemna, lub rowna zeru.", sum);
        return 0;
    }
//else if number is dividable by 3 or 5 (or 3&5) it will add it to sum (result)
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