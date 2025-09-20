/*
#include "carinha.h"

 int main() {
   animFace();
   return 0;
 }
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 50
#define MAX_COLUNAS 50

int main() {
    FILE *fp;
    char mapa[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0;

    fp = fopen("mapa.txt", "r");
    if (!fp) {
        printf("Erro ao abrir mapa.txt\n");
        return 1;
    }

    while (fgets(mapa[linhas], MAX_COLUNAS, fp)) {
        // remove o '\n' do final
        mapa[linhas][strcspn(mapa[linhas], "\n")] = '\0';
        linhas++;
    }
    fclose(fp);

    // Mostra o mapa na tela
    printf("Mapa carregado:\n");
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }

    return 0;
}
*/

// =====================================================
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 50
#define MAX_COLUNAS 50

int main() {
    FILE *fp;
    char mapa[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0;

    fp = fopen("mapa.txt", "r");
    if (!fp) {
        printf("Erro ao abrir mapa.txt\n");
        return 1;
    }

    while (fgets(mapa[linhas], MAX_COLUNAS, fp)) {
        mapa[linhas][strcspn(mapa[linhas], "\n")] = '\0'; // remove \n
        linhas++;
    }
    fclose(fp);

    printf("Mapa visual:\n\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < strlen(mapa[i]); j++) {
            switch (mapa[i][j]) {
                case '#': printf("█"); break;   // parede
                case '.': printf("·"); break;   // espaço/comida
                case 'P': printf("☺"); break;   // player
                default:  printf(" "); break;   // vazio
            }
        }
        printf("\n");
    }

    return 0;
}
*/

// =======================================================================
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 50
#define MAX_COLUNAS 50

int main() {
    FILE *fp;
    char mapa[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0;

    // Abre o arquivo de mapa
    fp = fopen("mapa.txt", "r");
    if (!fp) {
        printf("Erro ao abrir mapa.txt\n");
        return 1;
    }

    // Lê linha por linha
    while (fgets(mapa[linhas], MAX_COLUNAS, fp)) {
        mapa[linhas][strcspn(mapa[linhas], "\n")] = '\0'; // remove \n
        linhas++;
    }
    fclose(fp);

    // Mostra o mapa interpretado
    printf("Mapa visual:\n\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < strlen(mapa[i]); j++) {
            //switch (mapa[i][j]) {
                //case '#': printf("#"); break;   // parede
                //case '.': printf("."); break;   // comida
               // case 'P': printf("P"); break;   // player
              //  default:  printf(" "); break;   // vazio
            //}
            //switch (mapa[i][j]) {
              //case '#': printf("%c", 176); break;   // █ (parede, CP437)
              //case '.': printf("%c", 250); break;   // · (ponto do Pac-Man)
              //case 'P': printf("%c", 248);   break;   // ☺ (player)
              //default:  printf(" "); break;
            //}

           switch (mapa[i][j]) {
                case 'A': printf("%c", 218); break; // ┌
                case 'B': printf("%c", 191); break; // ┐
                case 'C': printf("%c", 192); break; // └
                case 'D': printf("%c", 217); break; // ┘
                case 'H': printf("%c", 196); break; // ─
                case 'V': printf("%c", 179); break; // │
                case '.': printf("%c", 250); break; // · comida
                case 'P': printf("%c", 248);   break; // ☺ player
                default: printf(" "); break;   // espaço vazio
          }
        }
        printf("\n");
    }

    return 0;
}
*/

//=======================================================================
/*
#include <stdio.h>
 #include <stdlib.h>
 // ==================== MATRIZES DE LETRAS (BITMAP) ====================
 unsigned char A[5] = {
 0b00100,
 0b01010,
 0b11111,
 0b10001,
 0b10001
 };
 unsigned char B[5] = {
 0b11110,
 0b10001,
 0b11110,
 0b10001,
 0b11110
 };
 // ==================== FUNÇÃO PARA GERAR SVG ====================
 void generateSVG(const char *filename, unsigned char *bitmap, int rows, int cols) {
 FILE *f = fopen(filename, "w");
 if (!f) {
 perror("Erro ao criar arquivo SVG");

return;
 }
 fprintf(f, "<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>\n", cols*20,rows*20);
 fprintf(f, "<rect width='100%%' height='100%%' fill='white'/>\n"); // fundo branco
 for(int y = 0; y < rows; y++) {
 for(int x = 0; x < cols; x++) {
 if(bitmap[y] & (1 << (cols-1-x))) { // pixel ligado
 fprintf(f, "<rect x='%d' y='%d' width='20' height='20' fill='black'/>\n", x*20, y*20);
 }
 }
 }
 fprintf(f, "</svg>\n");
 fclose(f);
 }
 // ==================== FUNÇÃO PRINCIPAL ====================
 int main() {
 generateSVG("A.svg", A, 5, 5);
 generateSVG("B.svg", B, 5, 5);
 printf("SVGs gerados! Agora você pode importar no FontForge e criar uma fonte TTF.\n");
 return 0;
 }
*/

//=================================================================================
// main.c
#include "glyph.h"

int main() {
    render_glyph_svg(A, "A.svg");
    render_glyph_svg(B, "B.svg");
    render_glyph_svg(Y, "Y.svg");
    render_glyph_svg(V, "V.svg");
    render_glyph_svg(Heart, "heart.svg");
    return 0;
}
