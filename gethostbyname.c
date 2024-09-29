#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv) {
    struct hostent *host_info;
    struct in_addr **address_list;

    if (argc != 2) {
        printf("To start, enter: client server_name\n");
        exit(-1);
    }
    
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Error: unable to find host\n");
        return 1;
    }

    address_list = (struct in_addr **) host_info->h_addr_list;

    printf("IP-address for %s: %s\n", argv[1], inet_ntoa(*address_list[0]));

    return 0;
}

