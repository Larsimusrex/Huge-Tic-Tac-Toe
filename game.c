#include <stdio.h>

char get_field_cell(char* field, unsigned int size, unsigned int x, unsigned int y) {
    return *(field + x + y * size);
}

void print_game(char* field, unsigned int size, int current_player) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (x > 0) printf("|");
            printf("%c", get_field_cell(field, size, x, y));
        }
        printf("\n");

        if (y < size - 1) {
            printf("―");
            for (int i = 0; i < size - 1; i++) printf("+―");
        }

        printf("\n");
    }

    printf("Player ");
    printf((current_player) ? "o" : "x");
    printf(" is playing.\n");
}

void get_game_input(char* field, unsigned int size, unsigned int* x, unsigned int* y) {
    int x_input;
    int y_input;

    while(1) {
        printf("Input a coordinate (<x>,<y>): ");

        if (scanf("%d,%d", &x_input, &y_input) != 2) {
            printf("Invalied coordinate!\n");
        }
        else if (x_input < 0) {
            printf("The x-coordinate must be at least 0.\n");
        }
        else if (y_input < 0) {
            printf("The y-coordinate must be at least 0.\n");
        }
        else if (x_input >= size) {
            printf("The x-coordinate must be at most %d.\n", size - 1);
        }
        else if (y_input >= size) {
            printf("The y-coordinate must be at most %d.\n", size - 1);
        }
        else {
            *x = (unsigned int)x_input;
            *y = (unsigned int)y_input;

            return;
        }
    }
}