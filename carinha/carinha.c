#include <stdio.h>
#include <unistd.h>
#include "carinha.h"

void animFace() {
 const char *frames[] = {
 "  (^_^)  \n",
 "  (o_o)  \n",
 "  (-_-)  \n",
 "  (#_0)  \n"
 };

 for(int i = 0; i < 10; i++) {  // 10 ciclos
 printf("\033[H\033[J"); // limpa tela
 printf("%s", frames[i % 4]);
 fflush(stdout);
 sleep(1);  // pausa 1s
 }
}
