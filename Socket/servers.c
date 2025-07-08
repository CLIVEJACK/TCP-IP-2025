#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define PORT 9090
#define BUF_SIZE 2048

void error_handling(const char *message);
void send_image(int sock, const char *filename);
void send_html(int sock);

int main() {
    int serv_sock, clnt_sock;
    char request[BUF_SIZE];

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

        memset(request, 0, BUF_SIZE);
        read(clnt_sock, request, BUF_SIZE - 1);
        printf("Request:\n%s\n", request);

        if (strncmp(request, "GET /game.jpg", 13) == 0 || strncmp(request, "GET /game.png", 13) == 0) {
            const char *filename = strstr(request, ".png") ? "game.png" : "game.jpg";
            send_image(clnt_sock, filename);
        } else {
            send_html(clnt_sock);
        }

        close(clnt_sock);
    }

    close(serv_sock);
    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

void send_html(int sock) {
    char response[] =
        "HTTP/1.1 200 OK\r\n"
        "Server: Linux Web Server\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n\r\n"
        "<!DOCTYPE html>\r\n"
        "<html><head><title>My Web Page</title>\r\n"
        "<style>body { background-color: #FFFF00; }</style></head>\r\n"
        "<body><center><h1>Hello world!!</h1><br>\r\n"
        "<img src=\"game.jpg\"></center></body></html>\r\n";
    write(sock, response, strlen(response));
}

void send_image(int sock, const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        char not_found[] = "HTTP/1.1 404 Not Found\r\n\r\nFile Not Found";
        write(sock, not_found, strlen(not_found));
        return;
    }
    
    const char *content_type = strstr(filename, ".png") ? "image/png" : "image/jpeg";

    char header[BUF_SIZE];
    snprintf(header, sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: ", content_type);

    off_t filesize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    char size_str[64];
    sprintf(size_str, "%ld\r\n\r\n", filesize);
    strcat(header, size_str);

    write(sock, header, strlen(header));
    
    char buf[BUF_SIZE];
    int read_cnt;
    while ((read_cnt = read(fd, buf, BUF_SIZE)) > 0) {
        write(sock, buf, read_cnt);
    }

    close(fd);
}
