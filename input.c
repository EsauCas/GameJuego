#include "input.h"
#include <stdio.h> // Para usar printf

void handle_input(SDL_Event *event, bool *running, int *dwarf_x, int *dwarf_y, bool *show_panel, bool *selecting_task, Button buttons[], int num_buttons) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            *running = false; // Cerrar el juego
        } else if (event->type == SDL_KEYDOWN) {
            // Mover el enano con las teclas de flecha
            switch (event->key.keysym.sym) {
                case SDLK_UP:    (*dwarf_y)--; break;
                case SDLK_DOWN:  (*dwarf_y)++; break;
                case SDLK_LEFT:  (*dwarf_x)--; break;
                case SDLK_RIGHT: (*dwarf_x)++; break;
            }
        } else if (event->type == SDL_MOUSEBUTTONDOWN) {
            if (event->button.button == SDL_BUTTON_RIGHT) {
                // Detectar clic derecho sobre el enano
                int click_x = event->button.x / TILE_SIZE;
                int click_y = event->button.y / TILE_SIZE;

                if (click_x == *dwarf_x && click_y == *dwarf_y) {
                    *show_panel = true; // Abrir el panel de tareas
                    printf("Panel abierto para el enano en (%d, %d)\n", *dwarf_x, *dwarf_y);
                }
            } else if (event->button.button == SDL_BUTTON_LEFT) {
                // Detectar clic izquierdo
                int click_x = event->button.x;
                int click_y = event->button.y;

                if (*show_panel) {
                    // Clic dentro del panel, detectar botón presionado
                    for (int i = 0; i < num_buttons; i++) {
                        if (click_x >= buttons[i].rect.x && click_x <= buttons[i].rect.x + buttons[i].rect.w &&
                            click_y >= buttons[i].rect.y && click_y <= buttons[i].rect.y + buttons[i].rect.h) {
                            printf("Botón seleccionado: %s\n", buttons[i].label);
                            *show_panel = false; // Cerrar el panel
                            *selecting_task = true; // Activar selección de casilla
                            break;
                        }
                    }
                } else if (*selecting_task) {
                    // Selección de casilla para realizar la tarea
                    int task_x = event->button.x / TILE_SIZE;
                    int task_y = event->button.y / TILE_SIZE;

                    printf("Tarea asignada a la casilla (%d, %d)\n", task_x, task_y);
                    *selecting_task = false; // Salir del modo de selección
                }
            }
        }

        // Limitar al enano dentro del grid
        if (*dwarf_x < 0) *dwarf_x = 0;
        if (*dwarf_y < 0) *dwarf_y = 0;
        if (*dwarf_x >= SCREEN_WIDTH / TILE_SIZE) *dwarf_x = (SCREEN_WIDTH / TILE_SIZE) - 1;
        if (*dwarf_y >= SCREEN_HEIGHT / TILE_SIZE) *dwarf_y = (SCREEN_HEIGHT / TILE_SIZE) - 1;
    }
}
