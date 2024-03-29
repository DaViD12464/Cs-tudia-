#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define HISTORY_SIZE 10

int main() {
    char choice[10];
    srand(time(NULL));
    char *bot;
    char user_history[HISTORY_SIZE][11] = {""};
    char bot_history[HISTORY_SIZE][11]  = {""};
    int user_wins = 0, bot_wins = 0, draws = 0;
    int history_index = 0;
//infinite loop so you can play multiple times
    while (1) {
        printf("\npapier, kamien, nozyce!\n");
        printf("Podaj swoj wybor (p/k/n) lub 'scores' aby sprawdzic wyniki: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

        //function to display 'scores' command - will give output out of last 10 games and what player&bot chosen
        if (strcmp(choice, "scores") == 0) {
            printf("Wyniki: Uzytkownik: %d, Komputer: %d, Remisy: %d\n", user_wins, bot_wins, draws);

            printf("Historia ruchow:\n");
            for (int i = 0; i < HISTORY_SIZE; i++) {
                printf("Runda %d: Uzytkownik - %s, Komputer - %s\n", i + 1, user_history[i], bot_history[i]);
            }
            continue;
        }
//this will add player choice to history
        strcpy(user_history[history_index], choice);
//function to pick bot choice (randomized)
        int random = rand() % 3;
        if (random == 0)
            bot = "p";
        else if (random == 1)
            bot = "k";
        else
            bot = "n";
//this will add bot choice to history
        strcpy(bot_history[history_index], bot);
        history_index = (history_index + 1) % HISTORY_SIZE;
//comparing the inputs to give output
        if (strcmp(choice, "p") == 0 && strcmp(bot, "k") == 0)
            user_wins++;
        else if (strcmp(choice, "k") == 0 && strcmp(bot, "n") == 0)
            user_wins++;
        else if (strcmp(choice, "n") == 0 && strcmp(bot, "p") == 0)
            user_wins++;
        else if (strcmp(choice, bot) == 0)
            draws++;
        else
            bot_wins++;
//printing the choices of player and bot
        printf("Wybrales: %s, Komputer wybral: %s\n", choice, bot);


    }

    return 0;
}
