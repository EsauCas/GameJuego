#include "render.h"

void render_grid(SDL_Renderer *renderer, int screen_width, int screen_height, int tile_size) {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gris para el grid
    for (int x = 0; x < screen_width; x += tile_size) {
        for (int y = 0; y < screen_height; y += tile_size) {
            SDL_Rect rect = {x, y, tile_size, tile_size};
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}

void render_dwarf(SDL_Renderer *renderer, int x, int y, int tile_size) {
    SDL_Rect dwarf_rect = {x * tile_size, y * tile_size, tile_size, tile_size};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Azul para el enano
    SDL_RenderFillRect(renderer, &dwarf_rect);
}

void render_panel(SDL_Renderer *renderer, Button buttons[], int num_buttons) {
    SDL_Rect panel = {100, 100, 200, 300};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Fondo gris oscuro
    SDL_RenderFillRect(renderer, &panel);

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Borde gris claro
    SDL_RenderDrawRect(renderer, &panel);

    // Dibujar cada botón
    for (int i = 0; i < num_buttons; i++) {
        SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255); // Azul
        SDL_RenderFillRect(renderer, &buttons[i].rect);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanco para borde
        SDL_RenderDrawRect(renderer, &buttons[i].rect);
    }
}
