#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "game.h"

int main() {

    //set game size and allocate memory
    int size_input;
    unsigned int size;
    printf("Input game size: ");
    if (scanf("%d", &size_input) != 1) {
        printf("Invalied game size!\n");

        return 1;
    }

    if (size_input <= 0) {
        printf("Game size must be at least 1!\n");

        return 1;
    }

    size = (unsigned int)size_input; //size_input will be posetive

    char* field = (char*) malloc(sizeof(char) * size * size);

    if (field == NULL) {
        printf("Could not allocate Memory! Try a smaller game size.\n");

        return 1;
    }

    memset(field, '.', sizeof(char) * size * size);

    //mainloop
    int is_finished = 1;
    int current_player = 0;
    int* x_input;
    int* y_input;

    print_game(field, size, current_player);
    get_game_input(field, size, x_input, y_input);

    printf("x: %d, y: %d\n", *x_input, *y_input);

    // while (!is_finished) {
    //     print_game(field, size);
    //     get_game_input(field, size, x_input, y_input);
    //     process_game(field, size, &x_input, &y_input, current_player);
    //     is_finished = is_game_won(field, size);
    // }

    //print game result


    free(field);
    return 0;
}