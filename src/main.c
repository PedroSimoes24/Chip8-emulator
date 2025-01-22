#include "chip8.h"
#include "main.h"

#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window *window;
SDL_Renderer *renderer;
Chip8 *chip8;

int main() {

    if (SDL2_init() == 1) {
        printf("Error in the SDL2 initialization");
        return 1;
    }

    chip8 = (Chip8*)calloc(1, sizeof(Chip8));
    chip8_init(chip8);

    if (chip8 == NULL) {
        perror("Error allocating memory for chip8");
        return 1;
    }

    // Loop principal
    int running = 1;
    SDL_Event event;

    while (running) {
        // Processar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0; // Sair do loop
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Definir a cor do quadrado (branco)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Definir as dimensões do quadrado

        for (int i = 0; i < DISPLAY_HEIGHT; i++) {
            for (int j = 0; j < DISPLAY_WIDTH; j++) {
                if (chip8->display[i][j] == 1) {
                    SDL_Rect square = {i * DISPLAY_SCALE, j * DISPLAY_SCALE, DISPLAY_SCALE, DISPLAY_SCALE};

                    SDL_RenderFillRect(renderer, &square);
                }
            }
        }

        invert_pixels(chip8);
        printf("a\n");

        // Mostrar o que foi renderizado
        SDL_RenderPresent(renderer);

        chip8->delay_reg = chip8->delay_reg == 0 ? 0 : chip8->delay_reg - 1;
        chip8->sound_reg = chip8->sound_reg == 0 ? 0 : chip8->sound_reg - 1;
        SDL_Delay(16); // Pequena pausa (~60 FPS) 16

        
    }

    // Limpar recursos
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(chip8);

    return 0;
}


int SDL2_init() {

    //Start SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    //Create window
    window = SDL_CreateWindow(
        "Exemplo SDL - Fechar Janela",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        DISPLAY_WIDTH * DISPLAY_SCALE,
        DISPLAY_HEIGHT * DISPLAY_SCALE,
        SDL_WINDOW_SHOWN
    );

    //Error while creating window
    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erro ao criar renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    return 0;

}
