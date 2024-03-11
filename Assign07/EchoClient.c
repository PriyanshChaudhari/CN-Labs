#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_MSG_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_MSG_SIZE] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    while (1) {
        memset(buffer, 0, sizeof(buffer));
    printf("Enter message: ");
    fgets(buffer, MAX_MSG_SIZE, stdin);
    printf("sent: %s\n", buffer);
    
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, MAX_MSG_SIZE);
    printf("Server: %s\n", buffer);
}

    return 0;
}
