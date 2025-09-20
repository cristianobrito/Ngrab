/*
#include <SDL3/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao iniciar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // SDL3: cria janela sem SDL_WINDOW_SHOWN
    SDL_Window* window = SDL_CreateWindow(
    "Meu Jogo SDL3",
    800, 600,
    SDL_WINDOW_RESIZABLE
);

    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Mantém a janela aberta por 3 segundos
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
*/


#include <SDL3/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <SDL3/SDL_ttf.h>
#include <SDL_ttf.h>

typedef struct {
    char label[64];
    float x, y, w, h;
} Botao;

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL_Init erro: %s\n", SDL_GetError());
        return 1;
    }

        SDL_Window* win = SDL_CreateWindow(
          "Meu Jogo SDL3",
         800, 600,
         SDL_WINDOW_RESIZABLE
        );

    if (!win) {
        fprintf(stderr, "CreateWindow erro: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *rnd = SDL_CreateRenderer(win, 0); // 0 = nenhuma flag especial
    if (!rnd) {
        fprintf(stderr, "CreateRenderer erro: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // carrega ui.txt
    FILE *f = fopen("ui.txt", "r");
    if (!f) {
        fprintf(stderr, "Nao achei ui.txt (coloque na pasta do exe)\n");
        SDL_DestroyRenderer(rnd);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    Botao botoes[128];
    int nb = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), f) && nb < 128) {
        char tipo[32], label[64];
        int x, y, w, h;
        if (sscanf(linha, "%31[^;];%63[^;];%d;%d;%d;%d", tipo, label, &x, &y, &w, &h) == 6) {
            if (strcmp(tipo, "botao") == 0) {
                strncpy(botoes[nb].label, label, sizeof(botoes[nb].label)-1);
                botoes[nb].x = x; botoes[nb].y = y; botoes[nb].w = w; botoes[nb].h = h;
                nb++;
            }
        }
    }
    fclose(f);

    int rodando = 1;
    SDL_Event ev;
    while (rodando) {
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_EVENT_QUIT) rodando = 0;
            else if (ev.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                int mx = ev.button.x;
                int my = ev.button.y;
                for (int i = 0; i < nb; ++i) {
                    if (mx >= botoes[i].x && mx <= botoes[i].x + botoes[i].w &&
                        my >= botoes[i].y && my <= botoes[i].y + botoes[i].h) {
                        printf("Clicou no botão: %s\n", botoes[i].label);
                        // aqui você pode disparar ações conforme label
                    }
                }
            }
        }

        // desenha fundo
        SDL_SetRenderDrawColor(rnd, 220, 220, 220, 255);
        SDL_RenderClear(rnd);

        // desenha botoes
        for (int i = 0; i < nb; ++i) {
            SDL_FRect r = { botoes[i].x, botoes[i].y, botoes[i].w, botoes[i].h };
            SDL_SetRenderDrawColor(rnd, 100, 140, 230, 255); // cor do botão
            SDL_RenderFillRect(rnd, &r);
            // borda
            SDL_SetRenderDrawColor(rnd, 30, 30, 30, 255);
            SDL_RenderRect(rnd, &r);
        }

        SDL_RenderPresent(rnd);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}


/*
#include <SDL3/SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char label[64];
    float x, y, w, h;
} Botao;

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL_Init erro: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() < 0) {
        fprintf(stderr, "TTF_Init erro: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow(
        "SDL3 Botões com Texto",
        100, 100,
        800, 600,
        SDL_WINDOW_RESIZABLE
    );

    if (!win) {
        fprintf(stderr, "CreateWindow erro: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *rnd = SDL_CreateRenderer(win, NULL);
    if (!rnd) {
        fprintf(stderr, "CreateRenderer erro: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Fonte TTF
    TTF_Font* fonte = TTF_OpenFont("arial.ttf", 20);
    if (!fonte) {
        fprintf(stderr, "Nao consegui abrir fonte: %s\n", TTF_GetError());
        SDL_DestroyRenderer(rnd);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Carrega ui.txt
    FILE *f = fopen("ui.txt", "r");
    if (!f) {
        fprintf(stderr, "Nao achei ui.txt\n");
        TTF_CloseFont(fonte);
        SDL_DestroyRenderer(rnd);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    Botao botoes[128];
    int nb = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), f) && nb < 128) {
        char tipo[32], label[64];
        float x, y, w, h;
        if (sscanf(linha, "%31[^;];%63[^;];%f;%f;%f;%f", tipo, label, &x, &y, &w, &h) == 6) {
            if (strcmp(tipo, "botao") == 0) {
                strncpy(botoes[nb].label, label, sizeof(botoes[nb].label)-1);
                botoes[nb].label[sizeof(botoes[nb].label)-1] = '\0';
                botoes[nb].x = x; botoes[nb].y = y; botoes[nb].w = w; botoes[nb].h = h;
                nb++;
            }
        }
    }
    fclose(f);

    int rodando = 1;
    SDL_Event ev;
    while (rodando) {
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_EVENT_QUIT) rodando = 0;
            else if (ev.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                float mx = ev.button.x;
                float my = ev.button.y;
                for (int i = 0; i < nb; ++i) {
                    if (mx >= botoes[i].x && mx <= botoes[i].x + botoes[i].w &&
                        my >= botoes[i].y && my <= botoes[i].y + botoes[i].h) {
                        printf("Clicou no botão: %s\n", botoes[i].label);
                    }
                }
            }
        }

        // Limpa fundo
        SDL_SetRenderDrawColor(rnd, 220, 220, 220, 255);
        SDL_RenderClear(rnd);

        // Desenha botoes
        for (int i = 0; i < nb; ++i) {
            SDL_FRect r = { botoes[i].x, botoes[i].y, botoes[i].w, botoes[i].h };
            SDL_SetRenderDrawColor(rnd, 100, 140, 230, 255);
            SDL_RenderFillRect(rnd, &r);

            // Borda
            SDL_SetRenderDrawColor(rnd, 30, 30, 30, 255);
            SDL_RenderRect(rnd, &r);

            // Texto
            SDL_Color corTexto = {255, 255, 255, 255};
            SDL_Surface* surfTexto = TTF_RenderText_Blended(fonte, botoes[i].label, corTexto);
            SDL_Texture* texTexto = SDL_CreateTextureFromSurface(rnd, surfTexto);
            int texW = 0, texH = 0;
            SDL_QueryTexture(texTexto, NULL, NULL, &texW, &texH);
            SDL_FRect dstRect = {
                botoes[i].x + (botoes[i].w - texW)/2,
                botoes[i].y + (botoes[i].h - texH)/2,
                texW,
                texH
            };
            SDL_RenderCopyF(rnd, texTexto, NULL, &dstRect);
            SDL_FreeSurface(surfTexto);
            SDL_DestroyTexture(texTexto);
        }

        SDL_RenderPresent(rnd);
        SDL_Delay(16);
    }

    TTF_CloseFont(fonte);
    TTF_Quit();
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
*/
