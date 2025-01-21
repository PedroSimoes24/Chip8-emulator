#include "chip8.h"
#include "main.h"

#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window *window;
SDL_Renderer *renderer;
Chip8 chip8_context;
Chip8 *chip8;

int main() {

    if (SDL2_init() == 1) {
        printf("Error in the SDL2 initialization");
        return 1;
    }

    chip8_init();

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

        for (int i = 0; i < DISPLAY_HEIGHT - 10; i++) {
            for (int j = 0; j < DISPLAY_WIDTH - 10; j++) {
                if (chip8->display[i][j] == 1) {
                    SDL_Rect square = {j * DISPLAY_SCALE, i * DISPLAY_SCALE, DISPLAY_SCALE, DISPLAY_SCALE};
                    SDL_RenderFillRect(renderer, &square);
                }
        }
    }

        // Mostrar o que foi renderizado
        SDL_RenderPresent(renderer);

    

        SDL_Delay(16); // Pequena pausa (~60 FPS)

        
    }

    // Limpar recursos
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void chip8_init() {

    chip8_context = {0};
    Chip8 *chip8 = &chip8_context;



    clear_display(chip8);
    clear_memory(chip8);
    load_fonts(chip8);


    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        for (int j = 0; j < DISPLAY_WIDTH; j++) {
            if (i + j % 2 == 0) chip8->display[i][j] = 1;
        }
    }
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
