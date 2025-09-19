/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char *hello = "Hello client";

    // Criar socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Escutar
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor esperando conexão...\n");

    int addrlen = sizeof(address);
    client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (client_fd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    read(client_fd, buffer, 1024);
    printf("Mensagem recebida: %s\n", buffer);
    send(client_fd, hello, strlen(hello), 0);

    close(client_fd);
    close(server_fd);
    return 0;
}
 */

// ==========================================

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char *message;
    char buffer[2000];
    int recv_size;

    // Inicia Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Falha WSAStartup. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    // Cria socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Falha na criação do socket. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Conecta
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Erro ao conectar");
        return 1;
    }

    puts("Conectado!");

    // Envia requisição HTTP
    message = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    send(sock, message, strlen(message), 0);

    // Recebe resposta
    while ((recv_size = recv(sock, buffer, 2000, 0)) > 0) {
        buffer[recv_size] = '\0';
        printf("%s", buffer);
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}
*/

// ========================================

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    int c;
    char *message;

    printf("Inicializando Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Falha. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Não foi possível criar socket: %d\n", WSAGetLastError());
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    if(bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Erro no bind: %d\n", WSAGetLastError());
        return 1;
    }

    listen(s, 3);

    printf("Esperando conexões na porta 8080...\n");

    c = sizeof(struct sockaddr_in);
    new_socket = accept(s, (struct sockaddr *)&client, &c);
    if(new_socket == INVALID_SOCKET) {
        printf("Erro no accept: %d\n", WSAGetLastError());
        return 1;
    }

    message = "Conexão estabelecida com sucesso!\n";
    send(new_socket, message, strlen(message), 0);

    closesocket(s);
    WSACleanup();

    return 0;
}
*/

// ================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    int c;
    char *message;

    printf("Inicializando Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Falha. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Não foi possível criar socket: %d\n", WSAGetLastError());
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    if(bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Erro no bind: %d\n", WSAGetLastError());
        return 1;
    }

    listen(s, 3);

    printf("Servidor esperando conexões na porta 8080...\n");

    c = sizeof(struct sockaddr_in);
    while(1) {
        new_socket = accept(s, (struct sockaddr *)&client, &c);
        if(new_socket == INVALID_SOCKET) {
            printf("Erro no accept: %d\n", WSAGetLastError());
            return 1;
        }

        printf("Cliente conectado!\n");
        message = "Conexão estabelecida com sucesso!\n";
        send(new_socket, message, strlen(message), 0);

        closesocket(new_socket); // fecha só a conexão do cliente, mas o servidor continua rodando
    }

    closesocket(s);
    WSACleanup();

    return 0;
}
