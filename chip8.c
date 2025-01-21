#include <stdio.h>   
#include <stdlib.h>
#include <stdint.h>

#include "utils/stack.h"
#include "utils/stack.c"

#define MEMORY_SIZE 4096


typedef struct Chip8 {

    uint8_t memory[MEMORY_SIZE];    //RAM
    Stack stack;                    //Stack

    uint8_t V[16];                  //V0-F
    uint16_t PC;                    //Program counter
    uint16_t I;                     //Index register
    uint8_t delay_reg;              //Delay register
    uint8_t sound_reg;              //Sound register

    int display[32][64];            //Display

} Chip8;

//Set memory to 0
void clearMem(Chip8 *chip8) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        chip8->memory[i] = 0;
    }
}

int main() {

    

    return 0;
}