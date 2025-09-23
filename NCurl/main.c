#include <stdio.h>

int main(int argc, char *argv[]) {
    // 1. Verifique se o número de argumentos está correto
    // Queremos apenas o nome do programa e a URL, ou seja, 2 argumentos.
    if (argc != 2) {
        printf("Uso: %s <https://google.com>\n", argv[0]);
        // Saímos com um código de erro para indicar que algo deu errado
        return 1;
    }

    // 2. Acesse o argumento da URL
    // A URL estará na posição 1 do array argv.
    char *url = argv[1];

    printf("Você solicitou a URL: %s\n", url);

    // Continue o código aqui para fazer a requisição HTTP...

    return 0; // Saímos com sucesso
}
