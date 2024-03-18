#include <stdio.h>

unsigned long long factorial(int x){
    if(x==0){
        return 1;
    }
    else
        return x * factorial(x-1);
}

int main(){
    int number;
    printf("Type in number to calculate factorial:\n");
    scanf("%d", &number);
    if (number < 0) {
        printf("Cannot calculate factorial for negative number.\n");
    } else {
        unsigned long long result = factorial(number);
        printf("Factorial of: %d is: %llu.\n", number, result);
    }
    return 0;
}