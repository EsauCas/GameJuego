#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "render.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TILE_SIZE 32

void handle_input(SDL_Event *event, bool *running, int *dwarf_x, int *dwarf_y, bool *show_panel, bool *selecting_task, Button buttons[], int num_buttons);

#endif // INPUT_H
