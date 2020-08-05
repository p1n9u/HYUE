#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define DEFAULT_PROTOCOL 0
#define MAXLINE 100

int read_line(int fd, char *str);

int main(int argc, char* argv[]) {
    int fd, sfd, port, result, size;
    struct sockaddr_in server_addr;
    struct hostent *hp;
    char *f, *haddrp, *host, inmsg[MAXLINE], outmsg[MAXLINE];

    if ( argc != 3 ) {
        fprintf(stderr, "usage : %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    sfd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    do {
        result = connect(sfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
        if ( result == -1 ) {
            sleep(1);
        }
    } while ( result == -1 );

    printf("input filename to download : ");
    scanf("%s", inmsg);
    send(sfd, inmsg, MAXLINE, 0);
    recv(sfd, &size, sizeof(int), 0);
    if ( !size ) {
        printf("No Such File\n");
        exit(1);
    }
    f = (char *)malloc(sizeof(size));
    recv(sfd, f, size, 0);
    fd = open(inmsg, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if ( write(fd, f, size) == 0 ) {
        printf("done\n");
    }
    close(fd);
    close(sfd);
    exit(0);
}

int read_line(int fd, char *str) {
    int n;
    do {
        n = read(fd, str, 1);
    } while ( n > 0 && *str++ != '\0' );
    return ( n > 0 );
}