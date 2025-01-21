#include "chip8.h"
#include "chip8.c"

#include <stdlib.h>
#include <stdint.h>


int main() {

    Chip8 *chip8;
    clear_memory(chip8);
    clear_display(chip8);
    load_fonts(chip8);

    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        for (int j = 0; j < DISPLAY_WIDTH; j++) {
            if (chip8->display[i][j] == 0) printf(".");
            else if (chip8->display[i][j] == 1) printf("X");
            else printf("?");
        }

        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}