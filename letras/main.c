#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system("clear") ou "cls"

// ==================== IMAGENS E ANIMAÇÕES ====================
void printHeart() {
    printf("  **   **  \n");
    printf(" **** **** \n");
    printf("***********\n");
    printf(" ********* \n");
    printf("  *******  \n");
    printf("   *****   \n");
    printf("    ***    \n");
    printf("     *     \n");
}

void animateFace() {
    const char *frames[] = {
        "  (^_^)  \n",
        "  (o_o)  \n",
        "  (-_-)  \n"
    };
    for(int i = 0; i < 10; i++) {
        #ifdef _WIN32
            system("cls");
        #else
            printf("\033[H\033[J");
        #endif
        printf("%s", frames[i % 3]);
        fflush(stdout);
        sleep(1);
    }
}

// Caveira simples em ASCII
void printSkullFrame1() {
    printf("   _____   \n");
    printf("  /     \\  \n");
    printf(" | () () | \n");
    printf("  \\  ^  /  \n");
    printf("   |||||   \n");
    printf("   |||||   \n");
}

void printSkullFrame2() {
    printf("   _____   \n");
    printf("  /     \\  \n");
    printf(" | (O O) | \n");
    printf("  \\  v  /  \n");
    printf("   |||||   \n");
    printf("   |||||   \n");
}

void animateSkull() {
    for(int i = 0; i < 10; i++) {
        #ifdef _WIN32
            system("cls");
        #else
            printf("\033[H\033[J");
        #endif
        if(i % 2 == 0) printSkullFrame1();
        else printSkullFrame2();
        fflush(stdout);
        sleep(1);
    }
}

// ==================== LETRAS ESTILIZADAS ====================
void print_A() {
    printf("  A  \n");
    printf(" A A \n");
    printf("AAAAA\n");
    printf("A   A\n");
    printf("A   A\n");
}

void print_B() {
    printf("BBBB \n");
    printf("B   B\n");
    printf("BBBB \n");
    printf("B   B\n");
    printf("BBBB \n");
}

void print_0() {
    printf(" 000 \n");
    printf("0   0\n");
    printf("0   0\n");
    printf("0   0\n");
    printf(" 000 \n");
}

// ==================== FUNÇÃO PRINCIPAL ====================
int main() {
    printf("=== Letras Estilizadas ===\n");
    print_A();
    print_B();
    print_0();

    printf("\n=== Imagem Estática ===\n");
    printHeart();

    printf("\n=== Animação Carinha ===\n");
    animateFace();

    printf("\n=== Animação Caveira ===\n");
    animateSkull();

    return 0;
}
