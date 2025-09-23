#include <stdio.h>

int main(int argc, char *argv[]) {
    // 1. Verifique se o n�mero de argumentos est� correto
    // Queremos apenas o nome do programa e a URL, ou seja, 2 argumentos.
    if (argc != 2) {
        printf("Uso: %s <https://google.com>\n", argv[0]);
        // Sa�mos com um c�digo de erro para indicar que algo deu errado
        return 1;
    }

    // 2. Acesse o argumento da URL
    // A URL estar� na posi��o 1 do array argv.
    char *url = argv[1];

    printf("Voc� solicitou a URL: %s\n", url);

    // Continue o c�digo aqui para fazer a requisi��o HTTP...

    return 0; // Sa�mos com sucesso
}
