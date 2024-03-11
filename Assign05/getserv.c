#include <stdio.h>
#include <netdb.h>

int main() {
    struct servent *serv;
    
    serv = getservbyname("http", "tcp");
    
    if (serv != NULL) {
        printf("Service name: %s\n", serv->s_name);
        printf("Port number: %d\n", ntohs(serv->s_port));
    } else {
        printf("Service not found.\n");
    }
    
    return 0;
}
