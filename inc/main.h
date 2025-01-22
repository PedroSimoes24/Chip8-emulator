#ifndef MAIN_H
#define MAIN_H

#define DISPLAY_SCALE 20

int main();

int SDL2_init();

void chip8_init();

void render_screen();

void fetch_execute();

void update_timers(); 

#endif