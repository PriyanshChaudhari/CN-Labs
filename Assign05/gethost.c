#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    struct hostent *host;

    host = gethostbyname("www.google.com");

    if (host != NULL) {
        printf("Official name: %s\n", host->h_name);
        printf("IP Address: %s\n", inet_ntoa(*((struct in_addr *)host->h_addr)));
    } else {
        printf("Host not found.\n");
    }

    return 0;
}
