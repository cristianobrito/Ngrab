#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;

    if (TTF_Init() != 0) {
        printf("Erro TTF: %s\n", TTF_GetError());
        return 1;
    }

    printf("SDL_ttf inicializado com sucesso!\n");

    TTF_Quit();
    SDL_Quit();
    return 0;
}
