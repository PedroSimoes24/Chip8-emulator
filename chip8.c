#include <stdio.h>   
#include <stdlib.h>
#include <stdint.h>


#include "chip8.h"
#include "stack.h"
#include "stack.c"


void clear_memory(Chip8 *chip8) {

    for (int i = 0; i < MEMORY_SIZE; i++) {
        chip8->memory[i] = 0;
    }
}

void clear_display(Chip8 *chip8) {

    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        for (int j = 0; j < DISPLAY_WIDTH; j++) {
            chip8->display[i][j] = 0;
        }
    }
}

void load_fonts(Chip8 *chip8) {

    for (int i = 0; i < FONT_SIZE; i++) {
        chip8->memory[FONT_START_ADDRESS + i] = DEFAULT_FONT[i];
    }
}
