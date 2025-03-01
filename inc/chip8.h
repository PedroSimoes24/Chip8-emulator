#ifndef CHIP_8_H
#define CHIP_8_H

#include <stdlib.h>
#include <stdint.h>

#include "stack.h"


#define MEMORY_SIZE 4096

#define FONT_SIZE 80
#define FONT_START_ADDRESS 0x050

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32

typedef struct Chip8 {

    uint8_t memory[MEMORY_SIZE];                          //RAM
    Stack stack;                                          //Stack

    uint8_t V[16];                                        //V0-F
    uint16_t PC;                                          //Program counter
    uint16_t I;                                           //Index register
    uint8_t delay_reg;                                    //Delay register
    uint8_t sound_reg;                                    //Sound register

    uint8_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH];    //Display

} Chip8;


static const uint8_t DEFAULT_FONT[FONT_SIZE] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,   // 0
    0x20, 0x60, 0x20, 0x20, 0x70,   // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,   // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,   // 6
    0xF0, 0x10, 0x20, 0x40, 0x40,   // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,   // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,   // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90,   // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,   // B
    0xF0, 0x80, 0x80, 0x80, 0xF0,   // C
    0xE0, 0x90, 0x90, 0x90, 0xE0,   // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,   // E
    0xF0, 0x80, 0xF0, 0x80, 0x80    // F
};


void clear_memory(Chip8 *chip8);

void clear_display(Chip8 *chip8);

void load_fonts(Chip8 *chip8);

//exprimental
int invert_pixels(Chip8 *chip8, int counter);


#endif