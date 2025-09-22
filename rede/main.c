/*
#include <stdio.h>
//#include <sys/socket.h> // Required header for socket()
#include <unistd.h>       // For close()
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

int main()
{
    int socket_fd;

    // Create a TCP socket for IPv4
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd == -1)
    {
      perror("Error creating socket");
      return 1;
    }

    // Socket created successfully
    printf("Socket created with file descriptor: %d\n", socket_fd);

    // Close the socket when no longer needed
    close(socket_fd);

    return 0;
}
*/

//=================================================================================
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    SOCKET socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd == INVALID_SOCKET) {
        printf("Error creating socket: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    printf("Socket created with descriptor: %llu\n", (unsigned long long)socket_fd);

    // Close socket
    closesocket(socket_fd);
    WSACleanup();

    return 0;
}


// ============================================================

/*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    // Windows
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef SOCKET socket_t;
    #define CLOSE_SOCKET(s) closesocket(s)
    #define GET_ERROR() WSAGetLastError()
#else
    // Linux / Unix
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    typedef int socket_t;
    #define CLOSE_SOCKET(s) close(s)
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define GET_ERROR() errno
#endif

int main() {
    socket_t sockfd;

#ifdef _WIN32
    // Inicializa Winsock no Windows
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }
#endif

    // Criação do socket TCP IPv4
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Error creating socket: %d\n", GET_ERROR());
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    printf("Socket created successfully!\n");

    // Configurando endereço do servidor (localhost:8080)
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Tentando conectar
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        printf("Connect failed: %d\n", GET_ERROR());
        CLOSE_SOCKET(sockfd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    printf("Connected to server!\n");

    // Fecha o socket
    CLOSE_SOCKET(sockfd);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}

***************************************************************/
// continauar estudano a criação de sockets
