// zad 1
//function will welcome you after you type in your name
#include <stdio.h>
int main() {
char name[20];
printf("Podaj swoje imie: ");
scanf("%s", name);

printf("Witaj %s", name);

return 0;
}
