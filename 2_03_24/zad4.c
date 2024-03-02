#include <stdio.h>

int main() {
//this for will take numbers 1-200 and print Foo if number is able to be divided by 5, Bar if div. by 7
// and FooBar if it's able to divide number by 5 & 7 at same time, else it'll print number
    for (int i=1; i<=200; i++)
    {
        if (i%5==0)
            printf("Foo\n");
        else
        if (i%7==0)
            printf("Bar\n");
        else
        if (i%5 && i%7==0)
            printf("FooBar\n");
        else
            printf("%d\n",i);
            return 0;
    }
}