#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9090
#define BUF_SIZE 1024

void error_handling(const char *message);

int main() {
    int serv_sock, clnt_sock;
    char request[BUF_SIZE];
    char webpagel[] =
        "HTTP/1.1 200 OK\r\n"
        "Server: Linux Web Server\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n\r\n"
        "<!DOCTYPE html>\r\n"
        "<html><head><title>My Web Page</title>\r\n"
        "<style>body { background-color: #FFFF00; }</style></head>\r\n"
        "<body><center><h1>Hello world!!</h1><br>\r\n"
        "<img src=\"game.jpg\"></center></body></html>\r\n";

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(PORT);

    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    printf("Server is running on http:127.0.0.1:%d\n", PORT);

    while (1) {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        if (clnt_sock == -1)
            continue;

        read(clnt_sock, request, BUF_SIZE - 1);
        printf("Request:\n%s\n", request); // 요청 로그 확인용

        write(clnt_sock, webpagel, sizeof(webpagel) - 1);
        close(clnt_sock);
    }

    close(serv_sock);
    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}
