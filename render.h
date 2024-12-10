#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

// Estructura para un botón
typedef struct {
    SDL_Rect rect;         // Área del botón
    const char *label;     // Texto del botón
} Button;

// Declaraciones de funciones
void render_grid(SDL_Renderer *renderer, int screen_width, int screen_height, int tile_size);
void render_dwarf(SDL_Renderer *renderer, int x, int y, int tile_size);
void render_panel(SDL_Renderer *renderer, Button buttons[], int num_buttons);

#endif // RENDER_H
