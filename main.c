#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "render.h"
#include "input.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TILE_SIZE 32

int main(int argc, char *argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear ventana
    SDL_Window *window = SDL_CreateWindow("Motor Gráfico - Simulador de Colonias",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear renderizador
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error al crear el renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Variables principales
    int dwarf_x = 5, dwarf_y = 5;
    bool running = true;
    bool show_panel = false;
    bool selecting_task = false;

    // Definir botones del panel
    Button buttons[] = {
        {{110, 120, 180, 30}, "Talar"},
        {{110, 160, 180, 30}, "Picar"},
        {{110, 200, 180, 30}, "Cultivar"},
        {{110, 240, 180, 30}, "Recoger"}
    };
    int num_buttons = sizeof(buttons) / sizeof(buttons[0]);

    // Loop principal
    SDL_Event event;
    while (running) {
        // Manejo de entrada
        handle_input(&event, &running, &dwarf_x, &dwarf_y, &show_panel, &selecting_task, buttons, num_buttons);

        // Renderizado
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fondo negro
        SDL_RenderClear(renderer);

        render_grid(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE);
        render_dwarf(renderer, dwarf_x, dwarf_y, TILE_SIZE);

        if (show_panel) {
            render_panel(renderer, buttons, num_buttons);
        }

        SDL_RenderPresent(renderer);
    }

    // Limpiar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
