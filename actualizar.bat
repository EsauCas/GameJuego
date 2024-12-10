@echo off
gcc main.c render.c input.c -o motor_grafico.exe -I SDL2/include -L SDL2/lib -lmingw32 -lSDL2main -lSDL2
pause
