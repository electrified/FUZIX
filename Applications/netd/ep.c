/* 
   Echoping - A udp test client
   send some text to an udp echo server, waits for reply, prints it.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main( int argc, char *argv[] ){

    struct sockaddr_in addr;
    int fd;
    char buf[1024];
    int x;
    int port = 7;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <ip address> [port]\n", argv[0]);
        exit(1);
    }

    if (argc == 3)
    {
        port = atoi(argv[2]);
    }

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if( fd < 0 ){
        perror("socket()");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton( AF_INET, argv[1], &addr.sin_addr.s_addr );
    
    if( connect( fd, (struct sockaddr *) &addr, sizeof(addr)) < 0 ){
	perror("connect");
	exit(1);
    }

    printf("writing 1\n");
    write( fd, "This is a test!", 16 ); 
    sleep(1);
    printf("writing 2\n");
    write( fd, "This is a test!", 16 );

    printf("reading\n");
    x=read( fd, buf, 1024 );
    printf("read %d: >%s<\n", x, buf );

    exit(0);
}
